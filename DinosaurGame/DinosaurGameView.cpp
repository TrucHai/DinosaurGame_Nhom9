
// DinosaurGameView.cpp : implementation of the CDinosaurGameView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "DinosaurGame.h"
#endif

#include "DinosaurGameDoc.h"
#include "DinosaurGameView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CDinosaurGameView

IMPLEMENT_DYNCREATE(CDinosaurGameView, CView)

BEGIN_MESSAGE_MAP(CDinosaurGameView, CView)
	ON_WM_KEYDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CDinosaurGameView construction/destruction

CDinosaurGameView::CDinosaurGameView() noexcept
{
	// TODO: add construction code here
	maingame = PlayGame();

}

CDinosaurGameView::~CDinosaurGameView()
{
}

BOOL CDinosaurGameView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CDinosaurGameView drawing

void CDinosaurGameView::OnDraw(CDC* pDC)
{
	CDinosaurGameDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CClientDC pdc(this);
	CDC* cdc = GetDC();
	HDC hdc = pdc.GetSafeHdc();
	SetBkMode(pdc, TRANSPARENT);


	CFrameWnd* pFrame = (CFrameWnd*)AfxGetApp()->m_pMainWnd;
	CView* pView = pFrame->GetActiveView();
	CWnd* pWnd = pView;  // pView có thể được sử dụng như một CWnd
	maingame.display_menu(&pdc, hdc, cdc);
}
void CDinosaurGameView::movedino()
{

		maingame.movedino();
	
}

void CDinosaurGameView::jumpdino()
{
	if (!maingame.isjumping()) {
		maingame.dinojump();
	}
}

void CDinosaurGameView::createcactus()
{
	CClientDC pdc(this);
	CDC* pDC = GetDC();
	
	maingame.create_cactus(&pdc, pDC);
}

void CDinosaurGameView::movecactus()
{

	maingame.movecactus();
}

void CDinosaurGameView::displayGame()
{
	CClientDC pdc(this);
	CDC* pDC = GetDC();
	SetBkMode(pdc, TRANSPARENT);
	maingame.displayupdate(&pdc, pDC);
	
}

UINT newThreadProc(LPVOID pParam)
{
	CDinosaurGameView* view = (CDinosaurGameView*)pParam;
	view->movedino();
	return 1;
}
UINT newThreadProc1(LPVOID pParam)
{
	CDinosaurGameView* view = (CDinosaurGameView*)pParam;
	view->displayGame();
	return 1;
}
UINT newThreadProc2(LPVOID pParam)
{
	CDinosaurGameView* view = (CDinosaurGameView*)pParam;
	view->movecactus();
	return 1;
}
UINT newThreadProc3(LPVOID pParam)
{
	CDinosaurGameView* view = (CDinosaurGameView*)pParam;
	view->jumpdino();
	return 1;
}
UINT newThreadProc4(LPVOID pParam)
{
	CDinosaurGameView* view = (CDinosaurGameView*)pParam;
	view->createcactus();
	return 1;
}

// CDinosaurGameView diagnostics

#ifdef _DEBUG
void CDinosaurGameView::AssertValid() const
{
	CView::AssertValid();
}

void CDinosaurGameView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDinosaurGameDoc* CDinosaurGameView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDinosaurGameDoc)));
	return (CDinosaurGameDoc*)m_pDocument;
}
#endif //_DEBUG


// CDinosaurGameView message handlers


void CDinosaurGameView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	CDC* pDC = GetDC();
	CClientDC pdc(this);
	if (nChar == 13) {
		maingame.addpoint(500);
	}
	if (maingame.ismenu || maingame.isrestart) {
		return;
	}
	if (nChar == 32 || nChar == 38) {
		AfxBeginThread(newThreadProc3, this);
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}



void CDinosaurGameView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CClientDC pdc(this);
	CDC* cdc = GetDC();
	HDC hdc = pdc.GetSafeHdc();
	SetBkMode(pdc, TRANSPARENT);


	CFrameWnd* pFrame = (CFrameWnd*)AfxGetApp()->m_pMainWnd;
	CView* pView = pFrame->GetActiveView();
	CWnd* pWnd = pView;  // pView có thể được sử dụng như một CWnd
	maingame.display_change_button(point, &pdc, hdc, cdc);

	CView::OnMouseMove(nFlags, point);
}


void CDinosaurGameView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CClientDC pdc(this);
	CDC* cdc = GetDC();
	HDC hdc = pdc.GetSafeHdc();
	SetBkMode(pdc, TRANSPARENT);


	CFrameWnd* pFrame = (CFrameWnd*)AfxGetApp()->m_pMainWnd;
	CView* pView = pFrame->GetActiveView();
	CWnd* pWnd = pView;  // pView có thể được sử dụng như một CWnd
	if (maingame.click_button(nFlags, point, &pdc, pWnd, hdc, cdc)) {
		Sleep(1500);
		AfxBeginThread(newThreadProc4, this);
		AfxBeginThread(newThreadProc2, this);
		AfxBeginThread(newThreadProc1, this);
		AfxBeginThread(newThreadProc, this);
	};
	CView::OnLButtonDown(nFlags, point);
}
