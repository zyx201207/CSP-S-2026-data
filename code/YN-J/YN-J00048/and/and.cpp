#include <bits/stdc++.h>
using namespace std;

int f (int a, int b) {
	int arra[31] = {0}, arrb[31] = {0}, arrc[31] = {0}, ans = 0;
	for (int i = 0; i < 31; i++) {
		if (a % 2 == 0)
			arra[i] = 0;
		else if (a % 2 != 0)
			arra[i] = 1;
		a /= 2;
		if (b % 2 == 0)
			arrb[i] = 0;
		else if (b % 2 != 0)
			arrb[i] = 1;
		b /= 2;
	}
	for (int i = 30; i >= 0; i--) {
		ans *= 2;
		if (arra[i] && arrb[i])
			ans++;
	}
	return ans;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int m, n, a[200009] = {}, b[200009] = {0};
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + m);
	int ans = a[m];
	for (int i = m - 1; i >= m - n + 1; i--)
		ans = f(ans, a[i]);
	cout << ans;
	return 0;
}