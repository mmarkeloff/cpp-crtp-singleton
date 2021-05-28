/**
 * @file crtp_st.cpp
 * @authors Max Markeloff (https://github.com/mmarkeloff)
 */

 // MIT License
//
// Copyright (c) 2021 Max
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

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