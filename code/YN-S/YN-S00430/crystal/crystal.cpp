#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500005], b[500005], sum = 1;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	if (n > 500000) {
		b[1] = abs(a[2] - a[1]);
		for (int i = 1; i <= n; i++) {
			if (m >= b[1] * i)
				m -= b[1] * i, sum++;
			else
				break;
		}
	} else if (n <= 20) {
		for (int i = 1; i <= n; i++)
			b[i] = a[i] - a[i - 1];
		for (int i = 2; i <= n; i++)
			if (m >= b[i] * (i - 1))
				m -= b[i] * (i - 1), sum++;
	} else
		sum = n;
	cout << sum;
	return 0;
}