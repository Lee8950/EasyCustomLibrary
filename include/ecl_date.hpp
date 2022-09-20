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
 * @file ecl_date.hpp
 * @author Lee8950 (github.com/Lee8950)
 * @brief This file is part of ecl files.
 * @version 0.1
 * @date 2022-09-20
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef __ECL_DATE_HPP__
#define __ECL_DATE_HPP__

#include <time.h>

namespace ecl
{

	class ecl_Date
	{

	private:
		/**
		 * @brief A TM-structure is used to get the time
		 */
		time_t __WHEEL_TIME__;

		/**
		 * @brief Version for getTm()
		 */
		tm __WHEEL_DATE_GET_TM__()
		{
			timeUpdate();
			return *localtime(&this->__WHEEL_TIME__);
		}

	public:
		/**
		 * @brief Constructor
		 */
		ecl_Date() : __WHEEL_TIME__(0) {}

		/**
		 * @brief Destructor
		 */
		virtual ~ecl_Date(){};

		/**
		 * @brief timeUpdate() will call time() to update
		 * itself
		 */
		inline time_t timeUpdate()
		{
			return time(&this->__WHEEL_TIME__);
		}

		/**
		 * @brief getTime(default=false) if the is true it will update
		 * its own storaged-time.
		 */
		inline time_t getTime(bool isUpdate = false)
		{
			return isUpdate ? this->timeUpdate() : this->__WHEEL_TIME__;
		}

		/**
		 * @brief just get tm structure
		 */
		inline tm getTm(bool isUpdate = false)
		{
			return isUpdate ? this->__WHEEL_DATE_GET_TM__() : *localtime(&this->__WHEEL_TIME__);
		}

		/**
		 * @brief set a timer
		 */
		void setTimer(int ST__Year, int ST__Month, int ST__Date, int ST__HRS)
		{
			while (1)
			{
				if (this->getTm(true).tm_year + 1900 >= ST__Year && this->getTm().tm_mon + 1 >= ST__Month && this->getTm().tm_mday >= ST__Date && this->getTm().tm_hour >= ST__HRS)
					return;
			}
		}

		/** TODO: A member function which can convert tm to
		 * string
		 */
	};

}
#endif
