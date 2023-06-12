#pragma once
#include <iostream>
#include "TCandidate.h"

class TKlasa
{
	static unsigned int count;
	static unsigned int vector_size;
	int init_val;
	unsigned int _id;
public:
	TKlasa(int init_val);

	void set_vector_size(unsigned int size);
	void set_init_val(int init_val);
	void info();

};