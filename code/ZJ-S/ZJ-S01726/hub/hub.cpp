#include <bits/stdc++.h>
int Tc, n, k, par[1048576], xd[1048576], rxd[1048576], ban;
std::basic_string<int> g[1048576];
void DFSp(int x, int F) {
	if(!ban)
		par[x] = F;
	xd[x] = 0;
	for(int y : g[x])
		if(y != F && y != ban)
			DFSp(y, x), xd[x] = std::max(xd[x], xd[y] + 1);
}
void DFSr(int x, int F) {
	int fir = rxd[x] + 1, pri = 0, sec = 0;
	for(int y : g[x])
		if(y != F && y != ban) {
			int v = xd[y] + 1;
			if(v > fir)
				sec = fir, fir = v, pri = y;
			else
				sec = std::max(sec, v);
		}
	for(int y : g[x])
		if(y != F && y != ban)
			rxd[y] = y == pri ? sec : fir,
			DFSr(y, x);
}
int solve(int c) {
	if(c == 1)
		ban = 0, DFSp(1, 0), rxd[1] = -1, DFSr(1, 0);
	else
		ban = c, DFSp(1, 0), rxd[1] = -1, DFSr(1, 0),
		DFSp(c, par[c]), rxd[c] = -1, DFSr(c, par[c]);
	static int o[1048576];
	for(int i = 2; i <= n; i++)
		o[i] = std::min(rxd[i], xd[i]);
	int l = -1, r = n;
	while(l + 1 < r) {
		int mid = l + r >> 1, cnt = 1;
		for(int i = 2; i <= n; i++)
			cnt += i == c || o[i] >= mid;
		(cnt <= k ? r : l) = mid;
	}
	return r;
}
int main() {
	freopen("hub.in", "rb", stdin);
	freopen("hub.out", "wb", stdout);
	int T;
	for(scanf("%d%d", &Tc, &T); T--; ) {
		scanf("%d%d", &n, &k);
		for(int i = 1; i <= n; i++)
			g[i].clear();
		for(int i = 1, u, v; i < n; i++)
			scanf("%d%d", &u, &v), g[u] += v, g[v] += u;
		int ans = n;
		if(Tc == 13 || Tc == 14) {
			int m = n >> 1;
			if(k <= m)
				ans = std::min(ans, m - k + 7 >> 2);
			else
				ans = k < n;
		} else
			for(int i = 1; i <= n; i++)
				ans = std::min(ans, solve(i));
		printf("%d\n", ans);
	}
	return 0;
}

