#pragma once
#include <iostream>
#include "TPopulation.h"

class TAlg
{
	TPop* wsk_pop_prev;
	TPop* wsk_pop_next;
	double best_ogcand_val;
public:
	TAlg(int pop_count, int max_generation_count = 20, int progress_cap = 10);

};