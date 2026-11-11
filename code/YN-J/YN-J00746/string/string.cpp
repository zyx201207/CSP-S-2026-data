#include <bits/stdc++.h>
using namespace std;
#define int long long
char a[20000005];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		int ai;
		char ci;
		cin >> ai >> ci;
		for (int j = cnt + 1; j <= cnt + ai ; j++) {
			a[j] = ci;
		}
		cnt += ai;

	}
	int ans = 0;
	int mid = cnt / 2;
	for (int i = 1; i <= mid; i++) {
		if (a[i] != a[cnt - i + 1]) {
			ans++;
		}
	}
	cout << ans;
	return 0;
}
