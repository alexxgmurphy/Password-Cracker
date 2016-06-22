#pragma once

#ifndef BRUTESTRUCT_DEFINED
#define BRUTESTRUCT_DEFINED

#include "bruteStruct.h"
#include <string>
#include "pair.h"
#include <iostream>
#include <vector>
#include "Sha1.h"

struct Brute 
{
	//member variables
	std::string mHexStr;
	std::string mSolution;
	int mEntryNum;
	bool mSolved;

	//Parametrized constructor
	Brute(std::string encrypted, std::string solved, int entryNum, bool solve);

	//Default constructor
	Brute();

	//print data
	void print();

	//brute force algorithm
	bool counter(std::vector<int> &toIncrement, int place);
	std::string convert(std::vector<int> digits);
};

#endif