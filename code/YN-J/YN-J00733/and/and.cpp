#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int a[10005];
	int n, m, cnt = 0, h = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int w = a[n];
	for (int i = 1; i <= m - 1; i++) {
		w = w & a[n - i];
	}
	cout << w;
	return 0;
}
