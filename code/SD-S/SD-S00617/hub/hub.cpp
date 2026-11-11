#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mp(Tx, Ty) make_pair(Tx, Ty)
#define For(Ti, Ta, Tb) for(auto Ti = (Ta); Ti <= (Tb); Ti++)
#define Dec(Ti, Ta, Tb) for(auto Ti = (Ta); Ti >= (Tb); Ti--)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define range(Tx) begin(Tx),end(Tx)
const int N = 1005, INF = 1e9;
int f[N][3][N];
int n, k;
int h[N], e[N * 2], ne[N * 2], idx;
int mdep[N], g[3][N], gg[3][N];
void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx++; 
}
void dfs(int x, int fa, int X) {
	int cnt = 0;
	mdep[x] = 0;
	for (int i = h[x]; ~i; i = ne[i]) {
		int j = e[i];
		if (j == fa) continue;
		dfs(j, x, X);
		mdep[x] = max(mdep[x], mdep[j] + 1);
		cnt++;
	}
	if (cnt == 0) {
		f[x][0][0] = 0, f[x][1][0] = 1;
		return;
	}
	memset(gg, 0x3f, sizeof(gg));
	gg[0][0] = 0;
	int md = 0;
	int now = 0, now2 = 0;
	for (int i = h[x]; ~i; i = ne[i]) {
		int j = e[i];
		if (j == fa) continue;
		memset(g, 0x3f, sizeof(g));
		For(l, 0, md) {
			For(op1, 0, 2) {
				if (gg[op1][l] >= INF) continue;
				For(r, 0, mdep[j]) {
					if (l + r + 2 > X) break;
					For(op2, 0, 2) {
						if (op1 + op2 > 2) break; 
						if (f[j][op2][r] >= INF) continue;
						g[op1 + op2][max(l, r)] = min(g[op1 + op2][max(l, r)], f[j][op2][r] + gg[op1][l]);
					}
				}
			}
		}
		memcpy(gg, g, sizeof(g));
		md = max(md, mdep[j]);
		if (mdep[j] + 1 <= X) ;
		else now = min(INF, now + f[j][1][0]);
		if (mdep[j] + 1 <= X) ;
		else {
			int minn = INF;
			For(k, 0, mdep[j]) if (k + 1 <= X) minn = min(minn, f[j][1][k]);
			now2 = min(INF, min(now2 + f[j][1][0], now + minn));
		}
	}
	For(i, 1, md) For(j, 0, 2) f[x][j][i] = gg[j][i - 1];
	f[x][1][0] = min(f[x][1][0], now + 1);
	f[x][2][0] = min(f[x][2][0], now2 + 1);
}
bool check(int x) {
	For(i, 1, n) For(j, 0, n + 1) f[i][0][j] = f[i][1][j] = f[i][2][j] = INF;
	dfs(1, 0, x);
	int minn = INF;
	For(i, 0, x) minn = min(minn, min(f[1][0][i], min(f[1][1][i], f[1][2][i])));
	return minn <= k;
}
int main() {
	assert(freopen("hub.in", "r", stdin));
	assert(freopen("hub.out", "w", stdout));
	cin.tie(nullptr)->sync_with_stdio(false);
	int c, T;
	cin >> c >> T;
	while (T--) {
		cin >> n >> k;
		For(i, 1, n) h[i] = -1;
		idx = 0;
		For(i, 1, n - 1) {
			int a, b;
			cin >> a >> b;
			add(a, b), add(b, a);
		}
		int l = 0, r = n + 1, ans = -1;
		while (l <= r) {
			int mid = l + r >> 1;
			if (check(mid)) ans = mid, r = mid - 1;
			else l = mid + 1;
		}
		cout << ans << '\n';
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/
