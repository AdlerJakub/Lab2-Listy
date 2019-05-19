#include "List.h"
#include "Defines.h"
#include <iostream>
#include "Tester.h"

CList::CList() ///w konstruktorze zeruje pierwszy element
{
	count = 0;
	first = 0;
}

list_el::list_el(const point_t &p)
{
	this->next = 0;
	this->p = p;

}


CList::~CList() ///w destruktorze usuwam liste
{
	list_el *curr = first;
	while (curr != 0)
	{
		list_el *prev_curr = curr;
		curr = curr->next;
		delete prev_curr;
	}

}


void CList::push_back(const point_t &p)
{
	list_el *nowy_el = new list_el(p); ///tworze nowy element
	

	if (count == 0) ///jesli lista jeszcze ni ma elementow tworze pierwszy
	{
		first = nowy_el;
		count++;
	}
	else ///jesli lista ma juz elementy przesuwam sie na jej koniec i tam dodaje element
	{
		list_el *curr = first;

		while (curr->next != 0)
		{
			curr = curr->next;
		}

		curr->next = nowy_el;
		count++;
	}
	nowy_el->next = 0;
}


result_en CList::pop_back()
{
	list_el *pcurr = 0;
	list_el *curr = first;

	if (count == 0) ///jesli lista ma tylko jeden element to kasuje go
	{
		return res_empty;
	}
	else ///jesli ma tez inne przesuwam sie na koniec, usuwam element a w przedostatnim elementcie zeruje wskaznik na nastepny
	{
		if (count == 1)
		{
			delete curr;
			first = 0;
			count = 0;
			return res_ok;

		}
		


		while (curr->next != 0)
		{
			pcurr = curr;
			curr = curr->next;
		}
		delete curr;
		pcurr->next = 0;
		count--;
		return res_ok;
	}
}

result_en CList::insert(size_t kr, const point_t &p)
{
	

	if (kr == 0) ///jesli chcemy wstawic element na poczatek 
	{

		if (first == 0) ///jesli lista nie ma elementow to tworzymy pierwszy
		{
			first = new list_el(p);
			//first->next = 0;
			//first->p = p;
			count++;
			return res_ok;
		}
		else
		{
			list_el *curr = first;
			first = new list_el(p);			
			first->next = curr;
			count++;
			return res_ok;
		}
	}
	else
	{
		/*!
		* \brief Wstawianie dalej
		*
		* Jesli wstawiamy dalej to najpierw sprawdzamy czy miejsce po ktorym wstawiamy istnieje.
		*Liczymy w petli ilosc elementow listy i porownujmy ja z zadanym miejscem.
		* W zaleznosci od wyniku zwracamy blad ub wstawiamy wartosc.
		*/

		list_el *curr = first;
		//size_t licznik = 0;
		int i;
		/*while (curr != 0)
		{
			licznik++;
			curr = curr->next;

		}*/


		//curr = first;
		if (kr > count)
		{
			return res_out_of_range;
		}
		else
		{


			for (int i = 1; i < kr; i++)
			{
				curr = curr->next;
				count++;
			}


			list_el *tmp = curr->next;
			curr->next = new list_el(p);
			curr->next->p = p;
			curr->next->next = tmp;
			count++;
			return res_ok;
		}

	}

}


result_en CList::find(const point_t &p, size_t &kr) const ///szukamy elementu o tych samych wartosciach co zadany punkt
{
	list_el *curr = first;
	kr = 0;
	if (count == 0)
	{
		return res_empty; ///gdy lista jest pusta zwracamy komunikat
	}
	while (curr->p.x != p.x && curr->p.y != p.y && curr->p.z != p.z)
	{
		if (curr->next == 0) ///gdy go nie a zwracamy blad
		{
			return res_out_of_range;
		}
		
		curr = curr->next;
		kr++;
		
	}
	return res_ok; ///zwracamy komunikat o pomyslnym wykonaniu polecenia
}

result_en CList::get(size_t kr, point_t &p) const
{
	list_el *curr = first;
	size_t i;
	//size_t licznik = 0;

	if (count == 0) ///jesli lista jest pusta to zwracamy stosowny komunikat
	{
		return res_empty;
	}
	/*
	while (curr != 0)
	{
		licznik++;
		curr = curr->next;
	}
	curr = first; */

	if (kr >= count) ///jesli chcemy wyciagnac element o zbyt duzym numerze to zwraca komunikat
	{
		return res_out_of_range;
	}
	else ///jesli wybralismy elemet z odpowiedniego przedzialu to metoda przekaze nam element do zadanej struktury p
	{
		for (i = 0; i <= kr; i++)
		{
			if (i == kr)
			{
				p = curr->p;
				return res_ok;
			}
			curr = curr->next;
		}
		
		
	}
}

size_t CList::size() const ///zwraca ilosc elementow listy
{
	
		/*list_el *curr = first;
		size_t rozmiar = 0;
		
		while (curr != 0)
		{
			rozmiar += sizeof(curr);
			curr = curr->next;
		}*/
		
		return count;
	
}

void CList::drawme() ///wypisuje elementy listy, uzywalem do testowania pozostalych metod
{
	using namespace std;

	list_el *it = first;
	
	do
	{
		cout << "{ x=" << it->p.x << ", y=" << it->p.y << ", z=" << it->p.z << " }" << endl;

		it = it->next;

	} while (it != 0);

}