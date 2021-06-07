#pragma once
#include<iostream>
#include<cstring>
using namespace std;
class CStudent
{
public:
	CStudent()
	{

	}
	
	void test() {
		cout << "hello" << endl;
	}
private:
	char* m_pszBuf;
	int m_nSex;
};
