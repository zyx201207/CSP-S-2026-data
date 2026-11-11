#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	long long int a[200005], b = 0;
	vector<long long int> v;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			v.push_back(a[j + i]);
		}
		b = max(b, v[0] & v[1]);
		v.clear();
	}
	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
	}
	cout << b;
	return 0;
}