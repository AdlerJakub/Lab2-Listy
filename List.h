#pragma once
#pragma once
#define USER_NAME    "Jakub"         //Prosz� wpisa� swoje Imi�
#define USER_SURNAME "Adler"     //Prosz� wpisa� swoje Nazwizko
#define USER_GROUP   3 				//Prosz� wpisac numer grupy
#include "Tester.h"

class CList : public Tester
{
private:
	list_el *first;
	size_t count;
public:
	CList();
	~CList();

	void push_back(const point_t &p); ///dodaje element na ko�cu listy
	result_en pop_back();  ///usuwa ostatni element
	result_en insert(size_t kr, const point_t &p); ///wstawia element na n-tej pozycji listy
	result_en find(const point_t &p, size_t &kr) const; ///wyszukuje element listy warto�ciami zgodny z podanym punktem oraz podaje jego pozycje
	result_en get(size_t kr, point_t &p) const; ///wy�wietla n-ty element listy
	size_t size() const; ///podaje ilo�� element�w
	void drawme(); ///wypisuje elementy listy- uzywalem do testow innych metod
};