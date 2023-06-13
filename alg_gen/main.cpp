#include <iostream>
#include <ctime>
#include <stdlib.h>

#include "Tcandidate.h"

#include "TPopulation.h"
#include "TAlgorithm.h"
#include "TParam.h"

//#include "TKlasa.h"


using namespace std;


int main()
{
	srand(time(NULL));

	/*TPop pop1(10);
	
	pop1.info();
	pop1.calculate();
	pop1.info();

	pop1.get_best_candidate().info();*/

	TAlg alg1(20);

	/*Tparam param1(0, 10, 0.5);
	Tparam param2(10, 20, 0.25,15);
	Tparam param3("parametr 3","opis zbedny",30., 40, 1);
	Tparam param4(param3);
	
	param1.info();
	param2.info();
	param3.info();
	param4.info();
	Tcandidate osobnik1{};
	Tcandidate osobnik2(osobnik1);
	osobnik1.rate();
	osobnik2.rate();

	osobnik1.info();
	osobnik2.info();*/

	/*Tcandidate osobnik1{};
	Tcandidate osobnik2{};
	Tcandidate osobnik3{};
	osobnik1.info();
	osobnik2.info();
	osobnik3.info();
	osobnik3.crossing(osobnik1, osobnik2);
	osobnik3.info();*/

	
	return 0;
}