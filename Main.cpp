// Main.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <string>
#include <fstream>
#include "hashMap.h"
#include "Sha1.h"
#include <tbb/parallel_invoke.h>

using namespace sha1;
using namespace tbb;

int main(int argc, char* argv[])
{
	if (argc == 2)
	{
		//initiate variables
		unsigned char hash[20];
		char hexstr[41];
		unsigned int size = strlen(argv[1]);

		//convert to hash and then to string
		calc(argv[1], size, hash);
		toHexString(hash, hexstr);

		//print final string
		std::cout << hexstr << std::endl;
	}
	else if (argc == 3)
	{
		//check if files exist and open them
		std::ifstream dict(argv[1]);
		std::ifstream pass(argv[2]);
		if (pass.good() && dict.good())
		{
			//load dictionary
			HashMap dictTable = HashMap(dict);
			std::cout << dictTable.mNumElements << " elements added to table" << std::endl;
			std::cout << "Dictionary loaded in " << dictTable.mElapsed << " seconds." << std::endl;

			//open file for writing
			std::string line;
			std::ofstream solved;
			solved.open("pass_solved.txt");
			int count = 0;

			if (pass.is_open() && solved.is_open())
			{
				while (getline(pass, line))
				{
					dictTable.getPass(line, count);
					count++;
				}
				Timer timer;
				timer.start();
				tbb::parallel_invoke(
					[&dictTable] {dictTable.force(0, 4); },
					[&dictTable] {dictTable.force(4, 8); },
					[&dictTable] {dictTable.force(8, 12); },
					[&dictTable] {dictTable.force(12, 16); },
					[&dictTable] {dictTable.force(16, 20); },
					[&dictTable] {dictTable.force(20, 24); },
					[&dictTable] {dictTable.force(24, 28); },
					[&dictTable] {dictTable.force(28, 32); },
					[&dictTable] {dictTable.force(32, 36); });
				std::cout << "Passwords decrypted in " << timer.getElapsed() << " seconds" << std::endl;
				for (int i = 0; i < signed int(dictTable.mSolved.size()); i++)
				{
					try
					{
						solved << dictTable.mSolved.at(i)->mHexStr << "," << dictTable.mSolved.at(i)->mSolution << std::endl;
					}
					catch (const std::out_of_range& oor)
					{
						std::cerr << "Out of Range error: " << oor.what() << '\n';
					}
				}
			}
			else
			{
				std::cout << "error opening pass_solved.txt" << std::endl;
			}
		}
		else
		{
			std::cout << "Error: One or both files not found" << std::endl;
		}

	}
	return 0;
}

