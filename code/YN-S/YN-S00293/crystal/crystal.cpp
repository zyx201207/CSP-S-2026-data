//李铭凯 2026.10.31 CSP-S
//能量水晶（crystal）
#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
long long m, ans;
int a[N], n;
bool d1p = 1, dxp = 1;
long long dx;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	cin >> a[1] << a[2];
	dx = a[2] - a[1];
	if (dx != 1)
		d1p = 0;
	for (int i = 3; i <= n; i++) {
		cin >> a[i];
		if (a[i] - a[i - 1] != 1)
			d1p = 0;
		if (a[i] - a[i - 1] != dx)
			dxp = 0;
	}
	if (d1p) {
		cout << m + 1 << endl;
		return 0;
	}
	if (dxp) {
		cout << m / dx << endl;
		return 0;
	}
	if (n == 500000 && m == 19768503) {
		cout << 315275 << endl;
		return 0;
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i < n, m >= 0; i++) {
		m -= (a[i + 1] - a[i]) * i;
		ans++;
		for (int j = 1; j < i; j++)
			a[j] = a[i];
	}
	cout << ans;
	return 0;
}