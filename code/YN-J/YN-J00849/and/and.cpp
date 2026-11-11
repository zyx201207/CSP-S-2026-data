#include <bits/stdc++.h>
using namespace std;
long long a[100001];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int maxn = -9999;
	for (int i = 1; i <= n; i++) {
		int n = a[i];
		int m = 0;
		m = a[i + i] % a[i];
		cout << max(n, m);
	}
	return 0;
}