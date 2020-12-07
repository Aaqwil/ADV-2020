#include <concepts>
#include <iostream>
#include <vector>
#include <complex>

using namespace std::complex_literals;

template<std::floating_point T>
std::complex<T> UseComplex(T x, std::complex<T> y = 1.0)
{
	std::complex<T> z = x + static_cast<std::complex<T>>(2.0i);
	return z + y + x;
}

int main()
{
	std::complex<long double> z = 9.9 + 9.9i;
	std::complex<float> z2 = 4.0f;
	std::cout << UseComplex(2.1l, z) << std::endl;
	std::cout << UseComplex(2.1, 1i) << std::endl;
	std::cout << UseComplex(2.0f) << std::endl;
	std::cout << UseComplex(2.0f, z2) << std::endl;
	std::cout << UseComplex(2.0f, std::complex{4.0f}) << std::endl;
	//std::cout << UseComplex(2.0f, 4.0f) << std::endl;
	//std::cout << UseComplex(2) << std::endl;
	//std::cout << UseComplex(2, 17i) << std::endl;
}