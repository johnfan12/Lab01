
// Traffic_lights_objectDlg.h: 头文件
//

#pragma once


// CTrafficlightsobjectDlg 对话框
class CTrafficlightsobjectDlg : public CDialogEx
{
// 构造
public:
	CTrafficlightsobjectDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TRAFFIC_LIGHTS_OBJECT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	float size;
	float mid_x;
	float mid_y;
	int red_time;
	int yellow_time;
	int green_time;
};
