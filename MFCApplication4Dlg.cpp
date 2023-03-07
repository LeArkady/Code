
// MFCApplication4Dlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication4.h"
#include "MFCApplication4Dlg.h"
#include "afxdialogex.h"

#include "Music.h"




#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Диалоговое окно CMFCApplication4Dlg



CMFCApplication4Dlg::CMFCApplication4Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION4_DIALOG, pParent)
	, m_depth(0)
	, m_pause(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication4Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_note0_0);
	DDX_Control(pDX, IDC_COMBO2, m_note0_1);
	DDX_Control(pDX, IDC_COMBO3, m_note0_2);
	DDX_Control(pDX, IDC_COMBO4, m_note0_3);
	DDX_Control(pDX, IDC_COMBO5, m_note0_4);
	DDX_Control(pDX, IDC_COMBO6, m_note0_5);
	DDX_Control(pDX, IDC_COMBO7, m_note0_6);
	DDX_Control(pDX, IDC_COMBO8, m_note0_7);
	DDX_Control(pDX, IDC_COMBO9, m_note1_0);
	DDX_Control(pDX, IDC_COMBO10, m_note1_1);
	DDX_Control(pDX, IDC_COMBO11, m_note1_2);
	DDX_Control(pDX, IDC_COMBO12, m_note1_3);
	DDX_Control(pDX, IDC_COMBO13, m_note1_4);
	DDX_Control(pDX, IDC_COMBO14, m_note1_5);
	DDX_Control(pDX, IDC_COMBO15, m_note1_6);
	DDX_Control(pDX, IDC_COMBO16, m_note1_7);
	DDX_Control(pDX, IDC_COMBO17, m_note2_0);
	DDX_Control(pDX, IDC_COMBO18, m_note2_1);
	DDX_Control(pDX, IDC_COMBO19, m_note2_2);
	DDX_Control(pDX, IDC_COMBO20, m_note2_3);
	DDX_Control(pDX, IDC_COMBO21, m_note2_4);
	DDX_Control(pDX, IDC_COMBO22, m_note2_5);
	DDX_Control(pDX, IDC_COMBO23, m_note2_6);
	DDX_Control(pDX, IDC_COMBO24, m_note2_7);
	DDX_Control(pDX, IDC_COMBO25, m_note3_0);
	DDX_Control(pDX, IDC_COMBO26, m_note3_1);
	DDX_Control(pDX, IDC_COMBO27, m_note3_2);
	DDX_Control(pDX, IDC_COMBO28, m_note3_3);
	DDX_Control(pDX, IDC_COMBO29, m_note3_4);
	DDX_Control(pDX, IDC_COMBO30, m_note3_5);
	DDX_Control(pDX, IDC_COMBO31, m_note3_6);
	DDX_Control(pDX, IDC_COMBO32, m_note3_7);
	DDX_Control(pDX, IDC_COMBO33, m_note5_0);
	DDX_Control(pDX, IDC_COMBO34, m_note5_1);
	DDX_Control(pDX, IDC_COMBO35, m_note5_2);
	DDX_Control(pDX, IDC_COMBO36, m_note5_3);
	DDX_Control(pDX, IDC_COMBO37, m_note5_4);
	DDX_Control(pDX, IDC_COMBO38, m_note5_5);
	DDX_Control(pDX, IDC_COMBO39, m_note5_6);
	DDX_Control(pDX, IDC_COMBO40, m_note5_7);
	DDX_Control(pDX, IDC_COMBO41, m_note4_0);
	DDX_Control(pDX, IDC_COMBO42, m_note4_1);
	DDX_Control(pDX, IDC_COMBO43, m_note4_2);
	DDX_Control(pDX, IDC_COMBO44, m_note4_3);
	DDX_Control(pDX, IDC_COMBO45, m_note4_4);
	DDX_Control(pDX, IDC_COMBO46, m_note4_5);
	DDX_Control(pDX, IDC_COMBO47, m_note4_6);
	DDX_Control(pDX, IDC_COMBO48, m_note4_7);
	DDX_Control(pDX, IDC_COMBO49, m_note6_0);
	DDX_Control(pDX, IDC_COMBO50, m_note6_1);
	DDX_Control(pDX, IDC_COMBO51, m_note6_2);
	DDX_Control(pDX, IDC_COMBO52, m_note6_3);
	DDX_Control(pDX, IDC_COMBO53, m_note6_4);
	DDX_Control(pDX, IDC_COMBO54, m_note6_5);
	DDX_Control(pDX, IDC_COMBO55, m_note6_6);
	DDX_Control(pDX, IDC_COMBO56, m_note6_7);
	DDX_Control(pDX, IDC_COMBO57, m_note7_0);
	DDX_Control(pDX, IDC_COMBO58, m_note7_1);
	DDX_Control(pDX, IDC_COMBO59, m_note7_2);
	DDX_Control(pDX, IDC_COMBO60, m_note7_3);
	DDX_Control(pDX, IDC_COMBO61, m_note7_4);
	DDX_Control(pDX, IDC_COMBO62, m_note7_5);
	DDX_Control(pDX, IDC_COMBO63, m_note7_6);
	DDX_Control(pDX, IDC_COMBO64, m_note7_7);
	DDX_Text(pDX, IDC_EDIT1, m_depth);
	DDX_Text(pDX, IDC_EDIT2, m_pause);
	DDX_Control(pDX, IDC_COMBO65, m_stench);
	DDX_Control(pDX, IDC_COMBO66, m_harmrhytm);
}

