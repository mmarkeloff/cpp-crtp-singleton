/**
 * @file crtp_st.hpp
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

#ifndef __CPP_CRTP_SINGLETON_CRTP_ST_HPP
#define __CPP_CRTP_SINGLETON_CRTP_ST_HPP

/**
 * Lib space
 */
namespace crtp_st {
    /**
     * Singleton CRTP implementation
     * 
     * @example main.cpp
     */
    template<class Derived>
    class Base {
    protected:
        /**
         * Ctor by default
         */
        Base() = default;
    public:
        /**
         * Dtor by default
         */
        virtual ~Base() = default;

        /**
         * Deleted copy ctor
         */
        Base(const Base&) = delete;

        /**
         * Deleted copy assigment operator
         */
        Base& operator=(const Base&) = delete;

        /**
         * Deleted move ctor
         */
        Base(Base&&) = delete;

        /**
         * Deleted move assigment operator
         */
        Base& operator=(Base&&) = delete;

        /**
         * Get class instance
         * 
         * @return class instance from static global scope
         */
        static Derived& instance() {
            static Derived instance;
            return instance;
        }
    };
};

#endif // __CPP_CRTP_SINGLETON_CRTP_ST_HPP