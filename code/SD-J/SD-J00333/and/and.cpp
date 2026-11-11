#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <functional>
using namespace std;
int n, m;
vector<long long> v;
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		long long w;
		cin >> w;
		v.push_back(w);
	}
	sort(v.begin(), v.end(), greater<long long>());
	if (m == 1) {
		cout << v[0];
		return 0;
	}
	unsigned long long a = v[0];
	for (int i = 1; i < m; i++) {
		a &= v[i];
	}
	cout << a;
	return 0;
}
