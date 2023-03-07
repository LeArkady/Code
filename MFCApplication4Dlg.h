
// MFCApplication4Dlg.h: файл заголовка
//

#pragma once


// Диалоговое окно CMFCApplication4Dlg
class CMFCApplication4Dlg : public CDialogEx
{
// Создание
public:
	CMFCApplication4Dlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION4_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedAboutbox();
	CComboBox m_note0_0;
	CComboBox m_note0_1;
	CComboBox m_note0_2;
	CComboBox m_note0_3;
	CComboBox m_note0_4;
	CComboBox m_note0_5;
	CComboBox m_note0_6;
	CComboBox m_note0_7;
	CComboBox m_note1_0;
	CComboBox m_note1_1;
	CComboBox m_note1_2;
	CComboBox m_note1_3;
	CComboBox m_note1_4;
	CComboBox m_note1_5;
	CComboBox m_note1_6;
	CComboBox m_note1_7;
	CComboBox m_note2_0;
	CComboBox m_note2_1;
	CComboBox m_note2_2;
	CComboBox m_note2_3;
	CComboBox m_note2_4;
	CComboBox m_note2_5;
	CComboBox m_note2_6;
	CComboBox m_note2_7;
	CComboBox m_note3_0;
	CComboBox m_note3_1;
	CComboBox m_note3_2;
	CComboBox m_note3_3;
	CComboBox m_note3_4;
	CComboBox m_note3_5;
	CComboBox m_note3_6;
	CComboBox m_note3_7;
	CComboBox m_note5_0;
	CComboBox m_note5_1;
	CComboBox m_note5_2;
	CComboBox m_note5_3;
	CComboBox m_note5_4;
	CComboBox m_note5_5;
	CComboBox m_note5_6;
	CComboBox m_note5_7;
	CComboBox m_note4_0;
	CComboBox m_note4_1;
	CComboBox m_note4_2;
	CComboBox m_note4_3;
	CComboBox m_note4_4;
	CComboBox m_note4_5;
	CComboBox m_note4_6;
	CComboBox m_note4_7;
	CComboBox m_note6_0;
	CComboBox m_note6_1;
	CComboBox m_note6_2;
	CComboBox m_note6_3;
	CComboBox m_note6_4;
	CComboBox m_note6_5;
	CComboBox m_note6_6;
	CComboBox m_note6_7;
	CComboBox m_note7_0;
	CComboBox m_note7_1;
	CComboBox m_note7_2;
	CComboBox m_note7_3;
	CComboBox m_note7_4;
	CComboBox m_note7_5;
	CComboBox m_note7_6;
	CComboBox m_note7_7;
	unsigned int m_depth;
	unsigned int m_pause;
	CComboBox m_stench;
	CComboBox m_harmrhytm;
};
