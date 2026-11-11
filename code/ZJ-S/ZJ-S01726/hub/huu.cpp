#include <bits/stdc++.h>
int	Tc, n, k, par[1048576], xd[1048576], rxd[1048576], ban,
	di[1048576], rdi[1048576];
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
void DFSd(int x, int F) {
	for(int y : g[x])
		if(y != F)
			DFSd(y, x);
	di[x] = 0;
	int px = 0;
	for(int y : g[x])
		if(y != F)
			di[x] = std::max({di[x], di[y], px + xd[y] + 1}),
			px = std::max(px, xd[y] + 1);
}
void DFSrd(int x, int F) {
	int fir = rxd[x] + 1, pri = 0, sec = 0, ond = 0, trd = 0;
	for(int y : g[x])
		if(y != F) {
			int v = xd[y] + 1;
			if(v > fir)
				trd = sec, sec = fir, ond = pri, fir = v, pri = y;
			else if(v > sec)
				trd = sec, sec = v, ond = y;
			else
				trd = std::max(trd, v);
		}
//	printf("x=%d [%d] %d %d %d %d %d\n", x, rdi[x], fir, pri, sec, ond, trd);
	for(int y : g[x])
		if(y != F) {
			int w = fir + sec;
			if(y == pri)
				w -= fir, w += trd;
			else if(y == ond)
				w -= sec, w += trd;
			rdi[y] = std::max(rdi[x], w), DFSrd(y, x);
		}
}
int main() {
	freopen("hub4.in", "rb", stdin);
//	freopen("hub.out", "wb", stdout);
	int T;
	for(scanf("%d%d", &Tc, &T); T--; ) {
		scanf("%d%d", &n, &k);
		printf("n=%d k=%d\n", n, k);
		for(int i = 1; i <= n; i++)
			g[i].clear();
		for(int i = 1, u, v; i < n; i++)
			scanf("%d%d", &u, &v), g[u] += v, g[v] += u;
		int ans = n;
		if(Tc == 11 || Tc == 12) {
			ban = 0, DFSp(1, 0), rxd[1] = -1, DFSr(1, 0),
			DFSd(1, 0), rdi[1] = 0, DFSrd(1, 0);
			for(int i = 2; i <= n; i++)
			//	printf("%d %d\n", di[i], rdi[i]),
				ans = std::min(ans, std::max(di[i], rdi[i]) + 1 >> 1);
		}
		printf("%d\n", ans);
	}
	return 0;
}

