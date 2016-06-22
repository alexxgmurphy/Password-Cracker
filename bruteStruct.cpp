#include "bruteStruct.h"

Brute::Brute(std::string encrypted, std::string solved, int entryNum, bool solve)
{
	mHexStr = encrypted;
	mSolution = solved;
	mEntryNum = entryNum;
	mSolved = solve;
}

Brute::Brute()
{
	mHexStr = "";
	mSolution = "??";
	mEntryNum = 0;
	mSolved = false;
}

void Brute::print()
{
	if (!mSolved)
	{
		std::cout << "Entry " << mEntryNum << "\n" << "Encrypted sha:\n\t" << mHexStr << "\nUNSOLVED\n" << std::endl;
	}
	else
	{
		std::cout << "Entry " << mEntryNum << "\n" << "Encrypted sha:\n\t" << mHexStr << "\nSOLUTION: " << mSolution << "\n" << std::endl;
	}
}

bool Brute::counter(std::vector<int> &toInc, int place)
{
	if (toInc[place] == 35 && place > 0)
	{
		toInc[place] = 0;
		place -= 1;
		counter(toInc, place);
		return true;
	}
	else if (toInc[place] == 35 && place == 0)
	{
		toInc[place]++;
		toInc[1] = 0;
		toInc[2] = 0;
		toInc[3] = 0;
		return false;
	}
	else
	{
		toInc[place]++;
		return true;
	}
}

std::string Brute::convert(std::vector<int> digits)
{
	std::string temp;
	for (int i = 0; i < 4; i++)
	{
		if (digits[i] == 0)
		{
			temp.push_back('a');
		}
		else if (digits[i] == 1)
		{
			temp.push_back('b');
		}
		else if (digits[i] == 2) {
			temp.push_back('c');
		}
		else if (digits[i] == 3) {
			temp.push_back('d');
		}
		else if (digits[i] == 4) {
			temp.push_back('e');
		}
		else if (digits[i] == 5) {
			temp.push_back('f');
		}
		else if (digits[i] == 6) {
			temp.push_back('g');
		}
		else if (digits[i] == 7) {
			temp.push_back('h');
		}
		else if (digits[i] == 8) {
			temp.push_back('i');
		}
		else if (digits[i] == 9) {
			temp.push_back('j');
		}
		else if (digits[i] == 10) {
			temp.push_back('k');
		}
		else if (digits[i] == 11) {
			temp.push_back('l');
		}
		else if (digits[i] == 12) {
			temp.push_back('m');
		}
		else if (digits[i] == 13) {
			temp.push_back('n');
		}
		else if (digits[i] == 14) {
			temp.push_back('o');
		}
		else if (digits[i] == 15) {
			temp.push_back('p');
		}
		else if (digits[i] == 16) {
			temp.push_back('q');
		}
		else if (digits[i] == 17) {
			temp.push_back('r');
		}
		else if (digits[i] == 18) {
			temp.push_back('s');
		}
		else if (digits[i] == 19) {
			temp.push_back('t');
		}
		else if (digits[i] == 20) {
			temp.push_back('u');
		}
		else if (digits[i] == 21) {
			temp.push_back('v');
		}
		else if (digits[i] == 22) {
			temp.push_back('w');
		}
		else if (digits[i] == 23) {
			temp.push_back('x');
		}
		else if (digits[i] == 24) {
			temp.push_back('y');
		}
		else if (digits[i] == 25) {
			temp.push_back('z');
		}
		else if (digits[i] == 26) {
			temp.push_back('0');
		}
		else if (digits[i] == 27) {
			temp.push_back('1');
		}
		else if (digits[i] == 28) {
			temp.push_back('2');
		}
		else if (digits[i] == 29) {
			temp.push_back('3');
		}
		else if (digits[i] == 30) {
			temp.push_back('4');
		}
		else if (digits[i] == 31) {
			temp.push_back('5');
		}
		else if (digits[i] == 32) {
			temp.push_back('6');
		}
		else if (digits[i] == 33) {
			temp.push_back('7');
		}
		else if (digits[i] == 34) {
			temp.push_back('8');
		}
		else if (digits[i] == 35) {
			temp.push_back('9');
		}
	}
	return temp;
}