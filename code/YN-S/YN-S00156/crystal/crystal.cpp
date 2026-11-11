#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long n, m, a[N], less;

bool jc() {
	for (int i = 2; i < n; i++) {
		if ((a[i] + a[i] - a[i - 1]) != a[i + 1])
			return 0;
	}
	return 1;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	if (jc()) {
		if (a[2] - a[1] == 1) {
			int del = 1 + 9 * m;
			int ans = ((int)(sqrt(del)));
			ans--;
			if (ans % 2 == 0)
				ans /= 2;
			else
				ans = ans / 2 + 1;
			cout << ans;
			return 0;
		} else {
			int k = a[2] - a[1];
			int del = 1 + (8 * m) / k;
			int ans = ((int)(sqrt(del)));
			ans--;
			if (ans % 2 == 0)
				ans /= 2;
			else
				ans = ans / 2 + 1;
			cout << ans;
			return 0;
		}
	}
	if (m % 2 == 0)
		cout << m / 2;
	else
		cout << m / 2 + 1;
	return 0;
	fclose(stdin);
	fclose(stdout);
}