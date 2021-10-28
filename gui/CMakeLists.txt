cmake_minimum_required (VERSION 3.1.0)
project(gui)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

set(CMAKE_PREFIX_PATH   ${CMAKE_PREFIX_PATH} $ENV{QTDIR})

# Dependencies
find_package(Qt5 COMPONENTS Widgets REQUIRED) #find_package(Qt5Widgets 5.5.1 REQUIRED)
find_package(Qt5 COMPONENTS Core REQUIRED) #find_package(Qt5Core    5.5.1 REQUIRED)

# Files
file(GLOB_RECURSE SRCS  "${PROJECT_SOURCE_DIR}/src/*.c*")
file(GLOB_RECURSE HDRS  "${PROJECT_SOURCE_DIR}/include/gui/*.h*")
#file(GLOB_RECURSE UIS   "${PROJECT_SOURCE_DIR}/src/*.ui")



# Include
include_directories("${PROJECT_SOURCE_DIR}/include" "${PROJECT_BINARY_DIR}/src")

# Target
add_executable(gui
    ${SRCS}
    ${HDRS}
#    ${UIS}
)

# QtShit
#file(GLOB_RECURSE UIS   "${PROJECT_SOURCE_DIR}/src/*.ui")
#QT5_WRAP_UI(UIS_H       ${UIS})
#QT5_WRAP_CPP(SRCS "${PROJECT_SOURCE_DIR}/src/MainWindow.cpp")
#list(APPEND library_sources ${moc_sources} ${uic_sources})

# Libs
target_link_libraries(gui Qt5::Widgets Qt5::Core)

# Logs
message(STATUS "SOURCES DIR => ${PROJECT_SOURCE_DIR}/src/")
message(STATUS "SOURCES FILES => ${SRCS}")
message(STATUS "HEADERS DIR => ${PROJECT_SOURCE_DIR}/include/gui")
message(STATUS "HEADERS FILES => ${HDRS}")

