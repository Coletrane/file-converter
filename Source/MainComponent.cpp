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
        // writing types instead of using auto just to get the hang of things
        // using list initialization to prevent type conversion weirdness
        // https://stackoverflow.com/questions/18222926/why-is-list-initialization-using-curly-braces-better-than-the-alternatives
        juce::File file { fileChooser.getResult() };
        if (!file.existsAsFile()) {
            return;
        }

        fileReader.readFileUsingFileNameAndIfstream(file);
        // TODO: get this working
        fileReader.readFileUsingJuceStream(file);
    }
}

