#pragma once

#ifndef HASHMAP_DEFINED
#define HASHMAP_DEFINED

#include "Sha1.h"
#include "pair.h"
#include "Timer.h"
#include <istream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <vector>
#include <map>
#include "bruteStruct.h"
#include <tbb/parallel_for_each.h>

//creates an unordered map of strings containing passwords and their sha1 equivalents
struct HashMap
{
	//parametrized constructor
	HashMap(std::ifstream &dict);
	std::string getPass(std::string &sha, int lineNum);

	//brute force
	void force(int start, int end);

	//variables
	std::unordered_map <std::string, Pair*> hashTable;
	int mNumElements = 0;
	double mElapsed;
	Brute mSolutions;
	std::map<int, Brute*> mSolved;
	std::vector<Brute*> mUnsolved;
};

#endif