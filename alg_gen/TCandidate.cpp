#include <iostream>
#include <math.h>

#include "TCandidate.h"

using namespace std;

Tcandidate::Tcandidate()
{	
	mark = 0;
	//rand_gens_val();

}
void Tcandidate::crossing(Tcandidate cand1, Tcandidate cand2)
{
	double los = rand() % 100 + 1;
	
	if (los > 50)
	{
		this->genotype[0] = cand1.genotype[0];
		this->genotype[1] = cand2.genotype[1];
	}
	else
	{
		this->genotype[0] = cand2.genotype[0];
		this->genotype[1] = cand1.genotype[1];
	}
	
}
void Tcandidate::mutating()
{
	double los = rand() % 100 + 1;
	if (los > 50)
	{
		genotype[0].set_val(genotype[0].get_val() + genotype[0].get_step());
	}
	else
	{
		genotype[0].set_val(genotype[0].get_val() - genotype[0].get_step());
	}
}
Tcandidate::Tcandidate(const Tcandidate &kopia)
{
	mark = kopia.mark;
	for (int i = 0; i < GENS_COUNT; i++)
	{
		double gen_val = kopia.genotype[i].get_val();
		(genotype[i]).set_val(gen_val);
	}

}

void Tcandidate::rand_gens_val()
{
	for (int i = 0; i < GENS_COUNT; i++)
	{
		genotype[i].set_rand_val();
	}
}
void Tcandidate::rate()
{
	double ocena = 0;
	ocena = genotype[0].get_val() * 10 + genotype[1].get_val() * 1;
	this->mark = ocena;
}

void Tcandidate::info()
{
	cout << "===== Genotype =====\n";
	cout << "++ gens count: " << GENS_COUNT << "\n";

	for (int i = 0; i < GENS_COUNT; i++)
	{
		cout << "++" << genotype[i].get_name() << ": " << genotype[i].get_val() << "\n";

	}
	cout << "++ \n";
	cout << "++ rate: " << mark << "\n";
	cout << "=====================";

}