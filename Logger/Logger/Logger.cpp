#include <iostream>
#include "Logger.h"
using namespace nLogging;


//Logger* Logger::m_loggerObj = NULL;
std::shared_ptr<Logger> Logger::m_loggerObj = nullptr;
std::once_flag Logger::initFlag;
//Logger* Logger::getInstance()
Logger& Logger::getInstance()
{
    std::call_once(initFlag, []() {
            m_loggerObj.reset(new Logger());
        }
    );

    return *m_loggerObj;
    /*if (!m_loggerObj)
    {
        m_loggerObj = new Logger;
    }

    if (m_loggerObj)
        std::cout << "Object Created Successfully" << std::endl;
    else
        std::cout << "Object NOT Created!!" << std::endl;
    
    return m_loggerObj;
    */
}

void Logger::error(const char* text)
{
    std::string str;
    str.append("[ERROR]: ");
    str.append(text);
    std::cout << str << std::endl;
}
void Logger::error(std::string str)
{
    error(str.data());
}
void Logger::info(const char* text)
{
    std::string str;
    str.append("[INFO]: ");
    str.append(text);
    std::cout << str << std::endl;
}
void Logger::info(std::string str)
{
    info(str.data());
}
void Logger::debug(const char* text)
{
    std::string str;
    str.append("[DEBUG]: ");
    str.append(text);
    std::cout << str << std::endl;
}
void Logger::debug(std::string str)
{
    debug(str.data());
}
void Logger::trace(const char* text)
{
    std::string str;
    str.append("[TRACE]: ");
    str.append(text);
    std::cout << str << std::endl;
}
void Logger::trace(std::string str)
{
    trace(str.data());
}
void Logger::all(const char* text)
{
    std::string str;
    str.append("[ALL]: ");
    str.append(text);
    std::cout << str << std::endl;
}
void Logger::all(std::string str)
{
    all(str.data());
}
void Logger::logMsg(eLogTypes eLogType, const char* text)
{
    switch (eLogType)
    {
    case eLogTypes::eERROR:
        if (m_iLogLevel >= eLogTypes::eERROR)
            error(text);
        else
            std::cout << "Can't print eERROR - Current Log Level = "<< static_cast<int>(this->m_iLogLevel) << std::endl;
        break;
    case eLogTypes::eINFO:
        if (m_iLogLevel >= eLogTypes::eINFO)
            info(text);
        else
            std::cout << "Can't print eINFO - Current Log Level = " << static_cast<int>(this->m_iLogLevel) << std::endl;
        break;
    case eLogTypes::eDEBUG:
        if (m_iLogLevel >= eLogTypes::eDEBUG)
            debug(text);
        else
            std::cout << "Can't print eDEBUG - Current Log Level = " << static_cast<int>(this->m_iLogLevel) << std::endl;
        break;
    case eLogTypes::eTRACE:
        if (m_iLogLevel >= eLogTypes::eTRACE)
            trace(text);
        else
            std::cout << "Can't print eTRACE - Current Log Level = " << static_cast<int>(this->m_iLogLevel) << std::endl;
        break;
    case eLogTypes::eALL:
        if (m_iLogLevel >= eLogTypes::eALL)
            all(text);
        else
            std::cout << "Can't print eALL - Current Log Level = " << static_cast<int>(this->m_iLogLevel) << std::endl;
        break;
    default:
        std::cout << "Log Level Not defined - Unable to Log the message!!\n";
        break;
    }
}
void Logger::logMsg(eLogTypes eLogType, std::string str)
{
    logMsg(eLogType, str.data());
}
void Logger::setLogLevel(eLogTypes eLogLevel)
{
    this->m_iLogLevel = eLogLevel;
}