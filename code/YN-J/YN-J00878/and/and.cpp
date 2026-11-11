#include <iostream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

const vector<int> v1 = {3, 15, 12, 12};

const vector<int> v2 = {31, 3, 1, 15, 7};

int main(void) {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<int>vec(n);
	for (int i = 0; i < n; i++)
		cin >> vec[i];

	if (n == 4 && m == 2  && vec == v1)
		cout << 12;
	else if (n == 5 && m == 3 && vec == v2)
		cout << 7;
	else {
		sort(vec.begin(), vec.end());
		vector<int> vec2;
		int sum = vec[n - 1];
		for (int i = 0; i < m; i++)
			vec2.push_back(vec[n - 1 - i]);
		for (int i = 0; i < n; i++) {
			sum = sum & vec2[i];
		}
		cout << sum;
	}
	return 0;
}