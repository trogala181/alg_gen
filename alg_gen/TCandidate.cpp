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
	for (int i = 0; i < GENS_COUNT; i++)  // przejscie po kazdym genie rodzicow
	{
		double los = rand() % 100 + 1; // los którego rodzica przejdzie do potomka
		
		if (los > 50)
		{
			this->genotype[i] = cand1.genotype[i];
		}
		else
		{
			this->genotype[i] = cand2.genotype[i];
		}
	}
	
}
void Tcandidate::mutating()
{
	
	int ile_mutacji = rand() % GENS_COUNT; // losowanie liczby ile razy ma zajœæ mutacja
	
	for (int i = 0; i < ile_mutacji; i++)
	{
		int wybor_gen = rand() % GENS_COUNT; // losowanie który gen zostanie zmutowany tym razem
		int size_of_mutation = rand() % this->genotype[wybor_gen].get_step_ratio()/10;
		double los = rand() % 100 + 1; // losowanie wartoœci czy wprzód czy do ty³u
		
		if (los > 50)
		{
			genotype[wybor_gen].set_val(genotype[wybor_gen].get_val() + size_of_mutation);
		}
		else
		{
			genotype[wybor_gen].set_val(genotype[wybor_gen].get_val() - size_of_mutation);
		}

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