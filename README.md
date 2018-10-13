# CU Computer Graphics Group Hack Night
This is the codebase used for Hack Nights of CU Computer Graphics Group. Our goal is building a [whitted ray tracer](https://en.wikipedia.org/wiki/Ray_tracing_(graphics)) together during club meetings.

## Tools needed to compile
### A C++ 17 compiler
Recent version of [Visual Studio](https://www.visualstudio.com/), [GCC](https://gcc.gnu.org/), or [Clang](https://clang.llvm.org/) should be find.

### CMake 3.8+
[CMake](https://cmake.org/) is the build tool used for this projects. The minimum CMake version requirement is 3.8. 

### Conan
[Conan](https://conan.io/) is the package manager this project use. The easiest way to install conan is through `pip`:

``` shell
$ pip install conan
```

### (Optional) Ninja
[Ninja](https://ninja-build.org/) can significantly improve the incremental build time. Can be used as a target for CMake.

### (Optional) CPPCheck
Download [cppcheck](https://sourceforge.net/projects/cppcheck/) here. CPPCheck is a static analyze tool with very few false positive.

### (Optional) Clang tool chains
Download [clang](http://releases.llvm.org/download.html) here. This projects use [clang-tidy](http://clang.llvm.org/extra/clang-tidy/) and [clang-format](https://clang.llvm.org/docs/ClangFormat.html) for linting.

## Build and run
After installing all the tools, we can build and run this project:

``` shell
mkdir build
cd build
conan install .. # Install dependencies
cmake .. # Generate target for CMake, you can pass parameters to CMake here
```

After generate the building script, you can compile your project from there. There are no platform dependent way of doing that. If you generate ninja target, you should be able to use `ninja` command in the `build` folder to compile. If you generate a Makefile, use `make` command in the `build` folder.

Note every time you reconfig the `CMakeList.txt`, you need to run `cmake` command again.
