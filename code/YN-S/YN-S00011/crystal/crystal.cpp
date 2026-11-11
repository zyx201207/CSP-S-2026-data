//by.pcx
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int a[N], n, m;

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	int flg = 1, d = a[1];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] - a[i - 1] != d)
			flg = 0;
		d = a[i] - a[i - 1];
	}
	if(flg){
		m/=d;
	}
	sort(a + 1, a + n + 1);
	int ans = 1;
	for (int i = 2; i <= n; i++) {
		int sum = 0, cnt = 1;
		for (int j = 1; j < i; j++) {
			if (sum + a[i] - a[j] <= m)
				sum += a[i] - a[j], cnt++;
			else
				break;
		}
		ans = max(ans, cnt);
	}
	cout << ans;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/