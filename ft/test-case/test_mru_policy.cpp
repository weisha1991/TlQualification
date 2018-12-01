#include "BaseMacro.h"
#include "ConcreteCachePolicy.h"
#include <gtest/gtest.h>
#include <FtMacro.h>

DEFINE_FT_FIXTURE(MruTest)

USING_CACHE_NS

TEST_F(MruTest, should_normal_get_operation_correct)
{
    mru_cache_t<std::string, int> cache(1);

    cache.put("test", 666);

    EXPECT_EQ(cache.get("test"), 666);
}

TEST_F(MruTest, shold_get_key_none_when_cache_is_empty)
{
    mru_cache_t<std::string, int> cache(1);

    EXPECT_THROW(cache.get("test"), std::range_error);
}

TEST_F(MruTest, shold_get_key_none_when_key_missing)
{
    mru_cache_t<std::string, int> cache(1);

    cache.put("test", 1);
    EXPECT_THROW(cache.get("fun"), std::range_error);
}

TEST_F(MruTest, should_least_recently_access_delete_when_capacity_overflow)
{
    mru_cache_t<std::string, int> cache(2);

    cache.put("test", 1);
    cache.put("lucky", 2);
    EXPECT_EQ(cache.get("test"), 1);
    cache.put("fun", 3);
    EXPECT_THROW(cache.get("test"), std::range_error);
}

TEST_F(MruTest, KeepsAllValuesWithinCapacity)
{
    constexpr int CACHE_CAP = 50;
    const int TEST_RECORDS = 100;
    mru_cache_t<int, int> cache(CACHE_CAP);

    for (int i = 0; i < TEST_RECORDS; ++i)
    {
        cache.put(i, i);
    }

    for (int i = 0; i < 49; ++i)
    {
        EXPECT_EQ(i, cache.get(i));
    }

    for (int i = 49; i < TEST_RECORDS -1 ; ++i)
    {
        EXPECT_THROW(cache.get(i), std::range_error);
    }

    EXPECT_EQ(99, cache.get(99));
}
