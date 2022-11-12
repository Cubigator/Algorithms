#include <iostream>
#include <algorithm>
#include <ctime>

#include "selection_sort.h"
#include "binary_search.h"
#include "merge_sort.h"

using namespace std;


template<typename T>
T sum(vector<T> arr) {
	if (arr.empty())
		return 0;
	if (arr.size() == 1)
		return arr[0];
	if (arr[0] < arr[1])
		arr.erase(arr.begin());
	else
		arr.erase(arr.begin() + 1);
	return sum(arr);
}


int main() {
	vector<int> v;
	for (size_t i = 0; i < 10000; i++)
	{
		v.push_back(rand() % 10000);
	}
	int start = clock();
	vector<int> test1 = merge_sort(v);
	cout << "merge_sort: " << clock() - start << endl;
	start = clock();
	vector<int> test2 = selection_sort(v);
	cout << "selection_sort: " << clock() - start << endl;
	//copy(test.begin(), test.end(), ostream_iterator<int>(cout, " "));
	return 0;
}


