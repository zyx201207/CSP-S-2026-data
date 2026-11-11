#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

int n, m, a[500000 + 10], c[500000 + 10];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == i)
			sum++;
	}

	int sum1 = 0;

	if (sum == n) {
		for (int i = 1; i <= n; i++) {
			if (sum1 + i <= m)
				sum1 += i;
			else
				cout << i - 1;
		}
	}

	sort(a + 1, a + n + 1);

	int cnt = 0;

	for (int i = 1; i <= n; i++) {
		c[i] = a[i + 1] - a[i];
		cnt += c[i] * i;
		if (cnt > m) {
			cout << i;
			break;
		}
	}

	return 0;
}
