#include "BasicSettingsPanel.h"

BasicSettingsPanel::BasicSettingsPanel(wxWindow* parent) : wxPanel(parent) {
    wxWindowBase::SetBackgroundColour("#282b30");

    // Create a StaticText label for the slider
    wxStaticText* thresholdLabel = new wxStaticText(this, wxID_ANY, "Threshold", wxPoint(30, 30));
    thresholdLabel->SetForegroundColour("#bfbfbf");
    thresholdLabel->SetFont(wxFont(16, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    
    wxSlider* thresholdSlider = new wxSlider(this, wxID_ANY, 127, 0, 255, wxPoint(30, 60), wxSize(200, -1));
    
    thresholdSlider->Bind(wxEVT_SCROLL_THUMBTRACK, &BasicSettingsPanel::OnThresholdSliderChange, this);
}

void BasicSettingsPanel::OnThresholdSliderChange(wxScrollEvent& e) {
    viewport_->SetThreshold(static_cast<float>(e.GetPosition()) / static_cast<float>(255.0));
    
}