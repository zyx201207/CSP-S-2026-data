#include <bits/stdc++.h>
using namespace std;
long long  a[100000], b[1000000];

int main() {
	freopen (" and.in", "r", stdin);
	freopen (" and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			b[i * j] = a[i] & a[j];
	sort(b + 1, b + n + 1);
	cout << b[n * n];
	return 0;
}