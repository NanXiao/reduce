# ReduceAddition
A simple reduce template implemented in C++.
## Example

	#include "reduce.h"

	int main(void)
	{
		std::vector<int> odd = {1, 2, 3, 4, 5};
		std::vector<int> even = {1, 2, 3, 4};
	
		int result = 0;
		reduce(odd, result, std::plus<int>());
		std::cout << result << '\n';
	
		reduce(even, result, std::plus<int>());
		std::cout << result << '\n';
	}
Compile:  

	g++ -fopenmp  main.cpp

Run:  

	# ./a.out
	15
	10


