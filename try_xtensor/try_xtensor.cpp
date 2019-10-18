// try_xtensor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "three_phase_tensor.hpp"
#include <cmath>


int main()
{
	using namespace std::complex_literals;
	using namespace three_phase_tensor;

	RealValue<false> a;
	a << 1, 2, 3;
	RealValue<false> a1;
	a1 << 4, 5, 6;
	RealTensor<false> b;
	b << 1, 2, 3, 4, 5, 6, 7, 8, 9;

	RealValue<false> c = tensor_vector_mult(b, a);
	RealTensor<false> d = vector_kron_product(a, a1 + a);
	RealValue<false> e = (a + c) * a;
	RealTensor<false> f = sin(b + d);
	ComplexTensor<false> g =  f * exp(1.0i * b);

	std::cout << a << '\n';
	std::cout << a1 << '\n';
	std::cout << b << '\n';
	std::cout << c << '\n';
	std::cout << d << '\n';
	std::cout << e << '\n';
	std::cout << f << '\n';
	std::cout << g << '\n';
    std::cout << "Hello World!\n"; 
}
