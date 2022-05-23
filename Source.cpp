#include <iostream>
#include <fstream>
#include <vector>
#include <conio.h>
#include <thread>
#include <windows.h>

using namespace std;

vector <char> chstr1;
string path;


int ReadTheFileToVector(string path)
{
	char ch;
	chstr1.clear();
	ifstream readthefile;
		readthefile.open(path, ios::in | ios::binary);
		if (!readthefile.is_open())
		{
			cout << "Error open " << path.substr(path.find_last_of("\\") + 1, string::npos) << " file" << endl;
			return(1);
		}
		
		else
		{
			while (readthefile.get(ch))
			{
				chstr1.push_back(ch);
			}
			return(0);
		}
		readthefile.seekg(0);
	readthefile.close();
	
}

void CountEntropy()
{
	int code[256] = { 0 };
	
	long total = 0;

	double entr=0, prob;

	uint8_t j = 0;

	for (long i = 0; i < chstr1.size(); ++i)

	{
		j = static_cast<int>(chstr1[i]);
		code[j]++;
		total++;
	}
	
	for (long i = 0; i < 256; i++)
	{
		if (code[i] == 0) continue;
		prob = code[i] / (double)total;

		entr -= prob * log(prob) / log(2.0f);
	}
	
	cout << "Entropy of "<< path.substr(path.find_last_of("\\") + 1, string::npos)<< " file = " << entr << endl;
}

DWORD WINAPI CheckEscape(LPVOID lpParam) {
	while (GetAsyncKeyState(VK_ESCAPE) == 0) {
		Sleep(10);
	}
	exit(0);

}



int ChangeTheIcon()
{
	return(0);
}


int main()
{
	
	setlocale(LC_ALL, "");
	CreateThread(NULL, 0, CheckEscape, NULL, 0, NULL);
	
	
	while (true)

	{
		cout << "Enter path and file name or press ESC to exit" << endl;
		cin >> path;
		

		if (ReadTheFileToVector(path) == 1)
		{
			continue;
		}

		else
		{
			CountEntropy();
		}
	}
	return(0);
}
