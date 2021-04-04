#pragma once
#include "wx/wx.h"


class RansomwareMain : public wxFrame
{
public:
	RansomwareMain();
	~RansomwareMain();

public:
	wxStaticText* application_text1 = nullptr;
	wxFont bigFont = wxFont(30, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);

	wxStaticText* application_text2 = nullptr;
	wxFont paragraphFont = wxFont(15,wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);

	


	wxButton* application_button1 = nullptr;
};

