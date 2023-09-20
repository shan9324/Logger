# Logger

This is a simple Logger project that can log messages based on user-provided severity/priority.
It is a header-only application and can be included along with other headers in your C++ program. 
One can look-up the existing CMakeLists.txt for building their own projects.
NOTE: A logger is supposed to be available for the lifetime of a program, and thus, Singleton design pattern is used here.

# Build
In the root folder, one can build the application with the Logger.h as explained below:
```bash
mkdir build && cd build/
cmake ..
make
```
The AppLogger.exe is placed in the same build/ folder.

# Platform Usage
As of now, no platform dependent libraries or headers are used and thus, this program can be used on any platform viz., windows, linux/unix or macOS
