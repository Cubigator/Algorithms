#pragma once
#include <vector>


template<typename T>
typename std::vector<T> Merge(const std::vector<T>& arr1, const std::vector<T>& arr2) {
	size_t i = 0;
	size_t j = 0;
	std::vector<T> result;
	for (size_t k = 0; k < arr1.size() + arr2.size(); k++)
	{
		if (i >= arr1.size()) {
			result.push_back(arr2[j++]);
			continue;
		}
		if (j >= arr2.size()) {
			result.push_back(arr1[i++]);
			continue;
		}
		if (arr1[i] < arr2[j]) {
			result.push_back(arr1[i++]);
		}
		else {
			result.push_back(arr2[j++]);
		}
	}
	return result;
}

template<typename T>
typename std::vector<T> merge_sort(const std::vector<T>& arr) {
	if (arr.size() < 2)
		return arr;
	size_t i = 0;
	std::vector<T> C;
	for (; i < arr.size() / 2; i++)
	{
		C.push_back(arr[i]);
	}
	std::vector<T> D;
	for (; i < arr.size(); i++)
	{
		D.push_back(arr[i]);
	}
	C = merge_sort(C);
	D = merge_sort(D);
	return Merge(C, D);
}