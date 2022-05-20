# Temp Cam

###### Noah Himed

### Summary

A software package that collects temperature data from a TE-Q1 Pro thermal camera.

### Building the Software

Compile the software package with CMake using the included CMakeLists.txt file
from the project root/

You may install CMake and add it to your system path by using the
[Chocolatey Package Manager for Windows](https://chocolatey.org/) and running
the following command on the Windows terminal **with admin privleges**
```
choco install cmake --installargs 'ADD_CMAKE_TO_PATH=System'
```

Use the [CMake extension for VS Code](https://code.visualstudio.com/docs/cpp/cmake-linux) to build the project. The exectable
`temp_cam.exe` will be created at `build\Debug`, relative to the project root.