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
 * @file ecl_complex.hpp
 * @author Lee8950 (github.com/Lee8950)
 * @brief This file is part of ecl files.
 * @version 0.1
 * @date 2022-09-20
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef __ECL_COMPLEX_HPP__
#define __ECL_COMPLEX_HPP__
namespace ecl
{

	class Real
	{
	private:
		double _____realPart;

	public:
		Real() { this->_____realPart = 0; }
		Real(double __operateNumber) { this->_____realPart = __operateNumber; }
		double getReal() { return _____realPart; }
		void setReal(double __operateNumber) { _____realPart = __operateNumber; }
	};

	class Imaginary
	{
	private:
		double _____imaginaryPart;

	public:
		Imaginary() { this->_____imaginaryPart = 0; }
		Imaginary(double __operateNumber) { this->_____imaginaryPart = __operateNumber; }
		double getImaginary() { return this->_____imaginaryPart; }
		void setImaginary(double __operateNumber) { this->_____imaginaryPart = __operateNumber; }
	};

	class Complex
	{
	private:
		Real a;
		Imaginary b;

	public:
		double getReal() { return this->a.getReal(); }

		double getImaginary() { return this->b.getImaginary(); }

		void setReal(int __operateNumber) { this->a.setReal(__operateNumber); }

		void setImaginary(int __operateNumber) { this->b.setImaginary(__operateNumber); }

		Complex operator*(ComplexNumber __operateNumber)
		{
			ComplexNumber temp;
			temp.setReal(this->a.getReal() * __operateNumber.getReal() - (this->b.getImaginary() * __operateNumber.getImaginary()));
			temp.setImaginary(this->a.getReal() * __operateNumber.getImaginary() + (this->b.getImaginary() * __operateNumber.getReal()));
			return temp;
		}

		Complex operator+(ComplexNumber __operateNumber)
		{
			ComplexNumber temp;
			temp.setReal(this->a.getReal() + __operateNumber.getReal());
			temp.setImaginary(this->b.getImaginary() + __operateNumber.getImaginary());
			return temp;
		}

		Complex(int __realNumber)
		{
			this->a.setReal(__realNumber);
		}

		Complex()
		{
			this->a.setReal(0);
			this->b.setImaginary(0);
		}
	};

}
#endif
