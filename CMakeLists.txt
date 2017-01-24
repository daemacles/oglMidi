cmake_minimum_required (VERSION 2.6)

set (PROJECT_NAME oglMidi)
project (${PROJECT_NAME})

## Set optional features.  This will show up as a preprocessor variable

## USE_MY_LIBRARY in source.
#option (USE_MY_LIBRARY
#        "Use the provided library" ON)

## Support for Clang's CompilationDatabase system
set (CMAKE_EXPORT_COMPILE_COMMANDS 1)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory( glfw-3.2.1 )

## Compile and create a library.  STATIC is default unless BUILD_SHARED_LIBS
## is on.
#add_library (LibraryName src/sources.cc)

#if (USE_MY_LIBRARY)
  ## Search for include files here as well
  #include_directories ("{PROJECT_SOURCE_DIR}/some_sub_path")

  ## Run Cmake also in this dir
  #add_subdirectory (some_sub_path)

  #set (EXTRA_LIBS ${EXTRA_LIBS} LibraryName)
#endif (USE_MY_LIBRARY)

include_directories ("include")
include_directories ("glfw-3.2.1/include")

set(LIBS 
	glfw
	)

add_executable (${PROJECT_NAME} 
	src/glad.c
	src/main.cc
	)
target_link_libraries (${PROJECT_NAME} ${EXTRA_LIBS} ${LIBS})

# Compile flags
SET (CMAKE_C_FLAGS                "-Wall -std=c11")
SET (CMAKE_C_FLAGS_DEBUG          "${CMAKE_CFLAGS} -g")
SET (CMAKE_C_FLAGS_MINSIZEREL     "${CMAKE_CFLAGS} -Os -DNDEBUG")
SET (CMAKE_C_FLAGS_RELEASE        "${CMAKE_CFLAGS} -O3 -DNDEBUG")
SET (CMAKE_C_FLAGS_RELWITHDEBINFO "${CMAKE_CFLAGS} -O2 -g")

SET (CMAKE_CXX_FLAGS                "-Wall -std=c++14")
SET (CMAKE_CXX_FLAGS_DEBUG          "${CMAKE_CXXFLAGS} -g")
SET (CMAKE_CXX_FLAGS_MINSIZEREL     "${CMAKE_CXXFLAGS} -Os -DNDEBUG")
SET (CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXXFLAGS} -O2 -g")
SET (CMAKE_CXX_FLAGS_RELEASE        "${CMAKE_CXXFLAGS} -O3 -DNDEBUG")



