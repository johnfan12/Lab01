#include "pch.h"
#include "Traffic_light.h"

void Traffic_light::initialize()
{
	count = red_time;
	state = 1;
}

void Traffic_light::setsize(float a)
{
	size = a;
}

void Traffic_light::set_position(float x, float y)
{
	position_x = x;
	position_y = y;
}

void Traffic_light::set_time(int red, int yellow, int green)
{
	red_time = red;
	yellow_time = yellow;
	green_time = green;
}

void Traffic_light::show(CDC* dc)
{
	CBrush* oldbrush,mybrush, *brushA, brushB;
	CPen* oldpen, mypen;
	mypen.CreatePen(PS_SOLID, 5, RGB(0, 0, 0)); 
	oldpen = dc->SelectObject(&mypen);
	mybrush.CreateSolidBrush(RGB(0, 0, 0));
	oldbrush = dc->SelectObject(&mybrush);
	dc->Rectangle(position_x - size * 3 / 2, position_y - size / 2, position_x + size * 3 / 2, position_y + size / 2);
	

	CRect myRect;
	int nRadium = size * 2 / 5 ;//设定圆的半径
	// 根据当前的时间和状态，画出红绿黄三个灯
	if (state == 1) // 红灯亮
	{
		myRect.left = position_x - nRadium - size;
		myRect.top = position_y - nRadium;
		myRect.right = position_x + nRadium - size;
		myRect.bottom = position_y + nRadium;//根据圆心计算圆的范围
		brushB.CreateSolidBrush(RGB(255, 0, 0));
		brushA = dc->SelectObject(&brushB);
		dc->Ellipse(myRect);
	}
	else if (state == 2) // 黄灯亮
	{
		myRect.left = position_x - nRadium;
		myRect.top = position_y - nRadium;
		myRect.right = position_x + nRadium;
		myRect.bottom = position_y + nRadium;//根据圆心计算圆的范围
		brushB.CreateSolidBrush(RGB(255, 255, 0));
		brushA = dc->SelectObject(&brushB);
		dc->Ellipse(myRect);
	}
	else if (state == 3)// 绿灯亮
	{
		myRect.left = position_x - nRadium + size;
		myRect.top = position_y - nRadium;
		myRect.right = position_x + nRadium + size;
		myRect.bottom = position_y + nRadium;//根据圆心计算圆的范围
		brushB.CreateSolidBrush(RGB(0, 255, 0));
		brushA = dc->SelectObject(&brushB);
		dc->Ellipse(myRect);
	}

}

void Traffic_light::counter(CDC* pDC)
{
	CString strCoord;
	strCoord.Format(_T("(%d)"), count--);
	pDC->TextOut(position_x, position_y - size, strCoord);
	if (count == 0 && state == 1)
	{
		state = 2;
		count = yellow_time;
	}
	if (count == 0 && state == 2)
	{
		state = 3;
		count = green_time;
	}
	if (count == 0 && state == 3)
	{
		state = 1;
		count = red_time;
	}

}
