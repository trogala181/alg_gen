#include "TParam.h"
#include <math.h>	// fabs
#include <stdlib.h> // rand

using namespace std;

unsigned int Tparam::gens_count = 0;

Tparam::Tparam(double min, double max, double step, double val): Tparam::Tparam(min,max,step)
{
	id = get_val_id(val);
}
Tparam::Tparam(double min, double max, double step) : name{""}, opis{""}, id{0}
{
	gens_count++;
	_id = gens_count;
	set_range(min, max, step);
	set_rand_val();
}
Tparam::Tparam(string name, string opis, double min, double max, double step) : Tparam::Tparam(min, max, step)
{
	set_name(name);
	set_des(opis);

}

Tparam::Tparam(const Tparam &kopia)
{
	this->name = kopia.name;
	this->opis = kopia.opis;
	this->min = kopia.min;
	this->max = kopia.max;
	this->step = kopia.step;

	set_rand_val();
	id += 1;

	gens_count++;
	_id = gens_count;

}

Tparam::~Tparam()
{
	//cout << "usunieto gen o nazwie: " << name << ", id: " << _id << "\n";
}

void Tparam::set_range(double min, double max, double step)
{
	this->min = min;
	this->max = max;
	this->step = step;

}

int Tparam::get_val_id(double val)
{
	if (val < min) return 0;

	else if (val > max) return (max - min) / step;

	else
	{
		double x = min;
		int _id = 0;

		while (fabs(x + _id * step - val) > step / 2) _id++;

		return _id;
	}

}

void Tparam::set_rand_val()
{
	int vals_count = fabs(max - min) / step + 1;
	id = rand() % vals_count;
}

/*
double Tparam::get_val(double val_check)
{
	double i = fmod(val_check, step); //reszta z dzielenia prx

	if (i != 0)
	{
		double dol = val_check - floor(val_check);
		double gora = ceil(val_check) - val_check;
		if (dol >= gora)
		{
			if (gora < abs(ceil(val_check) - step - val_check))
			{
				val_check = ceil(val_check);
			}
			else
			{
				val_check = ceil(val_check) - step;
			}
		}
		else
		{
			if (dol < abs(floor(val_check) + step - val_check))
			{
				val_check = floor(val_check);
			}
			else
			{
				val_check = floor(val_check) + step;
			}
		}

	}
	return val_check;
}
*/ // stary get_val

/*
void Tparam::set_val(double new_val)
{
	new_val = get_val( new_val );
	
	if (new_val <= this->min)
	{
		this->val = double(min);
	}
	else if (new_val >= this->max)
	{
		this->val = double(max);
	}
	else
	{
		this->val = new_val;
	}
	this->_id= (val - min) / step;
}
*/

void Tparam::info()
{
	cout << "+++++++++++++++++++++++++++++\n"
		<< get_name() << "   " << get_des() << "\n"
		<< "Wartosc min: "
		<< this->min << "\n"
		<< "Wartosc max: "
		<< this->max << "\n"
		<< "Krok: "
		<< this->step << "\n"
		<< "Wartosc: "
		<< get_val() << "\n"
		<< "Id wartosci: " << id <<"\n"
		<< "+++++++++++++++++++++++++++++\n";

}