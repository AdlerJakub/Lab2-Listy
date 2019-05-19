#include <iostream>
#include <cstdint>
#include <windows.h>
#include <vector>
#include <cstdlib>

#include "List.h"
#include "Defines.h"
#include "Tester.h"

using namespace std;

double GetPerformanceCounter()
{
	LARGE_INTEGER li;
	QueryPerformanceFrequency(&li);
	double freq = double(li.QuadPart) / 1000.0;
	QueryPerformanceCounter(&li);
	return double(li.QuadPart) / freq;
}

int main()
{
	CList *Lista = new CList;
	point_t punkt;
	punkt.x = 1;
	punkt.y = 1;
	punkt.z = 1;
	size_t kr=10;
	int i;
	

	/*

	///Sprawdzanie czy nastepuje wyciek pamieci
	
	while (kr)
	{

		for (i = 0; i < 1000; i++)
		{
			Lista->push_back(punkt);
			
		}
		for (i = 0; i < 1000; i++)
		{
			Lista->pop_back();
		}
		
	}

	*/
	
	///Porownanie vector vs lista
	/*
	//Test 1 podejscie 1
	cout << endl << endl << "Dodawanie elementu wektorem: \t";
	double startTime = GetPerformanceCounter();
	vector<point_t> pkt;
	for (int i = 0; i < 1000; i++) // dodaje elementy do listy
	{
		point_t p =
		{
			2 * i +1,
			3 * i +2,
			4 * i +3,
		};
		pkt.push_back(p);
	}
	double endTime = GetPerformanceCounter();
	cout << endTime - startTime << " ms" << endl;



	//Test 1 Podejscie 2
	cout << "dodawanie elementu listy: \t";
	startTime = GetPerformanceCounter();

	CList *Lista2 = new CList;
	for (int i = 0; i < 1000; i++) // dodawanie elementow do listy
	{
		point_t p =
		{
			2 * i + 1,
			3 * i + 2,
			4 * i + 3,
		};
		Lista2->push_back(p);
	}
	endTime = GetPerformanceCounter();
	cout << endTime - startTime << " ms" << endl << endl;


	//Test2 Podejscie 1

	cout << "Dostep vectorem: \t";
	startTime = GetPerformanceCounter();

	for (int i = 0; i < 1000; i++) // get elements
	{
		point_t a = pkt[i];
	}

	endTime = GetPerformanceCounter();
	cout << endTime - startTime << " ms" << endl;

	//Test2 Podejscie 2

	cout << "Dostep lista: \t";
	startTime = GetPerformanceCounter();
	point_t a;
	for (int i = 0; i < 1000; i++) // get elements
	{
		Lista2->get(i, a);
	}

	endTime = GetPerformanceCounter();
	cout << endTime - startTime << " ms" << endl << endl;

	//Test3 Podejscie 1

	cout << "Usuwanie wektorowo: \t";
	startTime = GetPerformanceCounter();

	for (int i = 1; i < 1000; i++) //delete them
	{
		pkt.erase(pkt.begin());
	}

	endTime = GetPerformanceCounter();
	cout << endTime - startTime << " ms" << endl;

	//Test4 Podejscie 2

	cout << "Usuwanie listy: \t";
	startTime = GetPerformanceCounter();

	for (int i = 1; i < 1000; i++) //delete them
	{
		Lista2->pop_back();
	}

	endTime = GetPerformanceCounter();
	cout << endTime - startTime << " ms" << endl;


	delete Lista2;

	*/

	system("pause");
	return 0;
}