#include <concepts>
#include <iostream>
#include <vector>



template <typename T, typename = typename std::enable_if_t<std::is_integral_v<T>>>
T f1(T x, T y)
{
   return x + y;
}

template<std::integral T>
T f2(T x, T y)
{
	return x + y;
}

int main()
{
	f1(1, 14);
	f2(1, 14);
	//f1(std::string{"nie"}, std::string{"wiem"});
	//f2(std::string{"nie"}, std::string{"wiem"});
}