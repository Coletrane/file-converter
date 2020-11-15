#include <fstream>
#include "FileReader.h"


FileReader::FileReader(const FitFileListener& listener):
    listener(listener) { }

void FileReader::readFileUsingJuceStream(juce::File file) {
    juce::FileInputStream inputStream {file};
    if (inputStream.failedToOpen()) {
        return;
    }
//        while (! inputStream.isExhausted()) {
//            auto line = inputStream.readNextLine();
//            std::cout << line.toStdString();
//        }
    int fileSize = (int) file.getSize();
    juce::MemoryBlock buffer(fileSize);

//    std::ifstream inFileStream{};
//
//    int bytesRead = inputStream.read(&instream, fileSize);
//    std::cout << bytesRead;


    // FIXME: use streams only, I think this reads the whole file into memory?
//        auto* data = static_cast<char*> (buffer.getData());
//        size_t i = 0;
//
//        while ((data[i] = inputStream.readByte()) != 0 && i < buffer.getSize());
//
//        membuf memBuf(data, data + sizeof(data));



//
//        if (!decode.CheckIntegrity(fileBufPtr->)) {
//            int dddd = 3;
//        }
}

FIT_BOOL FileReader::readFileUsingFileNameAndIfstream(juce::File file) {
    std::string filePath { file.getFullPathName().toStdString() };
    std::fstream fileStream;

    fileStream.open(filePath, std::ios::in | std::ios::binary);
    if (!fileStream.is_open()) {
        std::cout << "Error opening file " << filePath << "\n";
    }

    mesgBroadcaster.AddListener((fit::FileIdMesgListener &)listener);
    mesgBroadcaster.AddListener((fit::UserProfileMesgListener &)listener);
    mesgBroadcaster.AddListener((fit::MonitoringMesgListener &)listener);
    mesgBroadcaster.AddListener((fit::DeviceInfoMesgListener &)listener);
    mesgBroadcaster.AddListener((fit::RecordMesgListener&)listener);
    mesgBroadcaster.AddListener((fit::MesgListener &)listener);

    try {
        return decode.Read(&fileStream, &mesgBroadcaster, &mesgBroadcaster, &listener);
    } catch (const fit::RuntimeException& e) {
        std::cout << "Exception decoding the file: " << e.what();
        return FIT_BOOL_FALSE;
    }
}
