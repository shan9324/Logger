#pragma once
#ifndef _LOGGER_H_
#define _LOGGER_H_

#include <iostream>
#include <string>
#define logMessage(x, y) Logger::getInstance()->logMsg(x, y)
using namespace std;

enum eLogTypes {
    eERROR = 0,
    eINFO,
    eDEBUG,
    eTRACE,
    eALL
};

namespace nLogging
{
    class Logger
    {
        static Logger* m_loggerObj;
        eLogTypes m_iLogLevel = eERROR;
        Logger() {}
        Logger(const Logger& loggerObj) {}
        void operator=(const Logger& loggerObj) {}

    public:
        static Logger* getInstance();
        void getSuccessMsg();
        void error(const char* text);
        void error(string str);
        void info(const char* text);
        void info(string str);
        void debug(const char* text);
        void debug(string str);
        void trace(const char* text);
        void trace(string str);
        void all(const char* text);
        void all(string str);
        void logMsg(eLogTypes eLogType, const char* text);
        void logMsg(eLogTypes eLogType, string str);
        void setLogLevel(eLogTypes eLogLevel);
    };
}

#endif

