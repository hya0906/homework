
// ChildView.h: CChildView 클래스의 인터페이스
//


#pragma once


// CChildView 창

class CChildView : public CWnd
{
// 생성입니다.
public:
	bool start_flag;//필요없을듯
	CRect clientview;
	int gap = 20;    //오선 간격
	int p_gap;       //건반두께간격
	int note = 25;   //음표 크기
	CList <CRect, CRect&> position_list; //피아노건반위치
	void first_setting(CDC* dc, CRect clientview); //처음세팅그림
	void draw_notes();//음표그리기(일단 하나 그려놓음)
	CChildView();

// 특성입니다.
public:

// 작업입니다.
public:

// 재정의입니다.
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 구현입니다.
public:
	virtual ~CChildView();

	// 생성된 메시지 맵 함수
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

