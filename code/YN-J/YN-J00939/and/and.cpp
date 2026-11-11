#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<long long> a = {};
	for (int i = 0; i < n; i++) {
		long long x;
		cin >> x;
		a.push_back(x);
	}

	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());

	cout << a[m - 1];

	return 0;
}
