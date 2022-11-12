#pragma once
#include <vector>

template <typename T>
int binary_search(const std::vector<T>& lst, const T& value) {
	int low = 0, high = lst.size() - 1;
	int mid;
	T buf;
	while (low <= high)
	{
		mid = (high + low) / 2;
		buf = lst[mid];
		if (buf == value)
			return mid;
		if (buf > value)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}