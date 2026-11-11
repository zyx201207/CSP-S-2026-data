#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;
int n, m, a[N], tmp[N], nxt[N], vis[N], res[N];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = n; i >= 1; i--) {
		nxt[i] = tmp[a[i]];
		tmp[a[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		int st = i;
		while (st < n) {
			if (nxt[st]) st = nxt[st];
			else {
				res[a[st]]++;
				st++;
			}
		}
		res[a[n]]++;
	}
	for (int i = 1; i <= m; i++) cout << res[i] << ' ';
	return 0;
}
