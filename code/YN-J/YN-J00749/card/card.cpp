#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200005], wz[5005], sum[5005];

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m, flag = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		sum[a[i]]++;
		wz[a[i]] = i;
	}
	for (int i = 2; i <= n; i++) {
		if (a[i] < a[i - 1]) {
			flag = 1;
			break;
		}
	}
	if (flag == 0) {
		for (int i = 1; i <= m; i++) {
			if (wz != 0)
				cout << wz[i] << " ";
		}
		return 0;
	}
	for (int i = 1; i <= m; i++) {
		if (sum[i] != 1) {
			int u = (sum[i] + 1) / 2;
			cout << u << " ";
		} else {
			cout << wz[i] << " ";
		}
	}
	return 0;
}