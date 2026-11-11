#include<bits/stdc++.h>
using namespace std;
#define I inline
#define gc getchar
#define pc putchar
#define ll long long
I int read() {
	int x = 0, f = 1; char ch = gc();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -f; ch = gc();}
	while(ch >= '0' && ch <= '9') x = x * 10 + (ch ^ 48), ch = gc();
	return x * f;
}
I void write(ll x) {
	if(x < 0) pc('-'), x = -x;
	if(x == 0) {pc('0'); return ;}
	int tot = 0; char s[20];
	while(x) {
		s[tot++] = x % 10 + '0';
		x /= 10;
	}
	while(tot--) pc(s[tot]);
}
const int N = 510, M = 500010;
ll dis[N][N]; int c, n, m, d, q;
vector<int> e[M], t[M]; int w[M], cnt[M];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	c = read(), n = read(), m = read(), d = read(), q = read();
	for(int i = 1; i <= m; i++) w[i] = read();
	for(int i = 1; i <= n; i++) {
		int k = read();
		for(int j = 1; j <= k; j++) {
			int id = read(), tm = read();
			e[id].push_back(i);
			t[id].push_back(tm);
			cnt[id]++; 
		}
	}
	memset(dis, 63, sizeof dis);
	for(int i = 1; i <= n; i++) dis[i][i] = 0;
	for(int i = 1; i <= m; i++) if(cnt[i] > 1) {
		for(int j = 0; j < cnt[i]; j++) {
			for(int k = j + 1; k < cnt[i]; k++) {
				dis[e[i][j]][e[i][k]] = min(dis[e[i][j]][e[i][k]], 1ll * t[i][j] + t[i][k]);
				dis[e[i][k]][e[i][j]] = dis[e[i][j]][e[i][k]];
			}
		}
	}
	for(int k = 0; k < n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	while(q--) {
		int u = read(), v = read(); ll mi = 2e18;
		for(int i = 0; i < cnt[u]; i++) {
			for(int j = 0; j < cnt[v]; j++) {
//				cout << e[u][i] << ' ' << e[v][j] << ' ' << t[u][i] + t[v][j] + dis[e[u][i]][e[v][j]] << '\n';
				mi = min(mi, t[u][i] + t[v][j] + dis[e[u][i]][e[v][j]]);
			}
		}
		write(mi + w[u] + w[v]); pc('\n'); 
	}
	return 0;
}
