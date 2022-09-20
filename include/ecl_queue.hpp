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
 * @file ecl_queue.hpp
 * @author Lee8950 (github.com/Lee8950)
 * @brief This file is part of ecl files.
 * @version 0.1
 * @date 2022-09-20
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef ECL_QUEUE_HPP
#define ECL_QUEUE_HPP

#include <exception>
#include <stdint.h>

namespace ecl
{

    /**
     * @brief ecl Exception type.
     */
    class QueueError : public std::exception
    {
    public:
        QueueError(int type = 0) : ExceptionType(type) {}
        virtual const char *what() const throw()
        {
            switch (ExceptionType)
            {
            case 1:
                return "Inquiring an empty queue, throwing exception.";
            case 2:
                return "Popping an empty queue, throwing exception.";
            default:
                return "";
            }
        }

    private:
        int ExceptionType;
    };

    /**
     * @brief Custom queue template. Only minimum functions available.
     */
    template <typename T>
    class Queue
    {

#ifndef ECL_QUEUE_MODE_ARRAY
    private:
        template <typename Type>
        struct node
        {
        public:
            Type data;
            node *prev;
            node *next;
        };

        node<T> *QUEUE_FRONT__;
        node<T> *QUEUE_BACK__;
        int32_t QUEUE_ELEMENTS__;

    public:
        /**
         * @brief Default constructor.
         */
        Queue()
        {
            QUEUE_FRONT__ = nullptr;
            QUEUE_BACK__ = nullptr;
            QUEUE_ELEMENTS__ = 0;
        }

        /**
         * @brief Destroy the Stack object.
         */
        ~Queue()
        {
            if (QUEUE_ELEMENTS__ != 0)
            {
                node<T> *tmp;
                for (auto i = QUEUE_FRONT__; i != nullptr;)
                {
                    tmp = i;
                    i = i->next;
                    delete tmp;
                }
            }
        }

        /**
         * @brief Operator=.
         */
        Queue<T> operator=(const Queue<T> &obj)
        {
            if (this == &obj)
                return *this;
            QUEUE_FRONT__ = nullptr;
            QUEUE_BACK__ = nullptr;
            QUEUE_ELEMENTS__ = 0;
            for (auto i = obj.QUEUE_FRONT__; i != nullptr; i = i->next)
            {
                push(i->data);
            }
            return *this;
        }

        /**
         * @brief push(), core function. Push an element into the queue.
         */
        void push(T data)
        {
            if (QUEUE_ELEMENTS__ != 0 && QUEUE_ELEMENTS__ != 1)
            {
                auto tmp = new ecl::Queue<T>::node<T>;
                QUEUE_BACK__->next = tmp;
                tmp->prev = QUEUE_BACK__;
                tmp->next = nullptr;
                tmp->data = data;
                QUEUE_BACK__ = QUEUE_BACK__->next;
            }
            else if (QUEUE_ELEMENTS__ == 1)
            {
                QUEUE_BACK__ = new ecl::Queue<T>::node<T>;
                QUEUE_BACK__->data = data;
                QUEUE_BACK__->next = nullptr;
                QUEUE_BACK__->prev = QUEUE_FRONT__;
                QUEUE_FRONT__->next = QUEUE_BACK__;
            }
            else
            {
                QUEUE_FRONT__ = new ecl::Queue<T>::node<T>;
                QUEUE_FRONT__->next = nullptr;
                QUEUE_FRONT__->prev = nullptr;
                QUEUE_BACK__ = QUEUE_FRONT__;
                QUEUE_FRONT__->data = data;
            }
            QUEUE_ELEMENTS__++;
        }

        /**
         * @brief pop(), core function. return the front element and pop it from the queue.
         * @return front element.
         */
        T pop()
        {
            if (QUEUE_ELEMENTS__ == 0)
                throw ecl::QueueError(2);
            else
            {
                T tmp = QUEUE_FRONT__->data;
                auto t_ptr = QUEUE_FRONT__->next;
                delete QUEUE_FRONT__;
                QUEUE_FRONT__ = t_ptr;
                if (QUEUE_FRONT__ != nullptr)
                    QUEUE_FRONT__->prev = nullptr;
                QUEUE_ELEMENTS__--;
                return tmp;
            }
        }

        /**
         * @brief front(), core function.
         * @return front element.
         */
        T front()
        {
            if (QUEUE_ELEMENTS__ == 0)
                throw ecl::QueueError(1);
            else
                return QUEUE_FRONT__->data;
        }

        /**
         * @brief isFull() returns a boolean to tell if it's full. However
         * by using a list we will never get the queue full unless we run out of ram.
         * Therefore the value of this function a constantly set to false.
         * @return boolean.
         */
        bool isFull()
        {
            return false;
        }
        /**
         * @brief isEmpty() returns a boolean to tell if it's full.
         * @return boolean.
         */
        bool isEmpty()
        {
            return !QUEUE_ELEMENTS__;
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
#endif