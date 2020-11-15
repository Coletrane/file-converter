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
        progress(0),
        progressBar(progress),
        fileChooser("Choose a File", {}, getFileTypeStr(), true, true, this) {
    setOpaque(true);

    addAndMakeVisible(openButton);
    std::stringstream ss;
    ss << "Open a " << getFileTypeStr() << " file.";
    openButton.setButtonText(ss.str());
    openButton.onClick = [this] { openButtonClicked(); };

    lookAndFeelChanged();
    setSize(600, 400);
}

MainComponent::~MainComponent() = default;

void MainComponent::paint(juce::Graphics &g) {
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));
}

void MainComponent::resized() {
    openButton.setBounds(10, getHeight() - 40, getWidth() - 20, 30);
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

        // TODO: get this working
//        fileReader.readFileUsingJuceStream(file);

        std::stringstream filePathStream;
        filePathStream << file.getFullPathName() << file.getFileNameWithoutExtension() << ".csv";
        CsvWriter csvWriter(filePathStream.str());
        FitFileListener listener(progress, csvWriter);
        FileReader fileReader(listener);
        FIT_BOOL successfulRead = fileReader.readFileUsingFileNameAndIfstream(file);

        if (successfulRead) {
           renderProgressBar();
        }
    }
}

void MainComponent::renderProgressBar() {
    progressBar.setPercentageDisplay(true);
    addAndMakeVisible(progressBar);
    const int progressBarX = static_cast<int>(std::round(getHeight() / 2)) + 20;
    progressBar.setBounds(10, progressBarX, getWidth() - 20, 30);
}




