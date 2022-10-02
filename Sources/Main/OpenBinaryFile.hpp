#pragma once
#include <iostream>
#include <fstream>
#include <vector>

class OpenBinaryFile
{
private:
	std::ifstream m_readTheFile;
	std::string m_fileName;

public:
	OpenBinaryFile(const std::string& fileName);
	~OpenBinaryFile();
	void charToVector(std::vector<char>& nameOfVector);
};

