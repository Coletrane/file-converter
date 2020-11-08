#pragma once

#include <JuceHeader.h>
#include <string>
#include <sstream>
#include <vector>

class MainComponent : public juce::Component {
public:
    static const std::vector<std::string> SUPPORTED_FILE_TYPES;

    static std::string getFileTypeStr();

    MainComponent();

    ~MainComponent() override;

    void paint(juce::Graphics &) override;

    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)

    juce::TextButton openButton;

    juce::FileChooser fileChooser;

    void openButtonClicked();
};
