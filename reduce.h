#ifndef __REDUCE_H__
#define __REDUCE_H__

#include <vector>
#include <iostream>
#include <functional>

template <typename T, typename Op>
T reduceHelper(std::vector<T>& vec, Op op)
{
	auto size = vec.size();
	auto stepLen = size / 2 + size % 2;
	
	if (size == 1)
	{
		return vec[0];
	}
	
#pragma omp parallel for
	for (auto i = 0; i < (size / 2); i++)
	{
		vec[i] = op(vec[i], vec[i + stepLen]);
	}

	vec.resize(stepLen);
	reduceHelper(vec, op);
}

template <typename T, typename Op>
void reduce(std::vector<T>& vec, T& result, Op op)
{
	if (vec.size() == 0)
	{
		std::cout << "The vector size is 0, nothing to do.\n";
	}
	else if (vec.size() == 1)
	{
		result = vec[0];
	}
	else
	{
		std::vector<T> tmp = vec;
		result = reduceHelper(tmp, op);
	}
	return;
}

#endif /* __REDUCE_H__ */

