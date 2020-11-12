#ifndef FILE_CONVERTER_FITFILELISTENER_H
#define FILE_CONVERTER_FITFILELISTENER_H

#include <fstream>
#include <iostream>

#include <JuceHeader.h>

#include <fitsdk/fit_user_profile_mesg_listener.hpp>
#include <fitsdk/fit_file_id_mesg_listener.hpp>
#include <fitsdk/fit_monitoring_mesg_listener.hpp>
#include <fitsdk/fit_device_info_mesg_listener.hpp>
#include <fitsdk/fit_mesg_listener.hpp>
#include <fitsdk/fit_developer_field_description_listener.hpp>
#include <fitsdk/fit_record_mesg_listener.hpp>

class FitFileListener
        : public fit::FileIdMesgListener,
          public fit::UserProfileMesgListener,
          public fit::MonitoringMesgListener,
          public fit::DeviceInfoMesgListener,
          public fit::MesgListener,
          public fit::DeveloperFieldDescriptionListener,
          public fit::RecordMesgListener {
public:
    static void printValues(const fit::FieldBase &field);

    double &progress;

    explicit FitFileListener(double &progress);
    ~FitFileListener() override;

    void OnDeveloperFieldDescription(const fit::DeveloperFieldDescription &desc) override;
    void OnMesg(fit::DeviceInfoMesg &mesg) override;
    void OnMesg(fit::FileIdMesg &mesg) override;
    void OnMesg(fit::Mesg &mesg) override;
    void OnMesg(fit::MonitoringMesg &mesg) override;
    void OnMesg(fit::RecordMesg &mesg) override;
    void OnMesg(fit::UserProfileMesg &mesg) override;
};


#endif //FILE_CONVERTER_FITFILELISTENER_H
