#pragma once
#include "Cstudent.h"
class CPtr_auto
{
public:

	CPtr_auto(CStudent* pObj)
	{
		m_pObj = pObj;
	}
	~CPtr_auto()
	{
		if (m_pObj != nullptr)
		{
			delete m_pObj;
		}
	}
#pragma region 不允许拷贝构造
	/*CPtr_auto& operator=(CPtr_auto&) = delete;
	CPtr_auto(CPtr_auto&) = delete;*/
#pragma endregion

#pragma region 拷贝移动
	CPtr_auto& operator=(CPtr_auto& sp) {
		if (m_pObj != nullptr)
		{
			delete m_pObj;
		}
		m_pObj = sp.m_pObj;
		sp.m_pObj = nullptr;
		return *this;
	}
	CPtr_auto(CPtr_auto&) = delete;
#pragma endregion




	CStudent* operator->() {
		return m_pObj;
	}
	CStudent& operator*() {
		return *m_pObj;
	}
	operator bool() {
		m_pObj != nullptr;
	}
private:
	CStudent* m_pObj;
};

