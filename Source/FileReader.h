#ifndef FILE_CONVERTER_FILEREADER_H
#define FILE_CONVERTER_FILEREADER_H

#include <string>
#include <fstream>
#include <iostream>
#include <streambuf>

#include <JuceHeader.h>

#include <fitsdk/fit_decode.hpp>
#include <fitsdk/fit_mesg_broadcaster.hpp>
#include "FitFileListener.h"


class FileReader {
public:
    void readFileUsingJuceStream(juce::File file);

    void readFileUsingFileNameAndIfstream(juce::File file);

private:
    fit::MesgBroadcaster mesgBroadcaster;
    fit::Decode decode;
    FitFileListener listener;
};


#endif //FILE_CONVERTER_FILEREADER_H
