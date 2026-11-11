#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[500005];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n - 1);

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int tmp = 0;
		for (int j = 0; j <= i; j++) {
			tmp += a[i] - a[j];
		}
		if (tmp <= m)
			cnt++;
		else
			break;
	}

	cout << cnt;

	return 0;
}