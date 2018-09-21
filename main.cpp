#include "Polynomial.h"

int main(int argc, char** argv)
{
	Polynomial a,b;
	a.setPolynomial();
	a.print();
	b.setPolynomial();
	b.print();
	(a+b).print();
	(a-b).print();
	(a*b).print();
	return 0;
}

