#include <iostream>
#include <type_traits>
#include <concepts>
#include <vector>

template<typename T>
concept Integer = std::is_integral_v<T>;


template<Integer number>
number function(number x)
{
	return x;
}


template<typename T>
	requires std::is_integral_v<T>
T function(T argument)
{
	return argument;
}



int main()
{
	static_assert(Integer<int>);
	return 0;
}