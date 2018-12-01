/*
 * Cache.h
 *
 *  Created on: Nov 25, 2018
 *      Author: long
 */

#ifndef CODE_INCLUDE_CACHE_H_
#define CODE_INCLUDE_CACHE_H_

#include <cstddef>
#include <functional>
#include <limits>
#include <memory>
#include <mutex>
#include <unordered_map>
#include "BaseMacro.h"
#include "DefaultCachePolicy.h"

CACHE_NS_BEGIN

template <typename Key, typename Value, typename Policy = DefaultCachePolicy<Key>>
struct FixedSizeCache
{
public:
    using iterator = typename std::unordered_map<Key, Value>::iterator;
    using const_iterator = typename std::unordered_map<Key, Value>::const_iterator;
    using operation_guard = typename std::lock_guard<std::mutex>;
    using Callback = typename std::function<void(const Key &key, const Value &value)>;

    FixedSizeCache(size_t max_size, const Policy &policy = Policy(),
                    Callback OnErase = [](const Key &, const Value &) {})
      : cache_policy(policy), max_cache_size(max_size),
        OnEraseCallback(OnErase)
    {
      if (max_cache_size == 0)
      {
          max_cache_size = std::numeric_limits<size_t>::max();
      }
    }

    ~FixedSizeCache()
    {
        clear();
    }

    void put(const Key &key, const Value &value)
    {
        operation_guard lock{safe_op};
        auto elem_it = findElem(key);

        if (elem_it == cache_items_map.end())
        {
            // add new element to the cache
            if (cache_items_map.size() + 1 > max_cache_size)
            {
                auto disp_candidate_key = cache_policy.replCandidate();

                erase(disp_candidate_key);
            }

            insert(key, value);
        }
        else
        {
            // update previous value
            update(key, value);
        }
    }

    Value get(const Key &key) const
    {
        operation_guard lock{safe_op};
        auto elem_it = findElem(key);

        if (elem_it == cache_items_map.end())
        {
            throw std::range_error{"No such element in the cache"};
        }

        cache_policy.hit(key);
        return elem_it->second;
    }

    bool cached(const Key &key) const
    {
        operation_guard lock{safe_op};
        return fnidElem(key) != cache_items_map.end();
    }

    size_t size() const
    {
        operation_guard lock{safe_op};

        return cache_items_map.size();
    }

    void clear()
    {
        operation_guard lock{safe_op};

        for (auto it = begin(); it != end(); ++it)
        {
            cache_policy.deleteKey(it->first);
            OnEraseCallback(it->first, it->second);
        }

        cache_items_map.clear();
    }

    typename std::unordered_map<Key, Value>::const_iterator begin() const
    {
        return cache_items_map.begin();
    }

    typename std::unordered_map<Key, Value>::const_iterator end() const
    {
        return cache_items_map.end();
    }

protected:
    void insert(const Key &key, const Value &value)
    {
        cache_policy.put(key);
        cache_items_map.emplace(std::make_pair(key, value));
    }

    void erase(const Key &key)
    {
        cache_policy.deleteKey(key);

        auto elem_it = findElem(key);
        OnEraseCallback(key, elem_it->second);
        cache_items_map.erase(elem_it);
    }

    void update(const Key &key, const Value &value)
    {
        cache_policy.hit(key);
        cache_items_map[key] = value;
    }

    const_iterator findElem(const Key &key) const
    {
        return cache_items_map.find(key);
    }

private:
    std::unordered_map<Key, Value> cache_items_map;
    mutable Policy cache_policy;
    mutable std::mutex safe_op;
    size_t max_cache_size;
    Callback OnEraseCallback;
};

CACHE_NS_END

#endif /* CODE_INCLUDE_CACHE_H_ */
