#include<bits/stdc++.h>
//#define int long long
#define ll long long
#define maxn 2000005
#define INFint (int)(1e9 + 5)
#define INFll (long long)(1e18 + 5)
#define ull unsigned long long
using namespace std;

int c,t;
int n;
ll d,x[maxn];
ll f[maxn],g[maxn];// len num
int q[maxn],fr,ta;
int rsp[maxn],lsp[maxn],tong[maxn];
ll numl[maxn],numr[maxn];
void clear() {
	fr = 1,ta = 0;
	for(int i = 0; i <= n; ++ i) f[i] = g[i] = q[i] = rsp[i] = lsp[i] = tong[i] = numl[i] = numr[i] = 0;
}
void solve() {
	cin >> n >> d;
	for(int i = 1; i <= n; ++ i) cin >> x[i];
	clear();
	if(c <= 10) {
		ll ans = 0;
		for(int i = 1; i <= n; ++ i) {
			f[i] = 0;
			g[i] = 1;
			fr = 1;
			ta = 0;
			q[++ ta] = i;
			int now = 0;
			for(int j = i + 1; j <= n; ++ j) {
				while(x[j] - x[q[fr]] > d && fr <= ta) ++ fr;
				if(fr > ta) break;
				f[j] = f[q[fr]] + 1;
				g[j] = g[q[fr]];
				if(fr + 2 <= ta && f[q[fr]] == f[q[fr + 2]]) {
					g[j] = 3;
					q[++ ta] = j;
					continue;
				}
				if(fr + 1 <= ta && f[q[fr]] == f[q[fr + 1]] && g[q[fr]] + g[q[fr + 1]] > 2) {
					g[j] = 3;
					q[++ ta] = j;
					continue;
				}
				if(fr + 1 <= ta && f[q[fr]] == f[q[fr + 1]]) g[j] += g[q[fr]];
				if(g[j] == 2) ++ now;
				q[++ ta] = j;
			}
			ans += now;
			f[i] = INFint;
			g[i] = 0;
		}
		cout << ans << "\n";
		return ;
	} else if(c >= 11 && c <= 12) {
		f[1] = 0;
		g[1] = 1;
		fr = 1,ta = 0;
		q[++ ta] = 1;
		for(int i = 2; i <= n; ++ i) {
			while(x[i] - x[q[fr]] > d && fr <= ta) ++ fr;
			if(fr > ta) break;
			f[i] = f[q[fr]] + 1;
			g[i] = g[q[fr]];
			if(fr + 2 <= ta && f[q[fr]] == f[q[fr + 2]]) {
				g[i] = 3;
				q[++ ta] = i;
				continue;
			}
			if(fr + 1 <= ta && f[q[fr]] == f[q[fr + 1]] && g[q[fr]] + g[q[fr + 1]] > 2) {
				g[i] = 3;
				q[++ ta] = i;
				continue;
			}
			if(fr + 1 <= ta && f[q[fr]] == f[q[fr + 1]]) g[i] += g[q[fr]];
			q[++ ta] = i;
		}
		ll ans = 0;
		for(int i = 2; i <= n; ++ i) {
			if(g[i] == 2) ans += (n - i + 1);
		}
		cout << ans << "\n";
		return ;
	} else if(c >= 13 && c <= 14) {
		for(int i = 1,j = 1; i <= n && j <= n; ++ i) {
			while(x[j] - x[i] <= d && j <= n) {
				lsp[j] = i;
				++ j;
			}
		}
		for(int i = n,j = n; i >= 1 && j >= 1; -- i) {
			while(x[i] - x[j] <= d && j >= 1) {
				rsp[j] = i;
				-- j;
			}
		}
		for(int i = 1; i <= n; ++ i) {
//			cout << lsp[i] << ' ' << rsp[i] << "*\n";
			if(lsp[i] < i - 1) tong[lsp[i]] ++;
		}
		ll ans = 0;
		for(int i = 1; i <= n; ++ i) {
			if(rsp[i] == n) break;
			if(rsp[i] <= i + 1) continue;
			int nd = rsp[i] - 1;
			ans += tong[nd];
		}
		cout << ans << "\n";
		return ;
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t --) solve();

	return 0;
}
/*
25 2
4 2
1 2 3 4
5 2
1 2 3 4 5

25 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
