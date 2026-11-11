#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<int>a(n + 1);

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	sort(a.begin(), a.end());
	cout << a[n / 2];


	return 0;
}
