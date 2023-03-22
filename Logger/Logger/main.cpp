#include<iostream>
#include "Logger.h"
using namespace std;
using namespace nLogging;

int main()
{
    Logger* loggerObj = Logger::getInstance();
    loggerObj->setLogLevel(eLogTypes::eALL);

    string str1 = "Something is not right. Reboot your computer...";
    string str2 = "Your computer is running fine...";
    string str3 = "Your battery adapter is not compatible...";
    string str4 = "Your battery wattage is 65Wh. Required limit is 40Wh";
    string str5 = "Your computer's user name is Robinhood!!";

    loggerObj->setLogLevel(eLogTypes::eDEBUG);
    loggerObj->logMsg(eLogTypes::eERROR, str1);
    loggerObj->logMsg(eLogTypes::eINFO, str2);
    loggerObj->logMsg(eLogTypes::eDEBUG, str3);
    loggerObj->logMsg(eLogTypes::eTRACE, str4);
    loggerObj->logMsg(eLogTypes::eALL, str5);

    loggerObj->logMsg(eLogTypes::eERROR, "Cannot reboot your machine...");
    loggerObj->logMsg(eLogTypes::eINFO, "Your computer's virus free");
    loggerObj->logMsg(eLogTypes::eDEBUG, "memory cache corrupted...");
    loggerObj->logMsg(eLogTypes::eTRACE, "Data layer : Service Layer communication failure");
    loggerObj->logMsg(eLogTypes::eALL, "Ideas are bulletproof!!");
	return 0;
}