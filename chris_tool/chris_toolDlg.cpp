
// chris_toolDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "chris_tool.h"
#include "chris_toolDlg.h"
#include "afxdialogex.h"
#include <assert.h>
#include <windows.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cchris_toolDlg 对话框



Cchris_toolDlg::Cchris_toolDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CHRIS_TOOL_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cchris_toolDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Cchris_toolDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BT_calc, &Cchris_toolDlg::OnBnClickedBtcalc)
	ON_BN_CLICKED(IDC_BT_RE, &Cchris_toolDlg::OnBnClickedBtRe)
	ON_BN_CLICKED(IDC_BT_IP, &Cchris_toolDlg::OnBnClickedBtIp)
	ON_BN_CLICKED(IDC_BT_NoteBook, &Cchris_toolDlg::OnBnClickedBtNotebook)
	ON_BN_CLICKED(IDC_BT_SNAP, &Cchris_toolDlg::OnBnClickedBtSnap)
	ON_BN_CLICKED(IDC_BT_Write, &Cchris_toolDlg::OnBnClickedBtWrite)
	ON_BN_CLICKED(IDC_BT_Note, &Cchris_toolDlg::OnBnClickedBtNote)
	ON_BN_CLICKED(IDC_BT_Poweroff, &Cchris_toolDlg::OnBnClickedBtPoweroff)
END_MESSAGE_MAP()


// Cchris_toolDlg 消息处理程序

BOOL Cchris_toolDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	ShowWindow(SW_MINIMIZE);

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。


/*
提升进程权限
*/
bool improvePv()
{
	HANDLE hToken;
	TOKEN_PRIVILEGES tkp;
	if (!OpenProcessToken(GetCurrentProcess(), TOKEN_ALL_ACCESS, &hToken)) return false;
	if (!LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME, &tkp.Privileges[0].Luid)) return false;
	tkp.PrivilegeCount = 1;
	tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
	if (!AdjustTokenPrivileges(hToken, FALSE, &tkp, NULL, NULL, NULL)) return false;
	return true;
}

/*
关机
*/
bool powerOffProc()
{
	if (!improvePv() || !ExitWindowsEx(EWX_POWEROFF | EWX_FORCE, SHTDN_REASON_MAJOR_APPLICATION)) return false;
	return true;
}

/*
注销
*/
bool logOffProc()
{
	if (!improvePv() || !ExitWindowsEx(EWX_LOGOFF | EWX_FORCE, SHTDN_REASON_MAJOR_APPLICATION)) return false;
	return true;
}

/*
重启
*/
bool reBootProc()
{
	if (!improvePv() || !ExitWindowsEx(EWX_REBOOT | EWX_FORCE, SHTDN_REASON_MAJOR_APPLICATION)) return false;
	return true;
}

void Cchris_toolDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR Cchris_toolDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Cchris_toolDlg::OnBnClickedBtcalc()
{
	// TODO: 在此添加控件通知处理程序代码
	HINSTANCE hRslt = ShellExecute(NULL, _T("open"),

		_T("calc.exe"), NULL, NULL, SW_SHOWNORMAL);

	assert(hRslt > (HINSTANCE)HINSTANCE_ERROR);
}


void Cchris_toolDlg::OnBnClickedBtRe()
{
	// TODO: 在此添加控件通知处理程序代码
	HINSTANCE hRslt = ::ShellExecute(m_hWnd, "open", "devmgmt.msc", NULL, NULL, SW_SHOWNORMAL);
	assert(hRslt > (HINSTANCE)HINSTANCE_ERROR);
}


void Cchris_toolDlg::OnBnClickedBtIp()
{
	// TODO: 在此添加控件通知处理程序代码
	HINSTANCE hRslt = ::ShellExecute(NULL, _T("open"),

		_T("Nslookup.EXE"), NULL, NULL, SW_SHOWNORMAL);

	assert(hRslt > (HINSTANCE)HINSTANCE_ERROR);
}


void Cchris_toolDlg::OnBnClickedBtNotebook()
{
	// TODO: 在此添加控件通知处理程序代码
	HINSTANCE hRslt = ::ShellExecute(m_hWnd, "open", "notepad", NULL, NULL, SW_SHOWNORMAL);
	assert(hRslt > (HINSTANCE)HINSTANCE_ERROR);
}


void Cchris_toolDlg::OnBnClickedBtSnap()
{
	// TODO: 在此添加控件通知处理程序代码

	HINSTANCE hRslt = ::ShellExecute(m_hWnd, "open", "C:\WINDOWS\system32\SnippingTool.exe", NULL, NULL, SW_SHOWNORMAL);
	//assert(hRslt > (HINSTANCE)HINSTANCE_ERROR);
}


void Cchris_toolDlg::OnBnClickedBtWrite()
{
	// TODO: 在此添加控件通知处理程序代码
	ShellExecute(this->m_hWnd, "open", "http://www.baidu.com", "", "", SW_SHOW);
}


void Cchris_toolDlg::OnBnClickedBtNote()
{
	// TODO: 在此添加控件通知处理程序代码

	//ShellExecute(this->m_hWnd, "open", "	Notepad++", "", "", SW_SHOW);
}


void Cchris_toolDlg::OnBnClickedBtPoweroff()
{
	// TODO: 在此添加控件通知处理程序代码
	logOffProc();
}



