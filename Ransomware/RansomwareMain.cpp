#include "RansomwareMain.h"


RansomwareMain::RansomwareMain() : wxFrame(nullptr,wxID_ANY,"Ransomware",wxPoint(100,100),wxSize(1050,600)) {
	// Form properties
	SetBackgroundColour(*wxRED);


	// Main text constructor
	application_text1 = new wxStaticText(this, wxID_ANY, "Your files have been encrypted :(", wxPoint(150, 10), wxSize(150,50),wxALIGN_CENTRE_HORIZONTAL);
	
	// Main text Style
	application_text1->SetFont(bigFont);
	application_text1->SetForegroundColour(wxColor("#000000"));

	// Paragraph text constructor
	application_text2 = new wxStaticText(this, wxID_ANY, " In order to decrypt your files you need to (1) visit www.ransomware-payment.com \n (2) enter id 259275290 (3) make payment then (4) press the button below in order \n to check it", wxPoint(10, 50), wxSize(200, 150));
	application_text2->SetFont(paragraphFont);
	application_text2->SetForegroundColour(wxColor("#000000"));




	// Button constructors
	application_button1 = new wxButton(this, wxID_ANY, "Check payment", wxPoint(450, 450), wxSize(150, 75));
	application_button1->SetForegroundColour(wxColor("#000000"));



	
}

RansomwareMain::~RansomwareMain() {

}