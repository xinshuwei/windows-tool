
// chris_toolDlg.cpp : ʵ���ļ�
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


// Cchris_toolDlg �Ի���



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


// Cchris_toolDlg ��Ϣ�������

BOOL Cchris_toolDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	ShowWindow(SW_MINIMIZE);

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�


/*
��������Ȩ��
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
�ػ�
*/
bool powerOffProc()
{
	if (!improvePv() || !ExitWindowsEx(EWX_POWEROFF | EWX_FORCE, SHTDN_REASON_MAJOR_APPLICATION)) return false;
	return true;
}

/*
ע��
*/
bool logOffProc()
{
	if (!improvePv() || !ExitWindowsEx(EWX_LOGOFF | EWX_FORCE, SHTDN_REASON_MAJOR_APPLICATION)) return false;
	return true;
}

/*
����
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
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR Cchris_toolDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Cchris_toolDlg::OnBnClickedBtcalc()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	HINSTANCE hRslt = ShellExecute(NULL, _T("open"),

		_T("calc.exe"), NULL, NULL, SW_SHOWNORMAL);

	assert(hRslt > (HINSTANCE)HINSTANCE_ERROR);
}


void Cchris_toolDlg::OnBnClickedBtRe()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	HINSTANCE hRslt = ::ShellExecute(m_hWnd, "open", "devmgmt.msc", NULL, NULL, SW_SHOWNORMAL);
	assert(hRslt > (HINSTANCE)HINSTANCE_ERROR);
}


void Cchris_toolDlg::OnBnClickedBtIp()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	HINSTANCE hRslt = ::ShellExecute(NULL, _T("open"),

		_T("Nslookup.EXE"), NULL, NULL, SW_SHOWNORMAL);

	assert(hRslt > (HINSTANCE)HINSTANCE_ERROR);
}


void Cchris_toolDlg::OnBnClickedBtNotebook()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	HINSTANCE hRslt = ::ShellExecute(m_hWnd, "open", "notepad", NULL, NULL, SW_SHOWNORMAL);
	assert(hRslt > (HINSTANCE)HINSTANCE_ERROR);
}


void Cchris_toolDlg::OnBnClickedBtSnap()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	HINSTANCE hRslt = ::ShellExecute(m_hWnd, "open", "C:\WINDOWS\system32\SnippingTool.exe", NULL, NULL, SW_SHOWNORMAL);
	//assert(hRslt > (HINSTANCE)HINSTANCE_ERROR);
}


void Cchris_toolDlg::OnBnClickedBtWrite()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ShellExecute(this->m_hWnd, "open", "http://www.baidu.com", "", "", SW_SHOW);
}


void Cchris_toolDlg::OnBnClickedBtNote()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	//ShellExecute(this->m_hWnd, "open", "	Notepad++", "", "", SW_SHOW);
}


void Cchris_toolDlg::OnBnClickedBtPoweroff()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	logOffProc();
}



