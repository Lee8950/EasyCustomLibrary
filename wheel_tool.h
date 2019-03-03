#ifndef __WHEEL__TOOL__H__
#define __WHEEL__TOOL__H__

#include<string>
#include<fstream>

namespace ecl
{
	
	/*CONSTANT NUM FOR MD5 CRYPTION*/
	const unsigned int __CPT__WHEEL__k[]={
   	        0xd76aa478,0xe8c7b756,0x242070db,0xc1bdceee,
    	    0xf57c0faf,0x4787c62a,0xa8304613,0xfd469501,0x698098d8,
    	    0x8b44f7af,0xffff5bb1,0x895cd7be,0x6b901122,0xfd987193,
    	    0xa679438e,0x49b40821,0xf61e2562,0xc040b340,0x265e5a51,
    	    0xe9b6c7aa,0xd62f105d,0x02441453,0xd8a1e681,0xe7d3fbc8,
    	    0x21e1cde6,0xc33707d6,0xf4d50d87,0x455a14ed,0xa9e3e905,
    	    0xfcefa3f8,0x676f02d9,0x8d2a4c8a,0xfffa3942,0x8771f681,
    	    0x6d9d6122,0xfde5380c,0xa4beea44,0x4bdecfa9,0xf6bb4b60,
    	    0xbebfbc70,0x289b7ec6,0xeaa127fa,0xd4ef3085,0x04881d05,
    	    0xd9d4d039,0xe6db99e5,0x1fa27cf8,0xc4ac5665,0xf4292244,
    	    0x432aff97,0xab9423a7,0xfc93a039,0x655b59c3,0x8f0ccc92,
    	    0xffeff47d,0x85845dd1,0x6fa87e4f,0xfe2ce6e0,0xa3014314,
    	    0x4e0811a1,0xf7537e82,0xbd3af235,0x2ad7d2bb,0xeb86d391};
	const unsigned int __CPT__WHEEL__s[]={7,12,17,22,7,12,17,22,7,12,17,22,7,
        12,17,22,5,9,14,20,5,9,14,20,5,9,14,20,5,9,14,20,
        4,11,16,23,4,11,16,23,4,11,16,23,4,11,16,23,6,10,
        15,21,6,10,15,21,6,10,15,21,6,10,15,21};
	const char __CPT__WHEEL__str16[]="0123456789abcdef";
	const unsigned int __CPT__WHEEL__A=0x67452301;
	const unsigned int __CPT__WHEEL__B=0xefcdab89;
	const unsigned int __CPT__WHEEL__C=0x98badcfe;
	const unsigned int __CPT__WHEEL__D=0x10325476;
	/*CONSTANT NUM FOR MD5 CRYPTION*/
	
	
	/*
	*An object to hide details and provide user interface
	*/
	class cpt{
		public:
			
			std::string crypt(std::string &__target){
				std::string __tmp=getMD5(this->password);
				for(int i=0;i<__target.length();i++){
					__target[i]=__target[i]^__tmp[i%__tmp.length()];
				}
				return __target;
			}
			
			void set_pw(std::string __pw){
				this->password=__pw;
				return;
			}
			
			std::string get_pw(void){
				return this->password;
			}
			
			cpt(){/*
				   *constructor default password:000000
				   */
				this->password="000000";}
			
			cpt(std::string __pw){
				this->password=__pw;/*init constructor */}
			    
		private:
			
			int lineCounter(std::string address)
			{
				int line=0;
				std::string read;
				std::ifstream fin;
				fin.open(address.c_str());
				while(getline(fin,read))
					line++;
				fin.close();
				return line;
			}
			
			std::string getMD5(std::string __CPT__WHEEL__source)
			{
			    __CPT__WHEEL__atemp=__CPT__WHEEL__A;
			    __CPT__WHEEL__btemp=__CPT__WHEEL__B;
			    __CPT__WHEEL__ctemp=__CPT__WHEEL__C;
				__CPT__WHEEL__dtemp=__CPT__WHEEL__D;
    			unsigned int *__CPT__WHEEL__strByte=__CPT__WHEEL__add(__CPT__WHEEL__source);
    			for(unsigned int __CPT__WHEEL__i=0;__CPT__WHEEL__i<__CPT__WHEEL__strlength/16;__CPT__WHEEL__i++)
    			{
	  		      unsigned int __CPT__WHEEL__num[16];
	  		      for(unsigned int __CPT__WHEEL__j=0;__CPT__WHEEL__j<16;__CPT__WHEEL__j++)
	 		           __CPT__WHEEL__num[__CPT__WHEEL__j]=__CPT__WHEEL__strByte[__CPT__WHEEL__i*16+__CPT__WHEEL__j];
	 		       __CPT__WHEEL__mainLoop(__CPT__WHEEL__num);
	 		   }
	  		    return __CPT__WHEEL__changeHex(__CPT__WHEEL__atemp).append(__CPT__WHEEL__changeHex(__CPT__WHEEL__btemp)).append(__CPT__WHEEL__changeHex(__CPT__WHEEL__ctemp)).append(__CPT__WHEEL__changeHex(__CPT__WHEEL__dtemp));
			}
			
