
// DinosaurGame.h : main header file for the DinosaurGame application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CDinosaurGameApp:
// See DinosaurGame.cpp for the implementation of this class
//

class CDinosaurGameApp : public CWinApp
{
public:
	CDinosaurGameApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDinosaurGameApp theApp;
