#include "OpenBinaryFile.hpp"

OpenBinaryFile::OpenBinaryFile(const std::string& fileName)
	:m_fileName(fileName)

{
	m_readTheFile.open(m_fileName, std::ios::in | std::ios::binary);
	if (!m_readTheFile.is_open())
	{
		std::cout << "Error open " << m_fileName.substr(m_fileName.find_last_of("\\") + 1, std::string::npos) << " file" << std::endl;
		perror("");
	}
	
}

OpenBinaryFile::~OpenBinaryFile()
{
	m_readTheFile.close();
}

void OpenBinaryFile::charToVector(std::vector<char>& nameOfVector)
{
	char symbols;
	while (m_readTheFile.get(symbols))
	{
		nameOfVector.push_back(symbols);
	}
}