			void __CPT__WHEEL__mainLoop(unsigned int __CPT__WHEEL__M[])
			{
	    		unsigned int __CPT__WHEEL__f,__CPT__WHEEL__g;
	   		    unsigned int __CPT__WHEEL__a=__CPT__WHEEL__atemp;
	    		unsigned int __CPT__WHEEL__b=__CPT__WHEEL__btemp;
	    		unsigned int __CPT__WHEEL__c=__CPT__WHEEL__ctemp;
	    		unsigned int __CPT__WHEEL__d=__CPT__WHEEL__dtemp;
	    		for (unsigned int __CPT__WHEEL__i = 0; __CPT__WHEEL__i < 64; __CPT__WHEEL__i++)
	    		{
	    		    if(__CPT__WHEEL__i<16){
	    		        __CPT__WHEEL__f=(((__CPT__WHEEL__b) & (__CPT__WHEEL__c)) | ((~__CPT__WHEEL__b) & (__CPT__WHEEL__d)));
	    		        __CPT__WHEEL__g=__CPT__WHEEL__i;
	    		    }else if (__CPT__WHEEL__i<32)
	    		    {
        		    	__CPT__WHEEL__f=(((__CPT__WHEEL__b) & (__CPT__WHEEL__d)) | ((__CPT__WHEEL__c) & (~__CPT__WHEEL__d)));
        		    	__CPT__WHEEL__g=(5*__CPT__WHEEL__i+1)%16;
        			}else if(__CPT__WHEEL__i<48){
        			    __CPT__WHEEL__f=((__CPT__WHEEL__b) ^ (__CPT__WHEEL__c) ^ (__CPT__WHEEL__d));
        			    __CPT__WHEEL__g=(3*__CPT__WHEEL__i+5)%16;
        			}else{
        			    __CPT__WHEEL__f=((__CPT__WHEEL__c) ^ ((__CPT__WHEEL__b) | (~__CPT__WHEEL__d)));
        			    __CPT__WHEEL__g=(7*__CPT__WHEEL__i)%16;
        			}
        			unsigned int __CPT__WHEEL__tmp=__CPT__WHEEL__d;
        			__CPT__WHEEL__d=__CPT__WHEEL__c;
        			__CPT__WHEEL__c=__CPT__WHEEL__b;
        			__CPT__WHEEL__b=__CPT__WHEEL__b+(((__CPT__WHEEL__a+__CPT__WHEEL__f+__CPT__WHEEL__k[__CPT__WHEEL__i]+__CPT__WHEEL__M[__CPT__WHEEL__g]) << __CPT__WHEEL__s[__CPT__WHEEL__i]) | ((__CPT__WHEEL__a+__CPT__WHEEL__f+__CPT__WHEEL__k[__CPT__WHEEL__i]+__CPT__WHEEL__M[__CPT__WHEEL__g]) >> (32-__CPT__WHEEL__s[__CPT__WHEEL__i])));
        			__CPT__WHEEL__a=__CPT__WHEEL__tmp;
					}
    			__CPT__WHEEL__atemp=__CPT__WHEEL__a+__CPT__WHEEL__atemp;
   				__CPT__WHEEL__btemp=__CPT__WHEEL__b+__CPT__WHEEL__btemp;
    			__CPT__WHEEL__ctemp=__CPT__WHEEL__c+__CPT__WHEEL__ctemp;
    			__CPT__WHEEL__dtemp=__CPT__WHEEL__d+__CPT__WHEEL__dtemp;
			}
			
	        unsigned int* __CPT__WHEEL__add(std::string __CPT__WHEEL__str)
			{
			    unsigned int __CPT__WHEEL__num=((__CPT__WHEEL__str.length()+8)/64)+1;
			    unsigned int *__CPT__WHEEL__strByte=new unsigned int[__CPT__WHEEL__num*16];
			    __CPT__WHEEL__strlength=__CPT__WHEEL__num*16;
			    for (unsigned int __CPT__WHEEL__i = 0; __CPT__WHEEL__i < __CPT__WHEEL__num*16; __CPT__WHEEL__i++)
			        __CPT__WHEEL__strByte[__CPT__WHEEL__i]=0;
			    for (unsigned int __CPT__WHEEL__i=0; __CPT__WHEEL__i <__CPT__WHEEL__str.length(); __CPT__WHEEL__i++)
			    {
			        __CPT__WHEEL__strByte[__CPT__WHEEL__i>>2]|=(__CPT__WHEEL__str[__CPT__WHEEL__i])<<((__CPT__WHEEL__i%4)*8);
			    }
			    __CPT__WHEEL__strByte[__CPT__WHEEL__str.length()>>2]|=0x80<<(((__CPT__WHEEL__str.length()%4))*8);
 		  		__CPT__WHEEL__strByte[__CPT__WHEEL__num*16-2]=__CPT__WHEEL__str.length()*8;
  		  		return __CPT__WHEEL__strByte;
			}
			
			std::string __CPT__WHEEL__changeHex(int __CPT__WHEEL__a)
			{
			    int __CPT__WHEEL__b;
			    std::string __CPT__WHEEL__str1;
			    std::string __CPT__WHEEL__str="";
			    for(int __CPT__WHEEL__i=0;__CPT__WHEEL__i<4;__CPT__WHEEL__i++)
			    {
			        __CPT__WHEEL__str1="";
	 		       __CPT__WHEEL__b=((__CPT__WHEEL__a>>__CPT__WHEEL__i*8)%(1<<8))&0xff;
	 		       for (int __CPT__WHEEL__j = 0; __CPT__WHEEL__j < 2; __CPT__WHEEL__j++)
			        {
			            __CPT__WHEEL__str1.insert(0,1,__CPT__WHEEL__str16[__CPT__WHEEL__b%16]);
			            __CPT__WHEEL__b=__CPT__WHEEL__b/16;
			        }
			        __CPT__WHEEL__str+=__CPT__WHEEL__str1;
			    }
			    return __CPT__WHEEL__str;
			}
			
			/*private variable*/
			unsigned int __CPT__WHEEL__strlength;
			unsigned int __CPT__WHEEL__atemp;
			unsigned int __CPT__WHEEL__btemp;
			unsigned int __CPT__WHEEL__ctemp;
			unsigned int __CPT__WHEEL__dtemp;
			std::string password;
			/*private variable*/
	};
	
}
#endif
