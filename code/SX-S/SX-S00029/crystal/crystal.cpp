#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll m, a[500005];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int _ = 1;
//	cin>>_;
	while (_--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		sort(a + 1, a + n + 1);
		int lst = 1, ans = 1;
		ll now = 0;
		for (int i = 2; i <= n; i++) {
			while (lst <= i && (i - lst) * (a[i] - a[i - 1]) > m - now) {
				now -= a[i - 1] - a[lst++];
			}
			now += (i - lst) * (a[i] - a[i - 1]);
			ans = max(ans, i - lst + 1);
		}
		cout << ans;
	}
}/*
5 5
1 2 4 8 9

*/
