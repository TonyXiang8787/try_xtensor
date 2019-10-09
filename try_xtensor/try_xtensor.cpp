// try_xtensor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "three_phase_tensor.hpp"


int main()
{
	using namespace three_phase_tensor;

	RealValue<false> a;
	a << 1, 2, 3;
	RealValue<false> a1;
	a1 << 4, 5, 6;
	RealTensor<false> b;
	b << 1, 2, 3, 4, 5, 6, 7, 8, 9;

	RealValue<false> c = b * a;
	RealTensor<false> d = vector_kron_product(a, a1);
	RealValue<false> e = ele_mult(a, a1) + a;

	std::cout << d << '\n';
	std::cout << e << '\n';

    std::cout << "Hello World!\n"; 
}
