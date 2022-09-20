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
 * @file ecl_database.hpp
 * @author Lee8950 (github.com/Lee8950)
 * @brief This file is part of ecl files.
 * @version 0.1
 * @date 2022-09-20
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef __ECL_DATABASE_HPP__
#define __ECL_DATABASE_HPP__

#include <vector>
#include <string>
#include <fstream>

namespace ecl
{

	/*@brief
	While using the ecl_Database,write your own struct to storage the data.
	*/
	class ecl_Database
	{
	private:
		std::string Data;
		std::string DB_Address;
		std::ifstream DB_Input;
		std::ofstream DB_Output;

		std::vector<std::vector<std::string>> Container;

		int DataPerLine;
		int WritingModifier;

	public:
		ecl_Database()
		{
			this->DataPerLine = 0;
			this->WritingModifier = -1;
		}

		void SetFormat(int SetDataPerLine)
		{
			this->DataPerLine = SetDataPerLine;
		}

		void SetAddress(std::string Address)
		{
			this->DB_Address = Address;
		}

		void ReadDatabase()
		{
			this->DB_Input.open(this->DB_Address);
			std::vector<std::string> Temp;
			while (!(this->DB_Input.eof()))
			{
				this->Container.push_back(Temp);
				for (int i = 0; i < this->DataPerLine; i++)
				{
					this->DB_Input >> this->Data;
					Container.back().push_back(this->Data);
				}
			}
			this->DB_Input.close();
		}

		std::vector<std::vector<std::string>> GetStoragedData()
		{
			return this->Container;
		}

		void WriteInMem(std::string Data)
		{
			std::vector<std::string> Temp;
			if (this->WritingModifier == -1)
			{
				this->Container.push_back(Temp);
				WritingModifier++;
			}
			if (this->WritingModifier >= this->DataPerLine)
			{
				WritingModifier = 0;
				this->Container.push_back(Temp);
			}
			Container.back().push_back(Data);
			WritingModifier++;
		}

		void OutputToFile()
		{
			this->DB_Output.open(this->DB_Address);
			for (unsigned int i = 0; i < this->Container.size(); i++)
			{
				for (unsigned int j = 0; j < this->Container[i].size(); j++)
				{
					this->DB_Output << (this->Container[i])[j] << '\t';
				}
				this->DB_Output << '\n';
			}
			this->DB_Output.close();
		}
	};

}

#endif
