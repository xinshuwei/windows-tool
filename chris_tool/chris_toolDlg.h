
// chris_toolDlg.h : 头文件
//

#pragma once


// Cchris_toolDlg 对话框
class Cchris_toolDlg : public CDialogEx
{
// 构造
public:
	Cchris_toolDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHRIS_TOOL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtcalc();
	afx_msg void OnBnClickedBtRe();
	afx_msg void OnBnClickedBtIp();
	afx_msg void OnBnClickedBtNotebook();
	afx_msg void OnBnClickedBtSnap();
	afx_msg void OnBnClickedBtWrite();
	afx_msg void OnBnClickedBtNote();
	afx_msg void OnBnClickedBtPoweroff();
};
