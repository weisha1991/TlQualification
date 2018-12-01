/*
 * ConcreteCachePolicy.h
 *
 *  Created on: Nov 25, 2018
 *      Author: long
 */

#ifndef CODE_INCLUDE_CONCRETECACHEPOLICY_H_
#define CODE_INCLUDE_CONCRETECACHEPOLICY_H_

#include <BaseMacro.h>
#include <Cache.h>
#include <LfuCachePolicy.h>
#include <MruCachePolicy.h>
#include <LruCachePolicy.h>

CACHE_NS_BEGIN

template <typename Key, typename Value>
using lru_cache_t =
    typename CACHE_NS::FixedSizeCache<Key, Value, CACHE_NS::LruCachePolicy<Key>>;


template <typename Key, typename Value>
using mru_cache_t =
        typename CACHE_NS::FixedSizeCache<Key, Value, CACHE_NS::MruCachePolicy<Key>>;


CACHE_NS_END

#endif /* CODE_INCLUDE_CONCRETECACHEPOLICY_H_ */
