
// ChildView.cpp: CChildView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
#include "MFC_project.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()



// CChildView 메시지 처리기

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this);
	GetClientRect(&clientview);    //화면 크기 얻어옴
	first_setting(&dc, clientview); //기본화면 그리기
	draw_notes();//음표그리기
}

void CChildView::first_setting(CDC *dc, CRect clientview) {
	for (int i = 0; i < 5; i++) {//오선지 그리기
		dc->MoveTo(50, clientview.Height() / 5 - gap * i);
		dc->LineTo(clientview.Width() - 50, clientview.Height() / 5 - gap * i);
	}
	p_gap = clientview.Width() / 3 - clientview.Width() / 2.5;
	//for (int i = 1; i <= 4; i++) {//피아노 그리기(흰건반만)
	//	dc->Rectangle(clientview.Width() / 2 + (i - 1) * p_gap, clientview.Height() / 3, clientview.Width() / 2 + i * p_gap, clientview.Height());
	//	dc->Rectangle(clientview.Width() / 2 - i * p_gap, clientview.Height() / 3, clientview.Width() / 2 - (i - 1) * p_gap, clientview.Height());
	//	
	//}
	for (int i = -3; i <= 4; i++) {//피아노 건반 위치
		position_list.AddTail(CRect(clientview.Width() / 2 - i * p_gap, clientview.Height() / 3, clientview.Width() / 2 - (i-1) * p_gap, clientview.Height()));
	}
	//position_list.AddTail(CRect(clientview.Width() / 2 + 3 * p_gap, clientview.Height() / 3, clientview.Width() / 2 + 4 * p_gap, clientview.Height()));//도
	//position_list.AddTail(CRect(clientview.Width() / 2 + 2 * p_gap, clientview.Height() / 3, clientview.Width() / 2 + 3 * p_gap, clientview.Height()));//레
	//position_list.AddTail(CRect(clientview.Width() / 2 + 1 * p_gap, clientview.Height() / 3, clientview.Width() / 2 + 2 * p_gap, clientview.Height()));//미
	//position_list.AddTail(CRect(clientview.Width() / 2 + 0 * p_gap, clientview.Height() / 3, clientview.Width() / 2 + 1 * p_gap, clientview.Height()));//파
	//position_list.AddTail(CRect(clientview.Width() / 2 - 1 * p_gap, clientview.Height() / 3, clientview.Width() / 2 - 0 * p_gap, clientview.Height()));//솔
	//position_list.AddTail(CRect(clientview.Width() / 2 - 2 * p_gap, clientview.Height() / 3, clientview.Width() / 2 - 1 * p_gap, clientview.Height()));//라
	//position_list.AddTail(CRect(clientview.Width() / 2 - 3 * p_gap, clientview.Height() / 3, clientview.Width() / 2 - 2 * p_gap, clientview.Height()));//시
	//position_list.AddTail(CRect(clientview.Width() / 2 - 4 * p_gap, clientview.Height() / 3, clientview.Width() / 2 - 3 * p_gap, clientview.Height()));//도
}

void CChildView::draw_notes() {//위치받는 리스트 필요
	CClientDC dc(this);
	CBrush brush(RGB(0, 0, 0)),* pbrush;
	pbrush = dc.SelectObject(&brush);
	dc.Ellipse(50, clientview.Height() / 5 - gap, 50 + note, clientview.Height() / 5);//파
	dc.SelectObject(pbrush);
	brush.DeleteObject();
}

void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	
	CWnd::OnLButtonDown(nFlags, point);
}
