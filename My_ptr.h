#pragma once
#include "Cstudent.h"
template<typename T>
class CSmartPtr;
template<typename T>
class CRefCount
{
	friend class CSmartPtr<T>;
public:
	CRefCount(T* p_Stu)
	{
		m_pObj = p_Stu;
		m_nCount = 1;

	}
	~CRefCount() {
		delete m_pObj;
		m_pObj = NULL;
	}
	//新增引用
	void AddRef()
	{
		m_nCount++;
	}
	void Release() {
		if (--m_nCount == 0)
		{
			delete this;
		}
	}
private:
	T* m_pObj;
	int m_nCount;
};
template<typename T>
class CSmartPtr
{
public:
	CSmartPtr()
	{
		m_pRef = NULL;
	}
	CSmartPtr(T* p_Stu)
	{
		m_pRef =new CRefCount<T>(p_Stu);
	}
	~CSmartPtr()
	{
		m_pRef->Release();
	}
	CSmartPtr(CSmartPtr& obj) {
		m_pRef = obj.m_pRef;
		m_pRef->AddRef();
	}
	CSmartPtr& operator=(CSmartPtr& obj) {
		if (m_pRef == obj.m_pRef)
		{
			return *this;
		}
		m_pRef->AddRef();
		if (m_pRef != NULL)
		{
			m_pRef->Release();
		}
		m_pRef = obj.m_pRef;
		return *this;
	}
	void test2()
	{
		cout << "hello2" << endl;
	}
	T* operator->()
	{
		return m_pRef->m_pObj;
	}
	T** operator&()
	{
		return &m_pRef->m_pObj;
	}
	T& operator*()
	{
		return *m_pRef->m_pObj;
	}
	operator T*() {
		return m_pRef->m_pObj;
	}
private:
	CRefCount<T>* m_pRef;
};

