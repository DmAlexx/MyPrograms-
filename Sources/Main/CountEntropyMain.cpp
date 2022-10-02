#include "CountEntropy.hpp"
#include "OpenBinaryFile.hpp"

int main()
{
	CreateThread(NULL, 0, CheckEscape, NULL, 0, NULL);
	
	std::vector <char> fileSymbols;
	std::string pathToFile;
	double entropy = 0;
	
	std::cout << "Enter path and file name or press ESC to exit" << std::endl;
	std::cin >> pathToFile;

	OpenBinaryFile file(pathToFile);
	file.charToVector(fileSymbols);
	CountEntropy(fileSymbols, entropy);
	std::cout << "Entropy of " << pathToFile.substr(pathToFile.find_last_of("\\") + 1, std::string::npos) << " file = " << entropy << std::endl;
	return 0;
}

double CountEntropy(std::vector<char> fileSymbols, double& entropy)
{
	int eachSymbolAmount[256] = { 0 };
	long totalAmountSymbols = 0;
	double probabilityEverySymbol = 0;
	uint8_t charToInt = 0;

	for (unsigned long i = 0; i < fileSymbols.size(); ++i)
	{
		charToInt = static_cast<int>(fileSymbols[i]);
		eachSymbolAmount[charToInt]++;
		totalAmountSymbols++;
	}
	for (int i = 0; i < 256; i++)
	{
		probabilityEverySymbol = eachSymbolAmount[i] / (double)totalAmountSymbols;
		entropy += probabilityEverySymbol * log(1 / probabilityEverySymbol);
	}
	return entropy;
}

DWORD WINAPI CheckEscape(LPVOID lpParam) 
{
	while (GetAsyncKeyState(VK_ESCAPE) == 0) 
	{
		Sleep(10);
	}
	exit(0);
}


