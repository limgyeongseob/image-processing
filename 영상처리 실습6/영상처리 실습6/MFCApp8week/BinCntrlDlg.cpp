// BinCntrlDlg.cpp: 구현 파일
//

#include "pch.h"
#include "MFCApp8week.h"
#include "BinCntrlDlg.h"
#include "afxdialogex.h"

#include "MainFrm.h"
#include "ChildFrm.h"
#include "MFCApp8weekDoc.h"

// CBinCntrlDlg 대화 상자

IMPLEMENT_DYNAMIC(CBinCntrlDlg, CDialog)

CBinCntrlDlg::CBinCntrlDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
	, m_binValDisp(0)
{

}

CBinCntrlDlg::~CBinCntrlDlg()
{
}

void CBinCntrlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_binValDisp);
	DDV_MinMaxInt(pDX, m_binValDisp, 0, 255);
	DDX_Control(pDX, IDC_SLIDER1, m_ctrlSlider);
}


BEGIN_MESSAGE_MAP(CBinCntrlDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CBinCntrlDlg::OnBNApply)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, &CBinCntrlDlg::OnCustomdrawSlider1)
END_MESSAGE_MAP()


// CBinCntrlDlg 메시지 처리기


void CBinCntrlDlg::OnBNApply()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	OnOK(); //대화박스 종료
}


BOOL CBinCntrlDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_ctrlSlider.SetRange(0, 255);   //슬라이드바의 값의 범위 설정
	m_ctrlSlider.SetPos(100);  //슬라이드바의 초기 상태 설정

	m_binValDisp = m_ctrlSlider.GetPos();   //현재 설정되어 있는 값을 잡아온다
	UpdateData(FALSE); //설정된 데이터값으로 다이올로그박스의 표시부 갱신

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CBinCntrlDlg::OnCustomdrawSlider1(NMHDR* pNMHDR, LRESULT* pResult)
{
	
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	ASSERT(pFrame);
	CChildFrame* pChild = (CChildFrame*)pFrame->GetActiveFrame();
	ASSERT(pChild);
	CMFCApp8weekDoc* pDoc = (CMFCApp8weekDoc*)pChild->GetActiveDocument();
	ASSERT(pDoc);

	//Slider의 현재 위치를 잡아온다
	m_binValDisp = m_ctrlSlider.GetPos();
	UpdateData(FALSE);  //잡아온 데이터값으로 다이얼로그박스의 표시부 갱신
	//현재 활성화 도큐먼트클래스 아래의 이치화 계산함수를 호출
	pDoc->m_BinThres(256, 256, m_binValDisp);  //슬라이드설정 이치화 계수치를 넘겨줌
	
}
