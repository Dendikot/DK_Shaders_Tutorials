#pragma once

#include <Windows.h>  // Include this in the header file for HWND

class Window
{
public:
	Window(int width, int height);
	HWND Get_Handle() const;
private:
	HWND m_handle;
};