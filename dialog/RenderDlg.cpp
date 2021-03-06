// dialog\RenderDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "../Rhino.h"
#include "RenderDlg.h"
#include "afxdialogex.h"
#include "RenderDlg.h"


// RenderDlg 对话框

IMPLEMENT_DYNAMIC(RenderDlg, CDialogEx)

RenderDlg::RenderDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_RENDER_DIALOG, pParent)
{

}

RenderDlg::~RenderDlg()
{
}

void RenderDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(RenderDlg, CDialogEx)
	ON_WM_CLOSE()
	ON_WM_DESTROY()
	ON_WM_MBUTTONDOWN()
	ON_WM_MBUTTONUP()
	ON_WM_RBUTTONUP()
	ON_COMMAND(WM_CLOSE, &RenderDlg::OnClose)
END_MESSAGE_MAP()


// RenderDlg 消息处理程序


BOOL RenderDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_ContextMenu.CreatePopupMenu();
	m_ContextMenu.AppendMenu(MF_STRING, WM_CLOSE, TEXT("隐藏"));

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void RenderDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	ShowWindow(SW_HIDE);

	CDialogEx::OnClose();
}


void RenderDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	m_ContextMenu.DestroyMenu();

	// TODO: 在此处添加消息处理程序代码
}


void RenderDlg::OnMButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CDialogEx::OnMButtonUp(nFlags, point);
}


void RenderDlg::OnMButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CDialogEx::OnMButtonDown(nFlags, point);
}


void RenderDlg::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	LPPOINT lpoint = new tagPOINT;
	::GetCursorPos(lpoint);//得到鼠标位置

	m_ContextMenu.TrackPopupMenu(TPM_LEFTALIGN | TPM_LEFTBUTTON | TPM_VERNEGANIMATION, lpoint->x, lpoint->y, this);

	CDialogEx::OnRButtonUp(nFlags, point);
}
