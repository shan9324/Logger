#include <iostream>
#include "Logger.h"
using namespace std;
using namespace nLogging;


Logger* Logger::m_loggerObj = NULL;
Logger* Logger::getInstance()
{
    if (!m_loggerObj)
    {
        m_loggerObj = new Logger;
    }

    return m_loggerObj;
}
void Logger::getSuccessMsg()
{
    if (m_loggerObj)
        cout << "Object Created Successfully" << endl;
    else
        cout << "Object NOT Created!!" << endl;
    return;
}
void Logger::error(const char* text)
{
    string str;
    str.append("[ERROR]: ");
    str.append(text);
    cout << str << endl;
}
void Logger::error(string str)
{
    error(str.data());
}
void Logger::info(const char* text)
{
    string str;
    str.append("[INFO]: ");
    str.append(text);
    cout << str << endl;
}
void Logger::info(string str)
{
    info(str.data());
}
void Logger::debug(const char* text)
{
    string str;
    str.append("[DEBUG]: ");
    str.append(text);
    cout << str << endl;
}
void Logger::debug(string str)
{
    debug(str.data());
}
void Logger::trace(const char* text)
{
    string str;
    str.append("[TRACE]: ");
    str.append(text);
    cout << str << endl;
}
void Logger::trace(string str)
{
    trace(str.data());
}
void Logger::all(const char* text)
{
    string str;
    str.append("[ALL]: ");
    str.append(text);
    cout << str << endl;
}
void Logger::all(string str)
{
    all(str.data());
}
void Logger::logMsg(eLogTypes eLogType, const char* text)
{
    switch (eLogType)
    {
    case eERROR:
        if (m_iLogLevel >= eERROR)
            error(text);
        else
            cout << "Reset Log Level" << endl;
        break;
    case eINFO:
        if (m_iLogLevel >= eINFO)
            info(text);
        else
            cout << "Reset Log Level" << endl;
        break;
    case eDEBUG:
        if (m_iLogLevel >= eDEBUG)
            debug(text);
        else
            cout << "Reset Log Level" << endl;
        break;
    case eTRACE:
        if (m_iLogLevel >= eTRACE)
            trace(text);
        else
            cout << "Reset Log Level" << endl;
        break;
    case eALL:
        if (m_iLogLevel >= eALL)
            all(text);
        else
            cout << "Reset Log Level" << endl;
        break;
    default:
        cout << "Log Level Not defined - Unable to Log the message!!\n";
        break;
    }
}
void Logger::logMsg(eLogTypes eLogType, string str)
{
    logMsg(eLogType, str.data());
}
void Logger::setLogLevel(eLogTypes eLogLevel)
{
    m_iLogLevel = eLogLevel;
}