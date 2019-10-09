// try_xtensor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "three_phase_tensor.hpp"


int main()
{
	using namespace three_phase_tensor;

	ComplexValue<false> a;
	a << 1, 2, 3;
	ComplexTensor<false> b;
	b << 1, 2, 3, 4, 5, 6, 7, 8, 9;

	ComplexValue<false> c = tensor_vector_mult(b, a);
	ComplexValue<false> d = vector_kron_product(a, a);
	std::cout << c << '\n';

    std::cout << "Hello World!\n"; 
}
