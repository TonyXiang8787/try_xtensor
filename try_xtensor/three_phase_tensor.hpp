#pragma once

#include <cmath>
#include <cstddef>
#include <type_traits>
#include <complex>
#include "Eigen/Dense"

namespace three_phase_tensor {

using DoubleComplex = std::complex<double>;

template<class T>
using Vector3P = Eigen::Array<T, 3, 1, Eigen::DontAlign>;

template<class T>
using Tensor3P = Eigen::Array<T, 3, 3, Eigen::RowMajor | Eigen::DontAlign>;


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
using RealValue = std::conditional_t<sym, double, Vector3P<double>>;
template<bool sym>
using ComplexValue = std::conditional_t<sym, DoubleComplex, Vector3P<DoubleComplex>>;


}

