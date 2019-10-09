#pragma once

#include <cmath>
#include <cstddef>
#include <type_traits>
#include <complex>
#include "Eigen/Dense"

namespace three_phase_tensor {

using DoubleComplex = std::complex<double>;

template<class T>
using Vector3P = Eigen::Matrix<T, 3, 1, Eigen::DontAlign>;

template<class T>
using Tensor3P = Eigen::Matrix<T, 3, 3, Eigen::RowMajor | Eigen::DontAlign>;

template<class T>
using Diag3P = Eigen::DiagonalMatrix<T, 3>;


inline double vector_kron_product(double x, double y) {
	return x * y;
}
template<class T>
inline auto vector_kron_product(Vector3P<T> x, Vector3P<T> y) {
	return x * y.transpose();
}

inline double ele_mult(double x, double y) {
	return x * y;
}
inline DoubleComplex ele_mult(DoubleComplex x, DoubleComplex y) {
	return x * y;
}
template<class T>
inline auto ele_mult(Vector3P<T> x, Vector3P<T> y) {
	return x.cwiseProduct(y);
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