BEGIN_MESSAGE_MAP(CMFCApplication4Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDM_ABOUTBOX, &CMFCApplication4Dlg::OnBnClickedAboutbox)
END_MESSAGE_MAP()


// Обработчики сообщений CMFCApplication4Dlg

BOOL CMFCApplication4Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CMFCApplication4Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CMFCApplication4Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CMFCApplication4Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}






void CMFCApplication4Dlg::OnBnClickedAboutbox()
{
	// Примечание: в программе имеется озможность выбра кол-ва аккордов в 1 такте(1 или 2).
	// В 1-м случае программа рассматривает 8 тактов по 4 четвртные ноты.
	//Для каждого из них подбираются варианты гармонизации(согласованные с другими введенными параметрами: рассматриваемыми акцентированными звуками, допустимыми диссонансами, скоростью их разрешения)
	// Во 2-м случае мелодия будет условно делиться программой на 16 тактов - каждый из 2х четвертных нот.
	//И тогда для каждого из условных "тактов" будет выполняться стандартный алгоритм подбора аккордов.


	vector<bar> MELODY; //Мелодия, вводимая пользователем
	vector<chord> variants[16]; //Аккорды к каждому такту(или половине такта - в зависимости от выбора пользователя)
	unsigned int M; //Кол-во условных "тактов", рассматриваемых программой
	

	

	unsigned int depth; //Расстояние между акцентированнымизвуками(вводится пользователем)
	unsigned int pause; //Расстояние между потенциально диссонантным звуком и его разрешением(вводится пользователем)
	stench reek; //Уровень диссонантности интервалов между аккордовыми звуками и звуками мелодии(вводится пользователем)
	unsigned int harmonic_rhytm; //Кол-во аккордов в каждом такте(вводится пользователем)

	UpdateData(TRUE);

	//Считывание этих параметров:
	depth = (m_depth>0)? m_depth : 1;
	pause = (m_pause > 0) ? m_pause : 1;
	reek = (m_stench.GetCurSel() > 0)? static_cast<stench>(m_stench.GetCurSel()) : chord_tones;
	harmonic_rhytm = (m_harmrhytm.GetCurSel() >= 0) ? m_harmrhytm.GetCurSel()+1 : 1;



	//Создание и считывание 8(или 16) условных "тактов", в зависимости от кол-ва аккордов в каждом настоящем такте:
	if (harmonic_rhytm == 1)
	{
		M = 8;
		for (unsigned int i = 0; i < M; i++) { MELODY.push_back(bar(4)); }

		MELODY[0].set_note(0, option_to_note(m_note0_0.GetCurSel()));
		MELODY[0].set_note(1, option_to_note(m_note0_1.GetCurSel()));
		MELODY[0].set_note(2, option_to_note(m_note0_2.GetCurSel()));
		MELODY[0].set_note(3, option_to_note(m_note0_3.GetCurSel()));
		MELODY[0].set_note(4, option_to_note(m_note0_4.GetCurSel()));
		MELODY[0].set_note(5, option_to_note(m_note0_5.GetCurSel()));
		MELODY[0].set_note(6, option_to_note(m_note0_6.GetCurSel()));
		MELODY[0].set_note(7, option_to_note(m_note0_7.GetCurSel()));

		MELODY[1].set_note(0, option_to_note(m_note1_0.GetCurSel()));
		MELODY[1].set_note(1, option_to_note(m_note1_1.GetCurSel()));
		MELODY[1].set_note(2, option_to_note(m_note1_2.GetCurSel()));
		MELODY[1].set_note(3, option_to_note(m_note1_3.GetCurSel()));
		MELODY[1].set_note(4, option_to_note(m_note1_4.GetCurSel()));
		MELODY[1].set_note(5, option_to_note(m_note1_5.GetCurSel()));
		MELODY[1].set_note(6, option_to_note(m_note1_6.GetCurSel()));
		MELODY[1].set_note(7, option_to_note(m_note1_7.GetCurSel()));

		MELODY[2].set_note(0, option_to_note(m_note2_0.GetCurSel()));
		MELODY[2].set_note(1, option_to_note(m_note2_1.GetCurSel()));
		MELODY[2].set_note(2, option_to_note(m_note2_2.GetCurSel()));
		MELODY[2].set_note(3, option_to_note(m_note2_3.GetCurSel()));
		MELODY[2].set_note(4, option_to_note(m_note2_4.GetCurSel()));
		MELODY[2].set_note(5, option_to_note(m_note2_5.GetCurSel()));
		MELODY[2].set_note(6, option_to_note(m_note2_6.GetCurSel()));
		MELODY[2].set_note(7, option_to_note(m_note2_7.GetCurSel()));

		MELODY[3].set_note(0, option_to_note(m_note3_0.GetCurSel()));
		MELODY[3].set_note(1, option_to_note(m_note3_1.GetCurSel()));
		MELODY[3].set_note(2, option_to_note(m_note3_2.GetCurSel()));
		MELODY[3].set_note(3, option_to_note(m_note3_3.GetCurSel()));
		MELODY[3].set_note(4, option_to_note(m_note3_4.GetCurSel()));
		MELODY[3].set_note(5, option_to_note(m_note3_5.GetCurSel()));
		MELODY[3].set_note(6, option_to_note(m_note3_6.GetCurSel()));
		MELODY[3].set_note(7, option_to_note(m_note3_7.GetCurSel()));

		MELODY[4].set_note(0, option_to_note(m_note4_0.GetCurSel()));
		MELODY[4].set_note(1, option_to_note(m_note4_1.GetCurSel()));
		MELODY[4].set_note(2, option_to_note(m_note4_2.GetCurSel()));
		MELODY[4].set_note(3, option_to_note(m_note4_3.GetCurSel()));
		MELODY[4].set_note(4, option_to_note(m_note4_4.GetCurSel()));
		MELODY[4].set_note(5, option_to_note(m_note4_5.GetCurSel()));
		MELODY[4].set_note(6, option_to_note(m_note4_6.GetCurSel()));
		MELODY[4].set_note(7, option_to_note(m_note4_7.GetCurSel()));

		MELODY[5].set_note(0, option_to_note(m_note5_0.GetCurSel()));
		MELODY[5].set_note(1, option_to_note(m_note5_1.GetCurSel()));
		MELODY[5].set_note(2, option_to_note(m_note5_2.GetCurSel()));
		MELODY[5].set_note(3, option_to_note(m_note5_3.GetCurSel()));
		MELODY[5].set_note(4, option_to_note(m_note5_4.GetCurSel()));
		MELODY[5].set_note(5, option_to_note(m_note5_5.GetCurSel()));
		MELODY[5].set_note(6, option_to_note(m_note5_6.GetCurSel()));
		MELODY[5].set_note(7, option_to_note(m_note5_7.GetCurSel()));

		MELODY[6].set_note(0, option_to_note(m_note6_0.GetCurSel()));
		MELODY[6].set_note(1, option_to_note(m_note6_1.GetCurSel()));
		MELODY[6].set_note(2, option_to_note(m_note6_2.GetCurSel()));
		MELODY[6].set_note(3, option_to_note(m_note6_3.GetCurSel()));
		MELODY[6].set_note(4, option_to_note(m_note6_4.GetCurSel()));
		MELODY[6].set_note(5, option_to_note(m_note6_5.GetCurSel()));
		MELODY[6].set_note(6, option_to_note(m_note6_6.GetCurSel()));
		MELODY[6].set_note(7, option_to_note(m_note6_7.GetCurSel()));

		MELODY[7].set_note(0, option_to_note(m_note7_0.GetCurSel()));
		MELODY[7].set_note(1, option_to_note(m_note7_1.GetCurSel()));
		MELODY[7].set_note(2, option_to_note(m_note7_2.GetCurSel()));
		MELODY[7].set_note(3, option_to_note(m_note7_3.GetCurSel()));
		MELODY[7].set_note(4, option_to_note(m_note7_4.GetCurSel()));
		MELODY[7].set_note(5, option_to_note(m_note7_5.GetCurSel()));
		MELODY[7].set_note(6, option_to_note(m_note7_6.GetCurSel()));
		MELODY[7].set_note(7, option_to_note(m_note7_7.GetCurSel()));
	}
	else
	{
		M = 16;
		for (unsigned int i = 0; i < M; i++) { MELODY.push_back(bar(2)); }

		MELODY[0].set_note(0, option_to_note(m_note0_0.GetCurSel()));
		MELODY[0].set_note(1, option_to_note(m_note0_1.GetCurSel()));
		MELODY[0].set_note(2, option_to_note(m_note0_2.GetCurSel()));
		MELODY[0].set_note(3, option_to_note(m_note0_3.GetCurSel()));

		MELODY[1].set_note(0, option_to_note(m_note0_4.GetCurSel()));
		MELODY[1].set_note(1, option_to_note(m_note0_5.GetCurSel()));
		MELODY[1].set_note(2, option_to_note(m_note0_6.GetCurSel()));
		MELODY[1].set_note(3, option_to_note(m_note0_7.GetCurSel()));



		MELODY[2].set_note(0, option_to_note(m_note1_0.GetCurSel()));
		MELODY[2].set_note(1, option_to_note(m_note1_1.GetCurSel()));
		MELODY[2].set_note(2, option_to_note(m_note1_2.GetCurSel()));
		MELODY[2].set_note(3, option_to_note(m_note1_3.GetCurSel()));
		
		MELODY[3].set_note(0, option_to_note(m_note1_4.GetCurSel()));
		MELODY[3].set_note(1, option_to_note(m_note1_5.GetCurSel()));
		MELODY[3].set_note(2, option_to_note(m_note1_6.GetCurSel()));
		MELODY[3].set_note(3, option_to_note(m_note1_7.GetCurSel()));

		
		
		MELODY[4].set_note(0, option_to_note(m_note2_0.GetCurSel()));
		MELODY[4].set_note(1, option_to_note(m_note2_1.GetCurSel()));
		MELODY[4].set_note(2, option_to_note(m_note2_2.GetCurSel()));
		MELODY[4].set_note(3, option_to_note(m_note2_3.GetCurSel()));
		
		MELODY[5].set_note(0, option_to_note(m_note2_4.GetCurSel()));
		MELODY[5].set_note(1, option_to_note(m_note2_5.GetCurSel()));
		MELODY[5].set_note(2, option_to_note(m_note2_6.GetCurSel()));
		MELODY[5].set_note(3, option_to_note(m_note2_7.GetCurSel()));

		
		
		MELODY[6].set_note(0, option_to_note(m_note3_0.GetCurSel()));
		MELODY[6].set_note(1, option_to_note(m_note3_1.GetCurSel()));
		MELODY[6].set_note(2, option_to_note(m_note3_2.GetCurSel()));
		MELODY[6].set_note(3, option_to_note(m_note3_3.GetCurSel()));
		
		MELODY[7].set_note(0, option_to_note(m_note3_4.GetCurSel()));
		MELODY[7].set_note(1, option_to_note(m_note3_5.GetCurSel()));
		MELODY[7].set_note(2, option_to_note(m_note3_6.GetCurSel()));
		MELODY[7].set_note(3, option_to_note(m_note3_7.GetCurSel()));

		
		
		MELODY[8].set_note(0, option_to_note(m_note4_0.GetCurSel()));
		MELODY[8].set_note(1, option_to_note(m_note4_1.GetCurSel()));
		MELODY[8].set_note(2, option_to_note(m_note4_2.GetCurSel()));
		MELODY[8].set_note(3, option_to_note(m_note4_3.GetCurSel()));
		
		MELODY[9].set_note(0, option_to_note(m_note4_4.GetCurSel()));
		MELODY[9].set_note(1, option_to_note(m_note4_5.GetCurSel()));
		MELODY[9].set_note(2, option_to_note(m_note4_6.GetCurSel()));
		MELODY[9].set_note(3, option_to_note(m_note4_7.GetCurSel()));

		
		
		MELODY[10].set_note(0, option_to_note(m_note5_0.GetCurSel()));
		MELODY[10].set_note(1, option_to_note(m_note5_1.GetCurSel()));
		MELODY[10].set_note(2, option_to_note(m_note5_2.GetCurSel()));
		MELODY[10].set_note(3, option_to_note(m_note5_3.GetCurSel()));
		
		MELODY[11].set_note(0, option_to_note(m_note5_4.GetCurSel()));
		MELODY[11].set_note(1, option_to_note(m_note5_5.GetCurSel()));
		MELODY[11].set_note(2, option_to_note(m_note5_6.GetCurSel()));
		MELODY[11].set_note(3, option_to_note(m_note5_7.GetCurSel()));

		
		
		MELODY[12].set_note(0, option_to_note(m_note6_0.GetCurSel()));
		MELODY[12].set_note(1, option_to_note(m_note6_1.GetCurSel()));
		MELODY[12].set_note(2, option_to_note(m_note6_2.GetCurSel()));
		MELODY[12].set_note(3, option_to_note(m_note6_3.GetCurSel()));
		
		MELODY[13].set_note(0, option_to_note(m_note6_4.GetCurSel()));
		MELODY[13].set_note(1, option_to_note(m_note6_5.GetCurSel()));
		MELODY[13].set_note(2, option_to_note(m_note6_6.GetCurSel()));
		MELODY[13].set_note(3, option_to_note(m_note6_7.GetCurSel()));

		
		
		MELODY[14].set_note(0, option_to_note(m_note7_0.GetCurSel()));
		MELODY[14].set_note(1, option_to_note(m_note7_1.GetCurSel()));
		MELODY[14].set_note(2, option_to_note(m_note7_2.GetCurSel()));
		MELODY[14].set_note(3, option_to_note(m_note7_3.GetCurSel()));
		
		MELODY[15].set_note(0, option_to_note(m_note7_4.GetCurSel()));
		MELODY[15].set_note(1, option_to_note(m_note7_5.GetCurSel()));
		MELODY[15].set_note(2, option_to_note(m_note7_6.GetCurSel()));
		MELODY[15].set_note(3, option_to_note(m_note7_7.GetCurSel()));
	}


	
	CString out; //Выводимая на экран информация
	CString add; //Всмпомогательная переменная


	//Процедура подбора аккордов к каждому условному "такту" мелодии,
	//а также форматирование выводимой на экран информации:
	if (harmonic_rhytm == 1)
	{
		for (unsigned int i = 0; i < M; i++)
		{
			variants[i] = posibilities(MELODY[i], reek, depth, pause);

			add.Format(_T("%i такт:   "), i + 1);
			for (unsigned int j = 0; j < variants[i].size(); j++)
			{
				add += chord_to_cstring(variants[i][j]) + _T(" ");
			}
			add += _T("\n\n\n\n");

			out += add;
		}
	}
	else
	{
		for (unsigned int i = 0; i < M; i++)
		{
			variants[i] = posibilities(MELODY[i], reek, depth, pause);

			if (i % 2 == 0) { add.Format(_T("%i такт(1 половина):   "), (i/2) + 1); }
			else { add.Format(_T("%i такт(2 половина):   "), (i/2) + 1); }
			for (unsigned int j = 0; j < variants[i].size(); j++)
			{
				add += chord_to_cstring(variants[i][j]) + _T(" ");
			}
			add += _T("\n\n"); if (i % 2 == 1) { add += _T("\n"); }

			out += add;
		}
	}




	//Вывод информации на экран(во всплывающем окне):
	MessageBox(out);
}
