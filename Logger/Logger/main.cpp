#include<iostream>
#include "Logger.h"
using namespace std;
using namespace nLogging;

int main()
{
    Logger* loggerObj = Logger::getInstance();
    loggerObj->setLogLevel(eALL);

    // logMessage(eERROR, "Something is not right. Reboot your computer...");
    // logMessage(eINFO, "Your computer is running fine...");
    // logMessage(eDEBUG, "Your battery adapter is not compatible...");
    // logMessage(eTRACE, "Your battery wattage is 65Wh. Required limit is 40Wh");
    // logMessage(eALL, "Your computer's user name is Robinhood!!");

    string str1 = "Something is not right. Reboot your computer...";
    string str2 = "Your computer is running fine...";
    string str3 = "Your battery adapter is not compatible...";
    string str4 = "Your battery wattage is 65Wh. Required limit is 40Wh";
    string str5 = "Your computer's user name is Robinhood!!";

    loggerObj->setLogLevel(eDEBUG);
    logMessage(eERROR, str1);
    logMessage(eINFO, str2);
    logMessage(eDEBUG, str3);
    logMessage(eTRACE, str4);
    logMessage(eALL, str5);
	return 0;
}