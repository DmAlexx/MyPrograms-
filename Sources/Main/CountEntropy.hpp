#pragma once
#include <iostream>
#include <vector>
#include <windows.h>

DWORD WINAPI CheckEscape(LPVOID lpParam);
double CountEntropy(std::vector <char> fileSymbols, double& entropy);