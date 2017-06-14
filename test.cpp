#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

enum Terrain
{
	DESERT = 0,
	PLAINS = 0,
	FOREST = 1,
	MOUNTAIN = 2,
};

int main()
{
	srand(time(NULL));
	Terrain t = static_cast<Terrain>(rand() % 4);
	cout << t << endl;
	return 0;
}