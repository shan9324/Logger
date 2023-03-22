#pragma once
#ifndef _LOGGER_H_
#define _LOGGER_H_
#include <iostream>
#include <string>

enum class eLogTypes : std::uint32_t {
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

    private:
        static Logger* m_loggerObj;
        eLogTypes m_iLogLevel = eLogTypes::eERROR;
        Logger() {}
        Logger(const Logger& loggerObj) {}
        void operator=(const Logger& loggerObj) {}
        
        //Private Methods - To be called from within the class only
        void error(const char* text);
        void error(std::string str);
        void info(const char* text);
        void info(std::string str);
        void debug(const char* text);
        void debug(std::string str);
        void trace(const char* text);
        void trace(std::string str);
        void all(const char* text);
        void all(std::string str);
    public:
        static Logger* getInstance();
        void logMsg(eLogTypes eLogType, const char* text);
        void logMsg(eLogTypes eLogType, std::string str);
        void setLogLevel(eLogTypes eLogLevel);
    };
}

#endif

