#include "MainComponent.h"

const std::vector<std::string> MainComponent::SUPPORTED_FILE_TYPES = {
        "fit"
};


std::string MainComponent::getFileTypeStr() {
    std::stringstream ss;
    for (const auto &i : SUPPORTED_FILE_TYPES) {
        ss << "*." << i << ";";
    }
    return ss.str();
}

MainComponent::MainComponent() :
        fileChooser("Choose a File", {}, getFileTypeStr(), true, true, this) {
    setOpaque(true);

    addAndMakeVisible(&openButton);
    std::stringstream ss;
    ss << "Open a " << getFileTypeStr() << " file.";
    openButton.setButtonText(ss.str());
    openButton.onClick = [this] { openButtonClicked(); };

    lookAndFeelChanged();
    setSize(600, 400);
}

MainComponent::~MainComponent() {
}

void MainComponent::paint(juce::Graphics &g) {
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));
}

void MainComponent::resized() {
    openButton.setBounds(10, 10, getWidth() - 20, 30);
}

void MainComponent::openButtonClicked() {
    if (fileChooser.browseForFileToOpen()) {
        auto file = fileChooser.getResult();
        // TODO: read the file data here
    }
}
