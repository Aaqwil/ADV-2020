#include <concepts>
#include <iostream>
#include <vector>

template<typename T, typename U>
concept Comparable = requires(T a, U b)
{
	{ a == b } -> std::convertible_to<bool>;
	{ a != b } -> std::convertible_to<bool>;
	{ b == a } -> std::convertible_to<bool>;
	{ b != a } -> std::convertible_to<bool>;
};


template<typename T, typename U>
	requires Comparable<T, U>
bool f(T a, U b)
{
	return a == b;
}

using namespace std::string_literals;

int main()
{
	std::cout << f('c', 7) << std::endl;
	//std::cout << f("c"s, 7) << std::endl;

	static_assert(Comparable<float, int>);
	//static_assert(Comparable<std::string, int>);
}