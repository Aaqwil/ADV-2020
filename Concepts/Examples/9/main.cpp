#include <concepts>
#include <iostream>
#include <vector>
#include <algorithm>


int main()
{
	std::vector<int> v1{1, 14, 929, 0, 28};
	std::vector<int> v2{1, 14, 929, 0, 28};

	auto p = [](std::vector<int>& x){
		for(auto i : x)
			std::cout << i << " ";
		std::cout << std::endl;
	};

	std::sort(v1.begin(), v1.end());
	p(v1);

	std::ranges::sort(v2);
	p(v2);

	auto a = 17;
	//std::floating_point auto b = 16;
}