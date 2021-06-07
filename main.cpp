////////auto_ptr98
#include "My_ptr.h"

int main()
{
	CStudent* pStu = new CStudent();
	CRefCount<CStudent> ref(pStu);
	CSmartPtr<CStudent> sp1(pStu);
	sp1.test2();
	
	getchar();
	return 0;
}