#include "BaseMacro.h"
#include "ConcreteCachePolicy.h"
#include <gtest/gtest.h>
#include <FtMacro.h>

DEFINE_FT_FIXTURE(LruTest)

USING_CACHE_NS

TEST_F(LruTest, should_normal_get_operation_correct)
{
    lru_cache_t<std::string, int> cache(1);

    cache.put("test", 666);

    EXPECT_EQ(cache.get("test"), 666);
}

TEST_F(LruTest, shold_get_key_none_when_cache_is_empty)
{
    lru_cache_t<std::string, int> cache(1);

    EXPECT_THROW(cache.get("test"), std::range_error);
}

TEST_F(LruTest, shold_get_key_none_when_key_missing)
{
    lru_cache_t<std::string, int> cache(1);

    cache.put("test", 1);
    EXPECT_THROW(cache.get("fun"), std::range_error);
}

TEST_F(LruTest, should_least_recently_access_delete_when_capacity_overflow)
{
    lru_cache_t<std::string, int> cache(2);

    cache.put("test", 1);
    cache.put("lucky", 2);
    EXPECT_EQ(cache.get("test"), 1);
    cache.put("fun", 3);
    EXPECT_THROW(cache.get("lucky"), std::range_error);
}

TEST_F(LruTest, KeepsAllValuesWithinCapacity)
{
    constexpr int CACHE_CAP = 50;
    const int TEST_RECORDS = 100;
    lru_cache_t<int, int> cache(CACHE_CAP);

    for (int i = 0; i < TEST_RECORDS; ++i)
    {
        cache.put(i, i);
    }

    for (int i = 0; i < TEST_RECORDS - CACHE_CAP; ++i)
    {
        EXPECT_THROW(cache.get(i), std::range_error);
    }

    for (int i = TEST_RECORDS - CACHE_CAP; i < TEST_RECORDS; ++i)
    {
        EXPECT_EQ(i, cache.get(i));
    }
}
