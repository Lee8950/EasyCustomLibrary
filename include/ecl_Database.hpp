#ifndef __ECL_DATABASE_HPP__
#define __ECL_DATABASE_HPP__

#include <vector>
#include <string>
#include <fstream>

namespace ecl {

	/*@brief
	While using the ecl_Database,write your own struct to storage the data.
	*/
	class ecl_Database {
	private:

		std::string Data;
		std::string DB_Address;
		std::ifstream DB_Input;
		std::ofstream DB_Output;

		std::vector<std::vector<std::string>> Container;

		int DataPerLine;
		int WritingModifier;

	public:
		
		ecl_Database() {
			this->DataPerLine = 0;
			this->WritingModifier = -1;
		}

		void SetFormat(int SetDataPerLine) {
			this->DataPerLine = SetDataPerLine;
		}

		void SetAddress(std::string Address) {
			this->DB_Address = Address;
		}

		void ReadDatabase() {
			this->DB_Input.open(this->DB_Address);
			std::vector<std::string> Temp;
			while (!(this->DB_Input.eof())) {
				this->Container.push_back(Temp);
				for (int i = 0; i < this->DataPerLine; i++) {
					this->DB_Input >> this->Data;
					Container.back().push_back(this->Data);
				}
			}
			this->DB_Input.close();
		}

		std::vector<std::vector<std::string>> GetStoragedData() {
			return this->Container;
		}

		void WriteInMem(std::string Data) {
			std::vector<std::string> Temp;
			if (this->WritingModifier == -1) {
				this->Container.push_back(Temp);
				WritingModifier++;
			}
			if (this->WritingModifier >= this->DataPerLine) {
				WritingModifier = 0;
				this->Container.push_back(Temp);
			}
			Container.back().push_back(Data);
			WritingModifier++;
		}

		void OutputToFile() {
			this->DB_Output.open(this->DB_Address);
			for (unsigned int i = 0; i < this->Container.size(); i++) {
				for (unsigned int j = 0; j < this->Container[i].size(); j++) {
					this->DB_Output << (this->Container[i])[j] << '\t';
				}
				this->DB_Output << '\n';
			}
			this->DB_Output.close();
		}

	};

}

#endif
