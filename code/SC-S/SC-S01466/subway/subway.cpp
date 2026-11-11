#include <bits/stdc++.h>
#define ll long long
#define rep(i, l, r) for(int i = l; i <= r; i++)
#define req(i, r, l) for(int i = r; i >= l; i--)
#define pb push_back
#define PII pair<int, int>
#define fir first
#define sec second
#define mkp make_pair
inline int rd() {
	int res = 0, f = 1; char ch;
	while(!isdigit(ch)) { if(ch == '-') f = -1; ch = getchar(); }
	while(isdigit(ch)) { res = (res << 3) + (res << 1) + (ch ^ 48); ch = getchar(); }
	return f * res;
}
using namespace std;
const int N = 508;
const int M = 5e5 + 8;
int n, m, q, d;
int w[M];
ll dis[N][N];
vector<PII> G[M];
int k, u, v, w1, w2, x, y;
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);	
	rd(), m = rd(), n = rd(), d = rd(), q = rd();
	rep(i, 1, n) w[i] = rd();
	rep(i, 1, m) rep(j, 1, m) 
		if(i != j) dis[i][j] = 1e18;
	rep(i, 1, m) {
		k = rd();
		while(k--) G[rd()].pb(mkp(i, rd()));
	}
	rep(i, 1, n) rep(j, 0, (int)G[i].size() - 1) rep(k, 0, j) {
		u = G[i][j].fir, w1 = G[i][j].sec;
		v = G[i][k].fir, w2 = G[i][k].sec;
		dis[u][v] = dis[v][u] = min(dis[u][v], (ll)w1 + w2);
	}
	rep(k, 1, m) rep(i, 1, m) rep(j, 1, m) 
		dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	while(q--) {
		x = rd(), y = rd();
		ll ans = 1e18;
		rep(i, 0, (int)G[x].size() - 1) rep(j, 0, (int)G[y].size() - 1) {	
			u = G[x][i].fir, w1 = G[x][i].sec;
			v = G[y][j].fir, w2 = G[y][j].sec;
			ans = min(ans, w[x] + w[y] + dis[u][v] + w1 + w2);
		}
		cout << ans << "\n";
	}
	return 0;
}
/*
注意到线路很少，且线路之间没有权值。设dis[i][j]表示第i条线到第j条线的最短路

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/