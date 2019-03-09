#ifndef __ECL_DATE_HPP__
#define __ECL_DATE_HPP__

#include<ctime>

namespace ecl
{
	
	class ecl_Date{
		
		private:
			
			/*
			* A TM-structrue is used to get the time
			*/
			time_t __WHEEL_TIME__;
			
			/*
			* Version for getTm()
			*/
			tm __WHEEL_DATE_GET_TM__()
			{ timeUpdate();
				return *localtime(&this->__WHEEL_TIME__);}
			
		public:
			
			/*
			* Constructor
			*/
			ecl_Date():__WHEEL_TIME__(0){}
			
			/*
			* Destructor
			*/
			virtual ~ecl_Date(){};
			
			/*
			* timeUpdate() will call time() to update
			* itself
			*/
			inline time_t timeUpdate()
			{	return time(&this->__WHEEL_TIME__); }
			
			/*
			* getTime(default=false) if the is true it will update
			* its own storaged-time.
			*/
			inline time_t getTime(bool isUpdate=false)
			{ return isUpdate ? this->timeUpdate() : this->__WHEEL_TIME__; }
			
			/*
			* just get tm structure
			*/
			inline tm getTm(bool isUpdate=false)
			{ return isUpdate ? this->__WHEEL_DATE_GET_TM__() :
				 *localtime(&this->__WHEEL_TIME__); }
			
			/*
			* set a timer
			*/
			void setTimer(int ST__Year,int ST__Month,int ST__Date,int ST__HRS)
			{ while(1){
				if(this->getTm(true).tm_year+1900>=ST__Year&&this->getTm().tm_mon+1>=ST__Month
					&&this->getTm().tm_mday>=ST__Date&&this->getTm().tm_hour>=ST__HRS)return;	
				}}
			
			/*TODO: A member function which can convert tm to 
			* string
			*/
};

}
#endif
