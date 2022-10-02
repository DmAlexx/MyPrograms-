cmake_minimum_required(VERSION 3.6)

# Set the project name
project (Main)

# Create a sources variable with a link to all cpp files to compile
set(SOURCES
	OpenBinaryFile.cpp
	OpenBinaryFile.hpp
	CountEntropy.hpp
	CountEntropyMain.cpp
)

add_executable(Main ${SOURCES})