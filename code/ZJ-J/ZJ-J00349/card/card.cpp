#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];
int ans[300005];
int nxt[500005];
int lst[300005];
int fan[300005];
bool v[500005];
signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		if (lst[a[i]]) {
			nxt[i] = lst[a[i]];
			lst[a[i]] = i;
		}
		else {
			nxt[i] = 0;
			lst[a[i]] = i;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (nxt[i]) {
			fan[nxt[i]] = i;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (fan[j]) {
				j = fan[j] - 1;
			}
			else {
				ans[a[j]] += 1;
			}
		}
	}
	for (int i = 1; i <= m; i++) cout << ans[i] << ' ';
	return 0;
}
