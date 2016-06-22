#pragma once

#ifndef PAIR_DEFINED
#define PAIR_DEFINED

#include <string>

struct Pair
{
	unsigned char* mHash;
	std::string mWord;

	Pair(unsigned char* hash, std::string word);
};

#endif