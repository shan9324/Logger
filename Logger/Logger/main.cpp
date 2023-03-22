#include<iostream>
#include "Logger.h"
using namespace std;
using namespace nLogging;

int main()
{
    Logger* loggerObj = Logger::getInstance();
    loggerObj->setLogLevel(eALL);

    string str1 = "Something is not right. Reboot your computer...";
    string str2 = "Your computer is running fine...";
    string str3 = "Your battery adapter is not compatible...";
    string str4 = "Your battery wattage is 65Wh. Required limit is 40Wh";
    string str5 = "Your computer's user name is Robinhood!!";

    loggerObj->setLogLevel(eDEBUG);
    loggerObj->logMsg(eERROR, str1);
    loggerObj->logMsg(eINFO, str2);
    loggerObj->logMsg(eDEBUG, str3);
    loggerObj->logMsg(eTRACE, str4);
    loggerObj->logMsg(eALL, str5);

    loggerObj->logMsg(eERROR, "Cannot reboot your machine...");
    loggerObj->logMsg(eINFO, "Your computer's virus free");
    loggerObj->logMsg(eDEBUG, "memory cache corrupted...");
    loggerObj->logMsg(eTRACE, "Data layer : Service Layer communication failure");
    loggerObj->logMsg(eALL, "Ideas are bulletproof!!");
	return 0;
}