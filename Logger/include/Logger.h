#include <iostream>
#include <sstream>
#include <string>
#include <mutex>

using namespace std::string_literals;

enum class LogSetting: std::uint32_t{
    eLOG_INFO = 0,
    eLOG_ERROR ,
    eLOG_DEBUG ,
    eLOG_TRACE ,
    eLOG_ALL ,
};

#define LOGERROR LogSetting::eLOG_ERROR
#define LOGINFO LogSetting::eLOG_INFO
#define LOGDEBUG LogSetting::eLOG_DEBUG
#define LOGTRACE LogSetting::eLOG_TRACE
#define LOGALL LogSetting::eLOG_ALL

namespace nLogging{
    class Logger {
    public:

        static Logger& getInstance(){
            static Logger log;
            return log;
        }

        ~Logger() = default;

        /**
         * @brief set current log level
        */
        void setLogLevel(const LogSetting& mLogLevel){
            this->mLogLevel = mLogLevel;
        }
        
        // Log function that can take any number of arguments of various data types
        template <typename... Args>
        void log(const LogSetting& mLogType, const Args&... args) {
            if(this->mLogLevel >= mLogType){
                std::lock_guard<std::mutex> lg(this->mtx);
                logStream_ << this->getLogText(mLogType) <<concat(args...) << '\n';
                printLog();
            }
        }

    private:
        std::ostringstream logStream_;
        LogSetting mLogLevel;
        std::mutex mtx;

    private:
        /**
         * @brief Private Constructor
        */
        Logger() {}
        
        template <typename T>
        std::string concat(const T& arg) {
            std::ostringstream stream;
            stream << arg;
            return stream.str();
        }

        /**
         * @brief Function to concatenate multiple arguments into a single string
         * @param T Identified Data type 
         * @param Args other argument of various types
         * @return Concatenated result text
        */
        
        template <typename T, typename... Args>
        std::string concat(const T& first, const Args&... rest) {
            return concat(first) + " " + concat(rest...);
        }

        /**
         * @brief Print actual logs
        */
        void printLog(){
            std::cout << logStream_.str();
            this->logStream_.str("");
            return;
        }

        /**
         * @brief Get log pre-text type
        */
        std::string getLogText(const LogSetting& mLogType){
            switch (mLogType){
                case LOGERROR :
                    return "[ERROR]: "s;
                case LOGINFO :
                    return "[INFO]: "s;
                case LOGDEBUG :
                    return "[DEBUG]: "s;
                case LOGTRACE :
                    return "[TRACE]: "s;
                case LOGALL :
                    return "[ALL]: "s;
                default:
                    break;
            }
            return "[UNKNOWN]: "s;
        }
    };

    #define LOG(...) (nLogging::Logger::getInstance()).log(__VA_ARGS__)
    #define SETLOGLEVEL(x) (nLogging::Logger::getInstance()).setLogLevel(x)
}