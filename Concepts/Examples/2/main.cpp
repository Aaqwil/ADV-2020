#include <concepts>
#include <iostream>
#include <vector>

template<typename f, typename r, typename... args>
concept Function =
requires(f function, args&&... arguments)
{
	{ function(std::forward<args>(arguments)...) } -> std::convertible_to<r>;
};


template<typename T, typename func>
T f1(func g, T x)
{
	std::cout << "f1 ";
	return g(x);
}

template<typename T, typename func>
requires Function<func, T, T>
T f2(func g, T x)
{
	std::cout << "f2 ";
	return g(x);
}

template<typename T, typename func>
requires Function<func, T>
T f3(func g, T x)
{
	std::cout << "f3 ";
	return g();
}

int z(int a) { return a; }
int z1(int a) { return a; }
int z2(int a) { return a; }
std::vector<int> z4(int a) { return std::vector<int>{a}; }

int main()
{
	z(9);
	std::cout << f1(z, 9) << std::endl;
	std::cout << f1(z1, 9) << std::endl;
	std::cout << f1(z2, 9) << std::endl;
	//f1(2, 9);

	std::cout << std::endl;

	//f2(2, 9);
	std::cout << f2(z, 9) << std::endl;
	std::cout << f2([](int x) {return x + 1; }, 9) << std::endl;
	std::cout << f3([]() {return 1; }, 9) << std::endl;
}