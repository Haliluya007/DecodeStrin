// DecodeStr.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <Windows.h>
#include <iostream>

using namespace std;

bool fuck(BYTE &by)
{
	by ^= 23;
	by += 45;
	return true;
}

bool fuck2(BYTE &by)
{
	by -= 45;
	by ^= 23;
	return true;
}
bool Decode(string& str)
{
	int len  = str.length();
	
	PBYTE pos = (PBYTE)str.c_str();
	
	for (size_t i =  0 ; i <  len ; ++i)
	{
		BYTE by = *(BYTE*)(pos + i);
		fuck(by);
		//memset(pos + i, by, 1);	
		*(BYTE*)(pos+i) = by;

	}
	return true;

}


bool Incode(string& str){

	int len  = str.length();

	PBYTE pos = (PBYTE)str.c_str();

	for (size_t i =  0 ; i <  len ; ++i)
	{
		BYTE by = *(BYTE*)(pos + i);
		fuck2(by);
		//memset(pos + i, by, 1);	
		*(BYTE*)(pos+i) = by;

	}
	return true;
}

int _tmain(int argc, _TCHAR* argv[])
{


#if 1	
	//string str = "hellp world";
	//printf("strstr:%s\n", str.c_str());
	//Decode(str);
	//printf("decode:%s\n", str.c_str());
	LPCSTR str = {'0xac', '0x9f', '0xa8', '0xa8', '0x94', '0x64', '0x8d', '0xa5', '0x92', '0xa8', '0xa0', '0x00'};
	Incode(str);
	printf("Incode:%s\n", str.c_str());

#endif
	// LoadLibraryA
	//unsigned char data[12] = {
	//	0x4C, 0x6F, 0x61, 0x64, 0x4C, 0x69, 0x61, 0x72, 0x62, 0x72, 0x79, 0x41
	//};
	//
	//unsigned long data_[] = {'ABCD','FEGH',0};
	//
	//unsigned short dat[] = {0x4141,0x4242,0};
 //
	//char str[MAX_PATH] = {0};

	//memcpy(&str, data, sizeof(data));




	return 0;
}

