
// chris_toolDlg.h : ͷ�ļ�
//

#pragma once


// Cchris_toolDlg �Ի���
class Cchris_toolDlg : public CDialogEx
{
// ����
public:
	Cchris_toolDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHRIS_TOOL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
