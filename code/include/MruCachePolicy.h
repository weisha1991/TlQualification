/*
 * MruCachePolicy.h
 *
 *  Created on: Nov 25, 2018
 *      Author: long
 */

#ifndef CODE_INCLUDE_MRUCACHEPOLICY_H_
#define CODE_INCLUDE_MRUCACHEPOLICY_H_

#include <BaseMacro.h>
#include <AbstractCachePolicy.h>
#include <list>
#include <unordered_map>

CACHE_NS_BEGIN

template<typename Key>
struct MruCachePolicy : AbstractCachePolicy<Key>
{
    using mru_iterator = typename std::list<Key>::iterator;

    MruCachePolicy() = default;
     ~MruCachePolicy() override = default;

     void put(const Key &key) override
     {
         mru_queue.emplace_front(key);
         key_finder[key] = mru_queue.begin();
     }

     void hit(const Key &key) override
     {
         mru_queue.splice(mru_queue.begin(), mru_queue, key_finder[key]);
     }

     void deleteKey(const Key &key) override
     {
         key_finder.erase(mru_queue.front());
         mru_queue.pop_front();
     }

     // return a key of a displacement candidate
     const Key &replCandidate() const override
     {
         return mru_queue.front();
     }

 private:
   std::list<Key> mru_queue;
   std::unordered_map<Key, mru_iterator> key_finder;
};
CACHE_NS_END

#endif /* CODE_INCLUDE_MRUCACHEPOLICY_H_ */
