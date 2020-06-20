#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "process.h"
#include "linux_parser.h"
#include "helpers.h"
using std::string;
using std::to_string;
using std::vector;


// Constructor 
Process::Process(int pid){

    pid_ = pid; 
    uid_ = LinuxParser::Uid(pid_);
    user_ = LinuxParser::User(uid_);
    command_ = LinuxParser::Command(pid);
    ram_ = LinuxParser::Ram(pid);    
    uptime_ = LinuxParser::UpTime(pid);
    cpuUtil_ = LinuxParser::CpuUtilization(pid);

}
// TODO: Return this process's ID
int Process::Pid() { 
    // pids =  LinuxParser::Pids(); 
    return pid_;
    }

// TODO: Return this process's CPU utilization
float Process::CpuUtilization() const{ 
    // Print("HELLO");
    // Print(LinuxParser::CpuUtilization(pid_));
    
    return LinuxParser::CpuUtilization(pid_);
    }

// TODO: Return the command that generated this process
string Process::Command() { 
    return LinuxParser::Command(pid_); 
    }

// TODO: Return this process's memory utilization
string Process::Ram() {
    // For processes that use no ram. 
    ram_ = LinuxParser::Ram(pid_);
    if(ram_ == "") ram_ = "0.0";
    float ram_MB_ = std::stof(ram_);
    ram_MB_ /= 1000;
    return std::to_string(ram_MB_);
    
}

// TODO: Return the user (name) that generated this process
string Process::User() { 
    return LinuxParser::User(uid_);
}


// TODO: Return the age of this process (in seconds)
long int Process::UpTime() { return LinuxParser::UpTime(pid_); }

// TODO: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(Process const& a) const { 
    return CpuUtilization() < a.CpuUtilization();
    }