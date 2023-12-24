
// DinosaurGameView.h : interface of the CDinosaurGameView class
//

#pragma once
#include "Background.h"
#include "PlayGame.h"
#include "Dinosaur.h"
#include "Cactus.h"

class CDinosaurGameView : public CView
{
protected: // create from serialization only
	CDinosaurGameView() noexcept;
	DECLARE_DYNCREATE(CDinosaurGameView)

// Attributes
public:
	CDinosaurGameDoc* GetDocument() const;
	bool isend;
	void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	void movedino();
	void jumpdino();
	void createcactus();
	void movecactus();
	void displayGame();

// Operations
public:
	PlayGame maingame;

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CDinosaurGameView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in DinosaurGameView.cpp
inline CDinosaurGameDoc* CDinosaurGameView::GetDocument() const
   { return reinterpret_cast<CDinosaurGameDoc*>(m_pDocument); }
#endif

