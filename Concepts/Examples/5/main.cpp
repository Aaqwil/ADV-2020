void f(std::vector<int> i)
{
	///
}

template<typename T>
concept WithSizeMethod = requires(T a)
{
	{ a.size() } -> std::convertible_to<unsigned>;
	{ f(a) };
};

int main()
{

}