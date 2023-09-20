#include <iostream>
#include <string>
#include <thread>
#include "Logger.h"


int main() {
    // We shall log variables of different types
    int x = 105;
    std::string slr("Hello");
    double y = 10.01;
    char ch = '#';

    // Set current log level to log all types of messages
    SETLOGLEVEL(LOGALL);
    LOG(LOGINFO, "Current LogLevel", static_cast<int>(LOGALL));
    
    // Create a separate thread that also logs different messages.
    std::thread t1([&](){
        int i = 0;
        while(i < 100){
            LOG(LOGINFO, "This is an INFO message with different types of variable: int =", x, "double =", y, "string =",slr, "char =",ch);
            LOG(LOGERROR, "This is an ERROR message.");
            ++i;
        }    
    });
    
    int j = 0;
    while(j < 100){
        if (j==50){ 
            // Change the log level - This change will reflect in other threads as well
            SETLOGLEVEL(LOGINFO);
            LOG(LOGINFO, "LogLevel changed to", static_cast<int>(LOGTRACE));
        }
        LOG(LOGDEBUG, "This is a DEBUG message.");
        LOG(LOGTRACE, "This is a TRACE  message.");
        LOG(LOGALL, "This is a ALL type message");
        ++j;
    }
    t1.join();

    return 0;
}
