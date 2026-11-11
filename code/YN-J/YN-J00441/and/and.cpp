#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<int> vec(n);
	for (int i = 0; i < n; i++)
		cin >> vec[i];
	sort(vec.begin(), vec.end());
	cout << vec[m - 1];
	return 0;
}