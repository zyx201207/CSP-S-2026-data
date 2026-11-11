#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5+5, M = 3e5+5;
int n, m, a[N];
int las[N], nxt[N];
int cnt[N];
int ans[M];
int find(int x);
signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		nxt[las[a[i]]] = i;
		las[a[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		cnt[i] = 1;
		find(i);
	}
	for (int i = 1; i <= n; i++) {
		if (nxt[i] == i) {
			ans[a[i]] = cnt[i];
			cnt[i + 1] += cnt[i];
		} else {
			cnt[nxt[i]] += cnt[i];
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i];
		if (i != m) cout << ' ';
	}
	cout << '\n';
	return 0;
}
int find(int x) {
	if (!nxt[x] || x == nxt[x]) return nxt[x] = x;
	return nxt[x] = find(nxt[x]);
}
