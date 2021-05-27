/**
 * @file crtp_st.cpp
 * @authors Max Markeloff (https://github.com/mmarkeloff)
 */

#include <gtest/gtest.h>

#include "crtp_st.hpp"

using namespace crtp_st;

////////////////////////////////////////////////////////////////////////////
///
//
class TestCRTPSingleton : public ::testing::Test {
protected:
    void SetUp() { }

    void TearDown() { }
};

////////////////////////////////////////////////////////////////////////////
///
//
class Derived : public Base<Derived> {
private:
    uint32_t m_Data;
public:
    Derived() : m_Data{0} {}

    void setData(uint32_t data) noexcept { m_Data = data; }

    uint32_t getData() const noexcept { return m_Data; }
};

////////////////////////////////////////////////////////////////////////////
///
//
TEST_F(TestCRTPSingleton, basicUsage) {
    ASSERT_EQ(0, Derived::instance().getData());

    Derived::instance().setData(1);
    
    ASSERT_EQ(1, Derived::instance().getData());

    Derived::instance().setData(0);

    ASSERT_EQ(0, Derived::instance().getData());
}

#include <thread>
#include <chrono>
#include <vector>

TEST_F(TestCRTPSingleton, threadSafeSupport) {
    auto f = []() {
        Derived::instance().setData(1);
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    };

    std::vector<std::thread> threads;
    for (std::size_t i = 0; i < 16; i++)
        threads.push_back(std::thread{f});

    for (auto& thread : threads) 
        thread.join();
}