#include <concepts>
#include <iostream>
#include <vector>

template<typename T>
class A
{
public:
	
	A(T x) 
	requires std::floating_point<T>
	{	std::cout << "F " << x << std::endl; }

	A(T x)
	requires std::integral<T>
	{	std::cout << "I " << x << std::endl; }

	A(T x)
	requires (not std::integral<T> and not std::floating_point<T>)
	{	std::cout << "Other " << x << std::endl; }

	void f()
	requires std::floating_point<T>
	{	std::cout << "floating_method" << std::endl; }

	void f()
	{	std::cout << "not_floating_method" << std::endl; }
};

template<typename T>
struct B{
	B(T l){ std::cout << "regular " << l << std::endl;}
};

template<std::floating_point T>
struct B<T>{
	B(T l){ std::cout << "specialized for fp " << l << std::endl;}
};

template<std::integral T>
struct B<T>{
	B(T l){ std::cout << "specialized for int " << l << std::endl;}
};

int main()
{
	A a{6};
	A b{6.66};
	A c{6.66f};
	A d{std::string{"???"}};

	std::cout << std::endl;
	std::cout << std::endl;

	a.f();
	b.f();
	c.f();
	d.f();

	std::cout << std::endl;
	std::cout << std::endl;

	B e{1};
	B f{1.111};
	B g{6.666f};
	B h{"other"};
}


