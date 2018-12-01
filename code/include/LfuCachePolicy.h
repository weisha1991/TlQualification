/*
 * LfuCachePolicy.h
 *
 *  Created on: Nov 25, 2018
 *      Author: long
 */

#ifndef CODE_INCLUDE_LFUCACHEPOLICY_H_
#define CODE_INCLUDE_LFUCACHEPOLICY_H_

#include <cstddef>
#include <iostream>
#include <map>
#include <unordered_map>
#include "AbstractCachePolicy.h"
#include "BaseMacro.h"

CACHE_NS_BEGIN

template<typename Key>
struct LfuCachePolicy : AbstractCachePolicy<Key>
{
public:
    using lfu_iterator = typename std::multimap<std::size_t, Key>::iterator;

    LfuCachePolicy() = default;
    ~LfuCachePolicy() override = default;

    void put(const Key &key) override
    {
        constexpr std::size_t INIT_VAL = 1;
        // all new value initialized with the frequency 1
        lfu_storage[key] = frequency_storage.emplace_hint(
            frequency_storage.cbegin(), INIT_VAL, key);
    }

    void hit(const Key &key) override
    {
        // get the previous frequency value of a key
        auto elem_for_update = lfu_storage[key];
        auto updated_elem =
            std::make_pair(elem_for_update->first + 1, elem_for_update->second);
        // update the previous value
        frequency_storage.erase(elem_for_update);
        lfu_storage[key] = frequency_storage.emplace_hint(
            frequency_storage.cend(), std::move(updated_elem));
    }

    void deleteKey(const Key &key) override
    {
        frequency_storage.erase(lfu_storage[key]);
        lfu_storage.erase(key);
    }

    const Key &ReplCandidate() const override
    {
        return frequency_storage.cbegin()->second;
    }

private:
  std::multimap<std::size_t, Key> frequency_storage;
  std::unordered_map<Key, lfu_iterator> lfu_storage;
};
CACHE_NS_END

#endif /* CODE_INCLUDE_LFUCACHEPOLICY_H_ */
