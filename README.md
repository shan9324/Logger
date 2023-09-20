# Logger

This is a simple Logger application that can log messages based on user-provided severity/priority.
It is a header-only program and can be included along with other headers in your C++ program. 
One can look-up the existing CMakeLists.txt for building their own projects.
NOTE: A logger is supposed to be available for the lifetime of a program, and thus, Singleton design pattern is used here.

# Build
```bash
mkdir build && cd build/
cmake ..
make
```
The AppLogger.exe is placed in the same build/ folder.

# Platform Usage
As of now, no platform dependent libraries or headers are used and thus, this program can be used on any platform.
