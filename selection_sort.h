#pragma once
#include <vector>

template<typename T>
typename std::vector<T>::const_iterator findSmallest(const std::vector<T>& arr)
{
	T buf = arr[0];
	typename std::vector<T>::const_iterator iter = arr.begin();
	for (size_t i = 0; i < arr.size(); i++)
	{
		if (arr[i] < buf) {
			buf = arr[i];
			iter = arr.begin() + i;
		}
	}
	return iter;
}



template <typename T>
std::vector<T> selection_sort(std::vector<T>& arr) {
	size_t size = arr.size();
	std::vector<T> newArr;
	typename std::vector<T>::const_iterator buf = arr.begin();
	for (size_t i = 0; i < size; i++)
	{
		buf = findSmallest(arr);
		newArr.push_back(*buf);
		arr.erase(buf);
	}
	return newArr;
}