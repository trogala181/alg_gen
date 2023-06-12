#include <iostream>
#include "TPopulation.h"
#include "TCandidate.h"
using namespace std;

unsigned int TPop::count = 0;
unsigned int TPop::pops_count = 0;
TPop::TPop(int pop_count)
{
	TPop::count += 1;
	this->id = count;
	TPop::pops_count += pop_count;
	this->best_val = 0;

	for (int i = 0; i < pop_count; i++)
	{
		Tcandidate cand{};
		pops.push_back(cand);

	}
}
Tcandidate TPop::get_best_candidate()
{
	int size = this->pops.size();
	double best_cand_id = -1;
	for (int i = 0; i < size; i++)
	{
		if (pops[i].get_mark() > best_val)
			best_val = pops[i].get_mark();
	}
	for (int i = 0; i < size; i++)
	{
		if (pops[i].get_mark() == best_val)
			best_cand_id = i;
	}
	return pops[best_cand_id];
};
void TPop::calculate()
{
	int size = this->pops.size();
	for (int i = 0; i < size; i++)
	{
		pops[i].rate();
	}
}
void TPop::info()
{
	int size = this->pops.size();
	
	cout << "\n===== Population " << this->id << "/" << count << "=====\n";
	int j = 0;
	for (int i=0; i < size; i++)
	{
		
		cout << "==Candidate"<<j<<": " << pops[i].get_mark()<<"\n";
		j += 1;
	}
}