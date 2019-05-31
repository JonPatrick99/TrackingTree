// Main.cpp
// Jon Caldwell
// Project 2: Tracking Tree

#include <iostream>
#include "TTnode.h"
#include "TrackingTree.h"
#include <unordered_map>

using std::hash;
using std::cout;
using std::cin;

int main()
{
	TrackingTree* treeMaster = new TrackingTree();

	string input, input2;
	bool stop = false;
	while (stop == false)
	{
		cout << "\n\nPlease type a task: ";
		cin >> input;
		if (input._Equal("add"))
		{
			cin >> input;
			treeMaster->insertNode(treeMaster->getTree(), input);
			treeMaster->changeCrawl(treeMaster->height(treeMaster->getTree()) - 1);
		}
		else if (input._Equal("display"))
		{
			treeMaster->getTree()->display();
			treeMaster->getTree()->displayRec();
		}
		else if (input._Equal("update"))
		{
			cin >> input;
			cin >> input2;
			treeMaster->changeNode(treeMaster->getTree(), input, input2);
			treeMaster->changeCrawl(treeMaster->height(treeMaster->getTree()) - 1);
		}
		else if (input._Equal("search"))
		{
			cin >> input;
			treeMaster->showNode(treeMaster->getTree(), input);
		}
		else if (input._Equal("stop"))
		{
			stop = true;
		}
		else
		{
			cout << " incorrect input. valid inputs are: add, display, update, search, stop.";
		}
	}

	system("pause");
	return 0;
}

char* gen_random(const int len)				//Generates a string that is 8 characters long
{
	char* s = new char[8];
	static const char alphanum[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";

	for (int i = 0; i < len; ++i) {
		s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
	}

	s[len] = 0;

	return s;
}

string hasher(string in, hash<string> stHash)				//Generates a hash that has a length of 8 characters long
{
	string out;

	for (int i = 0; i < 8; i++)
	{
		out.push_back(stHash(in + static_cast<char>(i)));
	}
	out.resize(8);


	return out;
}





// I got help with the project from "Data Structures and Algorithm Analysis in C++", www.cplusplus.com, geeksforgeeks.com, and my brother.
