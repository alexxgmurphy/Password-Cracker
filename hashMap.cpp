#include "hashMap.h"

HashMap::HashMap(std::ifstream &dict)
{
	//initiate variables 
	unsigned char dictHash[20];
	char hexString[41];
	unsigned int size;
	std::string line;
	std::vector<Pair*> hashHex;

	//preallocate 100,000 buckets
	hashTable.rehash(120000);

	//start timer
	Timer timer;
	timer.start();

	//loop through dict file
	while (getline(dict, line))
	{
		//get size of line
		size = line.size();

		//convert to sha1, store result in char array
		sha1::calc(&line, size, dictHash);

		//convertchar array to hexstr
		sha1::toHexString(dictHash, hexString);
		hashHex.push_back(new Pair(dictHash, line));

		//add to hash table
		hashTable.insert(std::make_pair(hexString, hashHex[mNumElements]));
		mNumElements++;
	}
	mElapsed = timer.getElapsed();
	
}

std::string HashMap::getPass(std::string &sha, int lineNum)
{
	if (hashTable.find(sha) == hashTable.end())
	{
		mUnsolved.push_back(new Brute(sha, "", lineNum, false));
		mSolved.insert(std::make_pair(lineNum, new Brute(sha, "??", lineNum, true)));
		return sha + ",????";
	}
	else
	{
		mSolved.insert(std::make_pair(lineNum, new Brute(sha, hashTable.find(sha)->second->mWord, lineNum, true)));
		return sha + "," + hashTable.find(sha)->second->mWord;
	}
}

void HashMap::force(int start, int end)
{
	std::vector<int> digits;
	std::string englishPass;
	std::string shaPass;
	unsigned char hash[20];
	char hexstr[41];

	for (int i = 0; i < 4; i++)
	{
		digits.push_back(-1);
	}
	if (start > 0)
	{
		digits[0] = start;
	}
	bool done = true;
	while (mUnsolved[0]->counter(digits, 3))
	{
		if (digits[0] == end)
		{
			break;
		}
		//convert to string
		englishPass = mUnsolved[0]->convert(digits);

		//convert to sha
		sha1::calc(&englishPass, englishPass.size(), hash);
		sha1::toHexString(hash, hexstr);
		shaPass = hexstr;

		for (int i = 0; i < signed int(mUnsolved.size()); i++)
		{
			if (shaPass == mUnsolved[i]->mHexStr)
			{
				std::cout << "SHA-1: " << shaPass << "\nDecrypted = " << englishPass << std::endl;
				mUnsolved[i]->mSolution = englishPass;
				mUnsolved[i]->mSolved = true;
				mSolved[mUnsolved[i]->mEntryNum] = mUnsolved[i];
			}
		}
	}
}
