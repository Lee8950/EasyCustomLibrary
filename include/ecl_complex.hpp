#ifndef __ECL_COMPLEX_HPP__
#define __ECL_COMPLEX_HPP__
namespace ecl
{
	
	class Real{
	    private:
	        int _____realPart;
	    public:
	        Real(){this->_____realPart=0;}
	        Real(int __operateNumber){this->_____realPart=__operateNumber;}
	        int getReal(){return _____realPart;}
	        void setReal(int __operateNumber){_____realPart=__operateNumber;}
	};
	
	class Imaginary{
	    private:
	        int _____imaginaryPart;
	    public:
	        Imaginary(){this->_____imaginaryPart=0;}
	        Imaginary(int __operateNumber){this->_____imaginaryPart=__operateNumber;}
	        int getImaginary(){return this->_____imaginaryPart;}
	        void setImaginary(int __operateNumber){this->_____imaginaryPart=__operateNumber;}
	};
	
	class ComplexNumber{
	    private:
	        Real a;
	        Imaginary b;
	    public:
	    	
	        int getReal(){return this->a.getReal();}
	       
	        int getImaginary(){return this->b.getImaginary();}
	       
	        void setReal(int __operateNumber){this->a.setReal(__operateNumber);}
	       
	        void setImaginary(int __operateNumber){this->b.setImaginary(__operateNumber);}
	       
	        ComplexNumber operator*(ComplexNumber __operateNumber){
	            ComplexNumber temp;
	            temp.setReal(this->a.getReal()*__operateNumber.getReal()-(this->b.getImaginary()*__operateNumber.getImaginary()));
	            temp.setImaginary(this->a.getReal()*__operateNumber.getImaginary()+(this->b.getImaginary()*__operateNumber.getReal()));
	            return temp;
	        }
	       
	        ComplexNumber operator+(ComplexNumber __operateNumber){
	            ComplexNumber temp;
	            temp.setReal(this->a.getReal()+__operateNumber.getReal());
	            temp.setImaginary(this->b.getImaginary()+__operateNumber.getImaginary());
	            return temp;
	        }
	       
	        ComplexNumber(int __realNumber){
	            this->a.setReal(__realNumber);
	        }
	       
	        ComplexNumber(){
	            this->a.setReal(0);
	            this->b.setImaginary(0);
	        }
   	    	
   	    	typedef ComplexNumber Complex;
   	    	typedef ComplexNumber Cint;
	};
	
}
#endif

