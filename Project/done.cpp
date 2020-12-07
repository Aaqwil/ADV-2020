#include <concepts>
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

template<typename T>
concept base_container = requires(T o, T k)
{
	{ o.size() } -> std::convertible_to<unsigned>;
	{ o.size() } -> std::same_as<typename T::size_type>;
	{ o.max_size() } -> std::same_as<typename T::size_type>;
	{ o = k } -> std::same_as<T&>;
	{ o.~T() };
	{ o == k } -> std::convertible_to<bool>;
	{ o.empty() } -> std::convertible_to<bool>;
	{ o.swap(k) };
	{ swap(o, k) };
};

template<typename T>
concept vector_like_container = base_container<T>
and std::ranges::random_access_range<T> and
requires(T o)
{
	{ o.at(0) } -> std::same_as<typename T::value_type&>;
	{ o[0] } -> std::same_as<typename T::value_type&>;
};

template<typename T>
concept standard_library_container = base_container<T> or vector_like_container<T>;

template<typename T>
concept language_defined_array = std::ranges::random_access_range<T> and
requires(T o)
{
	{ o[0] } -> std::convertible_to<decltype(o[0])>;
	{ *o } -> std::convertible_to<decltype(*o)>;
};

template<typename T>
concept container = language_defined_array<T> or standard_library_container<T>;

template<typename T>
concept printable_via_operator = container<T> and
requires(T o)
{
	{ std::cout << o[0] };
};

template<typename T>
concept printable_via_method = container<T> and
requires(T o)
{
	{ std::cout << o.front() };
};

template<typename T>
concept container_of_printables = printable_via_method<T> or printable_via_operator<T>;

template<container T, typename U>
void fill_container_with(T& vector, U object_to_store)
{
	for (auto& x : vector)
		x = object_to_store;
}

template<container_of_printables T>
void print_container(const T& c)
{
	for (const auto& i : c)
		std::cout << i << " ";
	std::cout << std::endl;
}

int main()
{
	std::vector<int> a(10);
	fill_container_with(a, 10);
	print_container(a);

	std::array<unsigned, 5> b;
	fill_container_with(b, 5u);
	print_container(b);

	double c[15];
	fill_container_with(c, 9.9);
	print_container(c);

	return 0;
}