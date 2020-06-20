#include "processor.h"
#include "helpers.h"
#include <string>
#include "linux_parser.h"
// TODO: Return the aggregate CPU utilization
// Step 1: cat /proc/stat
// cpu  3367036 7215 802659 5427731 10120 0 52018 0 0 0 <-- total, we just need this. The numbers are jiffies (clock ticks)
// Add up the number of jiffies / total time (total jiffies)
// cpu0 862855 843 193408 5279550 9707 0 11051 0 0 0
// cpu1 837418 2321 195787 49592 148 0 9691 0 0 0
// cpu2 833134 2242 215790 49226 145 0 15379 0 0 0
//
float Processor::Utilization() {
    //TODO: parse the first line. 
    std::vector<std::string> s_utilisation = LinuxParser::CpuUtilization();
    float  usertime= stof(s_utilisation[0]);
    float  nicetime=stof(s_utilisation[1]);
    float  systemtime=stof(s_utilisation[2]);
    float  idletime=stof(s_utilisation[3]);
    float  ioWait=stof(s_utilisation[4]);
    float  irq=stof(s_utilisation[5]);
    float  softIrq=stof(s_utilisation[6]);
    float  steal=stof(s_utilisation[7]);
    float  guest=stof(s_utilisation[8]);
    float  guestnice=stof(s_utilisation[9]);

    float Total,Idle,NonIdle; 
    Idle = idletime + ioWait;
    NonIdle = usertime + nicetime + systemtime + irq + softIrq + steal;
    Total = Idle + NonIdle;
    return  (Total - Idle)/Total;
    }