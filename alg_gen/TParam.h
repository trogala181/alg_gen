#pragma once
#include <iostream>
#include <string>

class Tparam
{ 
	static unsigned int gens_count;
	unsigned _id;

	std::string name, opis;
	double min,max,step; 
	int id;

public:
	Tparam(double min, double max, double step, double val);
	Tparam(double min, double max, double step);
	Tparam(std::string name, std::string opis, double min, double max, double step);
	Tparam(const Tparam &kopia);

	~Tparam();

	void set_name(std::string name) { this->name = name; }
	std::string get_name() { return name; }

	void set_des(std::string opis) { this->opis = opis; }
	std::string get_des() { return opis; }

	void set_range(double min, double max, double step);
	void set_val(double val) { this->id = get_val_id(val); }
	void set_rand_val();

	double get_step() { return this->step; }
	double get_val() const { return min + id * step; }
	
	int get_step_ratio() { return ((this->max - this->min) / this->step);  }
	
	
	void info();
private:
	int get_val_id(double val);
	
};