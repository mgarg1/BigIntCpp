// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"
// #include "string.h"
// #include "stdlib.h"

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
// #include ""

#define Int int

class BigInt {
	const char *cptr;
	char *ptr;
	Int sz;
public:

	BigInt(const char *a)
			:sz(strlen(a)){
		
		ptr = (char *)malloc(sz);
		strncpy(ptr, a, sz);
	}

	BigInt(Int a){
		sz = log10(a);
		ptr = (char *)malloc(sz);
		for(Int i=0;i<sz;++i){
			ptr[sz-i-1] = a % 10;
			a = a / 10;
		}
	}

	~BigInt(){
		free(ptr);
	}

	const char *c_str() {
		return ptr;
	}

	BigInt operator+(BigInt &a) {

		int ll = this->sz;// strlen(this->ptr);
		int sl = a.sz;//strlen(a.c_str());

		const char *small;
		const char *large;
		if(ll > sl) {
			large = this->ptr; 
			small = a.c_str();
		}
		else {
			large = a.c_str();
			small = this->ptr;
			int t = ll;
			ll = sl;
			sl = t;
		}
		
		char *newStr = (char *)malloc((ll+1+1)*sizeof(char));
		int carry = 0;

		for (int i = 0; i < sl; ++i) {
			int temp = small[sl - i - 1] + large[ll - i - 1] - '0' - '0' + carry;
			newStr[ll - i] = temp % 10 + '0';
			carry = temp / 10;
		}

		for (int i = 0; i < ll - sl; ++i) {
			int temp = large[ll - sl - i - 1] - '0' + carry;
			newStr[ll - sl - i] = temp % 10 + '0';
			carry = temp / 10;
		}

		if (carry != 0) {
			newStr[0] = carry + '0';
			newStr[ll + 1] = '\0';
		}
		else {
			strncpy(newStr, newStr + 1, ll);
			newStr[ll] = '\0';
		}
		return BigInt(newStr);
	}
};


//1381

int main()
{
	BigInt B("999999999999999999999999999999"),C("2");
	// std::cout << (B+C).c_str();
	
	// const char *ptr = "1234";

	// char *ptr2 = (char *)malloc(5);
	
	// strncpy(ptr2,ptr,5);
	// strncpy(ptr2,ptr2+1,4);
	// ptr2[4] = '\0';
	
	// std::cout<<ptr2;
	// ptr[3] = '\0';
	// getchar();
	return 0;
}

