#pragma once
#include <iostream>
#include <vector>
#include "TParam.h"

#define GENS_COUNT 2

class Tcandidate
{
	Tparam genotype[GENS_COUNT] = 
	{
		Tparam ("x1","", 0,100,1),
		Tparam ("x2","", 0, 100,1)
	};
	
	double mark;

public:
	Tcandidate();
	Tcandidate(const Tcandidate &kopia);

	double get_mark() { return mark; };
	void rate();
	void info();
	void crossing(Tcandidate cand1, Tcandidate cand2);
	void mutating();
private:
	void rand_gens_val();
};
