#include <bits/stdc++.h>
using namespace std;

int m, n, a[200005], b[200005];
bool f(int a, int b) {
	return a > b;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1, f);
	for (int i = 1; i <= n - m + 1; i++) {
		b[i] = a[i];
		for (int j = i + 1; j <= i + m - 1; j++)
			b[i] &= a[j];
	}
	sort(b + 1, b + n - m + 2);
	cout << b[n - m + 1];
	return 0;
}