#pragma once

#include <cmath>
#include <cstddef>
#include <type_traits>
#include <complex>
#include "Eigen/Dense"

namespace three_phase_tensor {

struct Asym {
	double a, b, c;
};


using DoubleComplex = std::complex<double>;

template<class T>
using Vector3P = Eigen::Array<T, 3, 1, Eigen::DontAlign>;

template<class T>
using Tensor3P = Eigen::Array<T, 3, 3, Eigen::RowMajor | Eigen::DontAlign>;

using Array3P = Eigen::Array<double, 3, 1, Eigen::DontAlign>;

class Vector3PReal : public Array3P
{
public:
	Vector3PReal() = default;
	// This constructor allows you to construct MyVectorType from Eigen expressions
	template<typename OtherDerived>
	Vector3PReal(const Eigen::ArrayBase<OtherDerived>& other)
		: Array3P(other)
	{ }
	// This method allows you to assign Eigen expressions to MyVectorType
	template<typename OtherDerived>
	Vector3PReal& operator=(const Eigen::ArrayBase <OtherDerived>& other)
	{
		this->Array3P::operator=(other);
		return *this;
	}
	// convert from T
	Vector3PReal(Asym const& t) {
		*this << t.a, t.b, t.c;
	}
	
	operator Asym() {
		Asym t;
		t.a = (*this)(0);
		t.b = (*this)(1);
		t.c = (*this)(2);

	}
};

inline double vector_kron_product(double x, double y) {
	return x * y;
}
template <typename DerivedA, typename DerivedB>
inline auto vector_kron_product(
	Eigen::ArrayBase<DerivedA> const& x, 
	Eigen::ArrayBase<DerivedB> const& y) {
	return (x.matrix() * y.matrix().transpose()).array();
}

inline double tensor_vector_mult(double x, double y) {
	return x * y;
}
inline DoubleComplex tensor_vector_mult(DoubleComplex x, DoubleComplex y) {
	return x * y;
}
template <typename DerivedA, typename DerivedB>
inline auto tensor_vector_mult(
	Eigen::ArrayBase<DerivedA> const& x,
	Eigen::ArrayBase<DerivedB> const& y) {
	return (x.matrix()  * y.matrix()).array();
}

template<bool sym>
using RealTensor = std::conditional_t<sym, double, Tensor3P<double>>;
template<bool sym>
using ComplexTensor = std::conditional_t<sym, DoubleComplex, Tensor3P<DoubleComplex>>;
template<bool sym>
using RealValue = std::conditional_t<sym, double, Vector3PReal>;
template<bool sym>
using ComplexValue = std::conditional_t<sym, DoubleComplex, Vector3P<DoubleComplex>>;


struct Ha {
	size_t o;
	RealTensor<false> a;
	ComplexTensor<false> b;
	RealValue<false> c;
	ComplexValue<false> d;
	double x;
	bool y;
	int z;
};


struct X {
	int8_t x;
	Asym t;
	double y;
};

struct Y {
	size_t xx;
	X x;
	Asym t;
	bool opt;
};

struct Ho {
	int lambda;
	Ha ha;
	double theta;
};

constexpr bool a = std::is_standard_layout_v<Ho>;
constexpr bool b = std::is_pod_v<Ho>;

constexpr bool c = std::is_standard_layout_v<Y>;
constexpr bool d = std::is_pod_v<Y>;

constexpr size_t a1 = offsetof(Y, x.t.b);


inline void func() {
	RealValue<false> vec;
	vec << 1, 2, 3;
	Asym t = vec;
	vec = t;
}
}

