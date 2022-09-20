// BSD 3-Clause License
//
// Copyright (c) 2022, Lee8950
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice, this
//    list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its
//    contributors may be used to endorse or promote products derived from
//    this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

/**
 * @file ecl_stack.hpp
 * @author Lee8950 (github.com/Lee8950)
 * @brief This file is part of ecl files.
 * @version 0.1
 * @date 2022-09-20
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <exception>
#include <stdint.h>
#include <string.h>

namespace ecl
{

    /**
     * @brief ecl Exception type.
     */
    class StackError : public std::exception
    {
    public:
        StackError(int type = 0) : ExceptionType(type) {}
        virtual const char *what() const throw()
        {
            switch (ExceptionType)
            {
            case 1:
                return "Inquiring an empty stack, throwing exception.";
            case 2:
                return "Popping an empty stack, throwing exception.";
            default:
                return "";
            }
        }

    private:
        int ExceptionType;
    };

    /**
     * @brief Custom stack template. Only minimum functions available.
     */
    template <typename T>
    class Stack
    {

#ifndef ECL_STACK_MODE_CHAIN
    private:
        T *STACK_BASIS__;
        int32_t STACK_SIZE__;
        int32_t STACK_TOP_POINTER__;

    public:
        /**
         * @brief Default constructor. Initially distribute 4096 size.
         */
        Stack(int32_t size = 4096)
        {
            STACK_SIZE__ = size;
            STACK_TOP_POINTER__ = -1;
            STACK_BASIS__ = new T[STACK_SIZE__];
        }

        /**
         * @brief Destroy the Stack object.
         */
        ~Stack()
        {
            delete[] STACK_BASIS__;
        }

        /**
         * @brief Operator=.
         */
        Stack<T> operator=(const Stack<T> &obj)
        {
            if (this == &obj)
                return *this;
            delete[] STACK_BASIS__;
            STACK_BASIS__ = new T[obj.STACK_SIZE];
            memcpy_s(STACK_BASIS__, obj.STACK_SIZE__, obj.STACK_BASIS__, obj.STACK_SIZE__);
            STACK_SIZE__ = obj.STACK_SIZE__;
            STACK_TOP_POINTER__ = obj.STACK_TOP_POINTER__;
            return *this;
        }

        /**
         * @brief push(), core function.
         */
        void push(T data)
        {
            if (!isFull())
                STACK_BASIS__[++STACK_TOP_POINTER__] = data;
            else
            {
                std::cout << "Space expanded at " << STACK_TOP_POINTER__ << std::endl;
                /**
                 * @brief Dynamically expand space if there's no space available.
                 */
                T *tmp;
                tmp = new T[STACK_SIZE__ * 2];
                STACK_SIZE__ = STACK_SIZE__ * 2;
                memcpy_s(tmp, STACK_SIZE__, STACK_BASIS__, STACK_SIZE__ / 2);
                delete[] STACK_BASIS__;
                STACK_BASIS__ = tmp;
                STACK_BASIS__[++STACK_TOP_POINTER__] = data;
            }
        }

        /**
         * @brief pop(), core function.
         */
        T pop()
        {
            if (isEmpty())
                throw ecl::StackError(2);
            return STACK_BASIS__[STACK_TOP_POINTER__--];
        }

        /**
         * @brief top(), core function.
         */
        T top()
        {
            if (STACK_TOP_POINTER__ == -1)
                throw ecl::StackError(1);
            return STACK_BASIS__[STACK_TOP_POINTER__];
        }

        /**
         * @brief isFull() returns a boolean to tell if it's full.
         */
        bool isFull()
        {
            return !static_cast<bool>(STACK_TOP_POINTER__ + 1 < STACK_SIZE__);
        }
        /**
         * @brief isEmpty() returns a boolean to tell if it's full.
         */
        bool isEmpty()
        {
            return !static_cast<bool>(STACK_TOP_POINTER__ + 1);
        }

#ifdef ECL_DEBUG_MODE
        auto Debug();
#endif

#else
    private:
    public:
#endif
    };
}