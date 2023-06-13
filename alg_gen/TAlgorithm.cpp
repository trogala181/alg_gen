#include <iostream>
#include "TAlgorithm.h"

using namespace std;

TAlg::TAlg(int pop_count, int max_generation_count, int progress_cap)
{
	this->best_ogcand_val = 0;
	wsk_pop_next = new TPop(pop_count);
	wsk_pop_prev = wsk_pop_next;
	wsk_pop_next->calculate();
	
	double best_cand_val = wsk_pop_next->get_best_candidate().get_mark();
	int progress_check = 0;
	int ending_cond = 0;
	int j = 0;
	
	while (ending_cond==0) 
	{
		j += 1;
		wsk_pop_prev = wsk_pop_next;
		
		if (best_ogcand_val < best_cand_val)
		{
			progress_check = 0;
			this->best_ogcand_val = best_cand_val;
		}
		
		cout << "Best value of candidate in " << j  << " generation: " << best_cand_val << "\n";
		
		wsk_pop_next = new TPop(pop_count);
		
		/////
		wsk_pop_next->pops[0] = wsk_pop_prev->get_best_candidate();
		for (int i=1;i<pop_count;i++)
		{
			int los = rand() % 100 + 1;
			
			int cand1_id = wsk_pop_prev->get_random_waged_cand_id();
			int cand2_id = wsk_pop_prev->get_random_waged_cand_id();
			if (los > 80)
			{
				wsk_pop_next->pops[i] = wsk_pop_next->pops[cand1_id];
			}
			else if (los < 40)
			{
				wsk_pop_next->pops[i].crossing(wsk_pop_prev->pops[cand1_id], wsk_pop_prev->pops[cand2_id]);
			}
			else
			{
				wsk_pop_next->pops[i] = wsk_pop_next->pops[cand1_id];
				wsk_pop_next->pops[i].mutating();
			}

		}
		/////
		
		wsk_pop_next->calculate();
		
		best_cand_val = wsk_pop_next->get_best_candidate().get_mark();
		progress_check += 1;
		
		if (progress_cap == progress_check)
		{
			ending_cond = 1;
			
		}
		
		if (j == max_generation_count)
		{
			ending_cond = 1;
		}
	}

	cout << "\nBest value of all time:" << this->best_ogcand_val;
	
	delete wsk_pop_next;
	delete wsk_pop_prev;

}