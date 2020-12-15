#include <concepts>
#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <list>

/*
	Poni¿ej znajduj¹ siê dwa szablony funkcji - oba proste i w pe³ni poprawne.
	Mo¿na ich u¿yæ bez ¿adnych modyfikacji w podanych w mainie przyk³adach, ale nie tylko w nich.
	Na pierwszy rzut oka widaæ, ¿e szablony nijak nie nadaj¹ siê dla wszystkich istniej¹cych typów danych.
	Zadanie polega na tym, ¿eby stworzyæ odpowiednie koncepty, które narzuc¹ na podane szablony poprawne wymagania.
	Po zbudowaniu konceptów u¿ycie szablonów nie powinno byæ sztucznie ograniczone - poprawne wczeœniej wywo³ania nadal powinny byæ poprawne.
	Podczas wykonywania zadania przydatne mog¹ byæ static_asserty oraz koncepty znajduj¹ce siê ju¿ w bibliotece standardowej.
	Nie nale¿y siê sugerowaæ iloœci¹ szablonów ani parametrów - poprawne rozwi¹zanie mo¿e siê sk³adaæ z dowolnej liczby dowolnie zbudowanych konceptów.
	Mo¿emy za³o¿yæ, ¿e ma³o standardowe kontenery nie istniej¹.

	Zadanie testowa³em w Visual Studio 2019 oraz z kompilatorem g++-10.
	W ¿adnym z tych przypadków nie by³o ¿adnych problemów z kompilacj¹ kodu.

	Zrealizowane zadanie powinno zawieraæ kompilowalny zestaw plików.
	Zestaw ten powinien oczywiœcie zawieraæ wszystkie wymagane koncepty oraz poni¿sze szablony w zmodyfikowanej odpowiednio wersji.
*/

template<typename T, typename U>
void fill_container_with(T& vector, U object_to_store)
{
	for (auto& x : vector)
		x = object_to_store;
}

template<typename T>
void print_container(const T& c)
{
	for (const auto& i : c)
		std::cout << i << " ";
	std::cout << std::endl;
}

struct object
{
	object() = default;
	object(std::string _) : m{ _ } {}

	std::string m = "default";

	friend std::ostream& operator<<(std::ostream& out, const object& o)
	{
		return out << o.m;
	}
};

int main()
{
	std::vector<int> a(10);
	fill_container_with(a, 10);
	print_container(a);

	std::array<std::string, 5> b;
	fill_container_with(b, "thing");
	print_container(b);

	double c[15];
	fill_container_with(c, 9.9);
	print_container(c);

	std::list<object> d(3);
	fill_container_with(d, object{ "initialized_object" });
	print_container(d);

	return 0;
}