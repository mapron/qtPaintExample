cmake_minimum_required(VERSION 3.20)

project(qtPaintExample)

find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)

add_executable(painterSimple 
	src/main.cpp
	src/MainWindow.h
	src/MainWindow.cpp
)

target_link_libraries(painterSimple PRIVATE Qt5::Widgets)
