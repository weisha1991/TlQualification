/*
 * LruCachePolicy.h
 *
 *  Created on: Nov 25, 2018
 *      Author: long
 */

#ifndef CODE_INCLUDE_LRUCACHEPOLICY_H_
#define CODE_INCLUDE_LRUCACHEPOLICY_H_

#include <list>
#include <unordered_map>
#include "AbstractCachePolicy.h"
#include "BaseMacro.h"

CACHE_NS_BEGIN

template<typename Key>
struct LruCachePolicy : AbstractCachePolicy<Key>
{
public:
    using lru_iterator = typename std::list<Key>::iterator;

    LruCachePolicy() = default;
    ~LruCachePolicy() override = default;

    void put(const Key &key) override
    {
        lru_queue.emplace_front(key);
        key_finder[key] = lru_queue.begin();
    }

    void hit(const Key &key) override
    {
        lru_queue.splice(lru_queue.begin(), lru_queue, key_finder[key]);
    }

    void deleteKey(const Key &key) override
    {
        key_finder.erase(lru_queue.back());
        lru_queue.pop_back();
    }

    // return a key of a displacement candidate
    const Key &replCandidate() const override
    {
        return lru_queue.back();
    }

private:
  std::list<Key> lru_queue;
  std::unordered_map<Key, lru_iterator> key_finder;
};
CACHE_NS_END

#endif /* CODE_INCLUDE_LRUCACHEPOLICY_H_ */
