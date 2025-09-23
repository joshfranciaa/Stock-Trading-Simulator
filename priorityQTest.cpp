#include "priorityQ.h"
#include <unordered_map>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	priorityQ<string, int> mario_kart;
	unordered_map<string, int> removedItems;

	mario_kart.push_back("Mario", 22);
	mario_kart.push_back("Luigi", 30);
	mario_kart.push_back("Peach", 15);
	mario_kart.push_back("Toad", 27);
	mario_kart.push_back("Wario", 17);
	mario_kart.push_back("Yoshi", 21);
	mario_kart.push_back("Bowser", 1);
	mario_kart.push_back("KoopaTroopa", 11);


	mario_kart.update("Peach", 20);
	mario_kart.update("Luigi", 1);

	mario_kart.update("Bowser", 19);

	mario_kart.update("Wario", 12);
	mario_kart.update("Luigi", 33);

	mario_kart.update("Toad", 1);

	for (int i = 0; i < 3; i++)
	{
		removedItems[mario_kart.getRootKey()] = 
			mario_kart.getRootPriority();

		mario_kart.pop_front();
	}

	for (auto element : removedItems)
		mario_kart.push_back(element.first, element.second);


	while (!mario_kart.isEmpty())
	{
		cout << mario_kart.getRootKey() << ": ";
		cout << mario_kart.getRootPriority() << endl;

		mario_kart.pop_front();
	}

	return 0;
}