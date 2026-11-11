#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500050];
int cnt = 0, ans = -1, n, m;

signed main() {
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		int d = 1, h = m;
		cnt = 1;
		for (int j = i + 1; j <= n; ++j) {
			h -= (a[j] - a[j - 1]) * d;
			if (h < 0)
				break;
			d++;
			cnt++;
		}
		if (cnt > ans)
			ans = cnt;
	}
	cout << ans;
	return 0;
}