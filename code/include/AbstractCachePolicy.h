/*
 * AbstractCache.h
 *
 *  Created on: Nov 25, 2018
 *      Author: long
 */

#ifndef CODE_INCLUDE_ABSTRACTCACHEPOLICY_H_
#define CODE_INCLUDE_ABSTRACTCACHEPOLICY_H_

#include "BaseMacro.h"

CACHE_NS_BEGIN

template<typename Key>
struct AbstractCachePolicy
{
public:
    virtual ~AbstractCachePolicy() {}
 // handle element insertion in a cache
    virtual void put(const Key &key) = 0;
    // handle request to the key-element in a cache
    virtual void hit(const Key &key) = 0;
    // handle element deletion from a cache
    virtual void deleteKey(const Key &key) = 0;

    // return a key of a replacement candidate
    virtual const Key &replCandidate() const = 0;

};

CACHE_NS_END

#endif /* CODE_INCLUDE_ABSTRACTCACHEPOLICY_H_ */
