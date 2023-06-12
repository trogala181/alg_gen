#pragma once
#include <iostream>
#include "TCandidate.h"
#include "TParam.h"
#include <vector>

class TPop
{
	static unsigned int count;
	static unsigned int pops_count;
	unsigned int id;
	
	double best_val;
public:
	
	TPop(int pop_count);
	void calculate();
	Tcandidate get_best_candidate();
	void info();
	std::vector <Tcandidate> pops;
	
};