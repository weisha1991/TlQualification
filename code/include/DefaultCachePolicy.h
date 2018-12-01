/*
 * DefaultCachePolicy.h
 *
 *  Created on: Nov 25, 2018
 *      Author: long
 */

#ifndef CODE_INCLUDE_DEFAULTCACHEPOLICY_H_
#define CODE_INCLUDE_DEFAULTCACHEPOLICY_H_

#include <unordered_set>
#include "AbstractCachePolicy.h"
#include "BaseMacro.h"

CACHE_NS_BEGIN

template<typename Key>
struct DefaultCachePolicy : AbstractCachePolicy<Key>
{
    DefaultCachePolicy() = default;
    ~DefaultCachePolicy() override = default;

    void put(const Key &key) override
    {
        key_storage.emplace(key);
    }

    void hit(const Key &key) override
    {
        // do not do anything
    }

    void deleteKey(const Key &key) override
    {
        key_storage.erase(key);
    }

    // return a key of a displacement candidate
    const Key &replCandidate() const override
    {
        return *key_storage.cbegin();
    }

  private:
    std::unordered_set<Key> key_storage;
};
CACHE_NS_END

#endif /* CODE_INCLUDE_DEFAULTCACHEPOLICY_H_ */
