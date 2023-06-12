#include <iostream>
#include "TKlasa.h"

using namespace std;

unsigned int TKlasa::count = 0;
unsigned int TKlasa::vector_size = 5;

TKlasa::TKlasa(int init_val) 
{
	TKlasa::count += 1;
	_id = TKlasa::count;
	this->init_val = init_val;

}

void TKlasa::set_vector_size(unsigned int size)
{
	TKlasa::vector_size = size;
}

void TKlasa::set_init_val(int init_val)
{
	TKlasa::init_val = init_val;
}

void TKlasa::info() 
{
	cout << "Obiekt klasy o numerze: " << _id << "/" << count;
	cout << "\nWartoœci: ";

	for (int i = 0; i < vector_size; i++)
	{
		cout << init_val + i << ", ";
	}
	cout << "\n\n";
}