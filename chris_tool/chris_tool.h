
// chris_tool.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Cchris_toolApp: 
// �йش����ʵ�֣������ chris_tool.cpp
//

class Cchris_toolApp : public CWinApp
{
public:
	Cchris_toolApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Cchris_toolApp theApp;