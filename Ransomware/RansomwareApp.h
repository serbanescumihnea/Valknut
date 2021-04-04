#pragma once

#include <wx/wx.h>
#include "RansomwareMain.h"
#include "EncryptionEngine.h"

class RansomwareApp : public wxApp
{
public:
	RansomwareApp();
	~RansomwareApp();

private:
	RansomwareMain* application_frame1 = nullptr;

public:
	virtual bool OnInit();
};