#include <string>
#include "helpers.h"
#include "format.h"

using std::string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) { 
    std::string shours,sminutes,sseconds;
    int ihours,iminutes,iseconds;
    double fhours,fminutes,fseconds;
    float remainder;
    ihours = seconds/3600;
    fhours = seconds/3600.0;
    remainder = fhours-ihours;
    iminutes = remainder*60;
    fminutes = remainder*60;
    remainder = fminutes-iminutes;
    iseconds = remainder*60;

    shours = std::to_string(ihours);
    sminutes = std::to_string(iminutes);
    sseconds = std::to_string(iseconds);

    return shours+":"+sminutes+":"+sseconds;

    }
    