#ifndef _COMPLEX_NUMBER_H_
#define _COMPLEX_NUMBER_N_

#include <cmath>
#include <iostream>
#include <cassert>



class complex_number
{
public:
	
complex_number(double r = 0.0, double i = 0.0)
{
	// postcondition: complex with given components has been created
	real_part = r;
	imag_part = i;

}
double get_real_part() const
{
	// returned: real part of complex number
	return real_part;
}
  double get_imag_part () const
  {
	  // returned: imaginary part of complex number
	  return imag_part;
  }
private:
  double real_part;
  double imag_part;
};


complex_number operator + (const complex_number& c1, const complex_number& c2)
{
	// returned: sum of c1 and c2
	const double x = c1.get_real_part() + c2.get_real_part();
	const double y = c1.get_imag_part() + c2.get_imag_part();
	
	return complex_number(x, y);

}
complex_number operator - (const complex_number& c1, const complex_number& c2)
{
	// returned: difference of c1 and c2
	const double x = c1.get_real_part() - c2.get_real_part();
	const double y = c1.get_imag_part() - c2.get_imag_part();

	return complex_number(x,y);
}

complex_number operator * (const complex_number& c1, const complex_number& c2)
{
	// returned: product of c1 and c2
	double a = c1.get_real_part();
	double b = c1.get_imag_part();
	double c = c2.get_real_part();
	double d = c2.get_imag_part();

	const double x = (a*c) - (b*d);
	const double y = (a*d) + (b*c);
	
	return complex_number(x, y);
	
}

complex_number operator / (const complex_number& c1, const complex_number& c2)
{
	// precondition: c2 is not the zero of complex numbers
	// returned: quotient of c1 and c2
	//assert(c2.get_real_part() + c2.get_imag_part() == 0);

	double a = c1.get_real_part();
	double b = c1.get_imag_part();
	double c = c2.get_real_part();
	double d = -c2.get_imag_part();

	const double x = ((a*c) - (b*d)) / (pow(c,2) + pow(d,2));
	const double y = ((a*d) + (b*c)) / (pow(c,2) + pow(d,2));

	return complex_number(x, y);
}

complex_number conjugate(const complex_number& c)
{
	return complex_number(c.get_real_part(), -c.get_imag_part());	
}
double complex_modulus(const complex_number& c)
{
	// returned: modulus of c
	return sqrt((pow(c.get_real_part(), 2) + (pow(c.get_imag_part(), 2))));
}

bool operator == (const complex_number& c1, const complex_number& c2)
{
	// returned whether c1 and c2 are equal to each other
	if ((c1.get_real_part() + c1.get_imag_part()) == (c2.get_real_part() + c2.get_imag_part()))
	{
		return true;
	}
	else
	{
		return false;
	}

}
bool operator != (const complex_number& c1, const complex_number& c2)
{
	// returned whether c1 and c2 are not equal to each other
	if ((c1.get_real_part() + c1.get_imag_part()) != (c2.get_real_part() + c2.get_imag_part()))
	{
		return true;
	}
	else
	{
		return false;
	}
}
std::ostream& operator << (std::ostream& output, const complex_number& c)
{
	// postcondition: c has been put on the output stream output
	// returned: modified output stream output
	return output << c.get_real_part() << " + " << c.get_imag_part();
}

#endif
