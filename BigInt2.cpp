// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"
// #include "string.h"
// #include "stdlib.h"

#include <iostream>
#include <cstring>
#include <cstdlib>
// #include ""

class BigInt {

	const char *ptr;

public:

	BigInt(const char *a) {
		ptr = a;
		//ptr = (const char *)malloc(strlen(a));
		//strncpy(ptr, a, strlen(a));
	}

	const char *c_str() {
		return ptr;
	}

	BigInt operator+(BigInt &a) {

		int ll = strlen(this->ptr);
		int sl = strlen(a.c_str());

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
	BigInt B("9999"),C("1");
	std::cout << (B+C).c_str();
	
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

