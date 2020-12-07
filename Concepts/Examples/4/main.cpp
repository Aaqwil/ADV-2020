#include <concepts>
#include <iostream>
#include <string>
#include <vector>


template<typename T>
concept Number = std::integral<T> or std::floating_point<T>;


template<typename T>
concept NumberTwo = requires(T a, T b)
{
	{ a + b } -> std::convertible_to<T>;
};


template<typename T>
concept NumberThree = requires(T a, T b)
{
	{ a + b } -> std::convertible_to<T>;
	{ a - b } -> std::convertible_to<T>;
	{ a * b } -> std::convertible_to<T>;
	{ a / b } -> std::convertible_to<T>;

	{ a += b } -> std::convertible_to<T&>;
	{ a -= b } -> std::convertible_to<T&>;
	{ a *= b } -> std::convertible_to<T&>;
	{ a /= b } -> std::convertible_to<T&>;
};


template<NumberThree T>
T f(T a, T b)
{
	return a + b;
}


template<typename T>
concept Concept_1 = std::integral<T>;
template<typename T>
concept Concept_2 = std::floating_point<T>;
template<typename T, typename U>
concept FinalConcept = Number<T> and NumberTwo<U>;


template<Concept_1 T, Concept_2 U>
	requires FinalConcept<T, U>
double func(T a, U b)
{
	return 1.0;
}


int main()
{
	std::cout << f(1, 3) << std::endl;
	//f(std::string{"nie"}, std::string{"wiem"});
}