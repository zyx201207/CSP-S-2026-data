#include<bits/stdc++.h>
#define int long long
using ll = long long;
using namespace std;
const int N = 2e6 + 5;
int c, T;
int n;
ll d, x[N];
namespace Solve1{
	bool judge(){
		return c <= 10;
	}
	int dis[N], cnt[N];
	vector<int> pos[N];
	void solve(){
		int ans = 0;
		for (int u = 1; u <= n; u ++){
			for (int i = u; i <= n; i ++) dis[i] = n + 10;
			dis[u] = 0;
			{
				deque<int> que;
				que.push_front(u);
				for (int j = u + 1; j <= n; j ++){
					while (!que.empty() && x[que.back()] < x[j] - d) que.pop_back();
					if (!que.empty()) dis[j] = dis[que.back()] + 1;
					while (!que.empty() && dis[que.front()] >= dis[j]) que.pop_front();
					que.push_front(j);
				}
			}
			for (int i = 0; i <= n; i ++) pos[i].clear();
			for (int i = u; i <= n; i ++)
				if (dis[i] <= n) pos[dis[i]].push_back(i);
			cnt[u] = 1;
			{
				for (int ds = 1; ds <= n; ds ++){
					int S = 0, l = 0, r = -1;
					for (const int& p : pos[ds]){
						while (r + 1 < (int)pos[ds - 1].size() && x[pos[ds - 1][r + 1]] <= x[p] + d){
							r ++;
							S += cnt[pos[ds - 1][r]];
						}
						while (l <= r && x[pos[ds - 1][l]] < x[p] - d){
							S -= cnt[pos[ds - 1][l]];
							l ++;
						}
						cnt[p] = S;
					}
				}
			}
			for (int i = 1; i <= n; i ++) ans += (cnt[i] == 2);
		}
		cout << ans << "\n";
	}
}
int nxt[N];
int f[N], len[N], g[N];
signed main(){
#ifndef DEBUG
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
#endif
//	freopen("migrate\\migrate4.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	for (cin >> c >> T; T --; ){
		cin >> n >> d;
		for (int i = 1; i <= n; i ++) cin >> x[i];
		if (Solve1::judge()){
			Solve1::solve();
			continue;
		}
		nxt[n] = n;
		for (int i = n - 1; i >= 1; i --){
			nxt[i] = nxt[i + 1];
			while (x[nxt[i]] - x[i] > d) nxt[i] --;
		}
		for (int i = 1; i <= n; i ++) f[i] = g[i] = len[i] = 0;
		for (int u = n; u >= 1; u --){
			len[u] = nxt[u - 1] < nxt[u] ? len[nxt[u]] + 1 : 1;
			if (nxt[u] == u){
				f[u] = 0;
				continue;
			}
			if (nxt[u] == u + 1){
				f[u] = f[nxt[u]];
				continue;
			}
			g[u] = nxt[u];
			int p1 = nxt[nxt[u]];
			int p2 = nxt[nxt[u] - 1];
			int p3 = nxt[nxt[u] - 2];
			if (p1 - p2 >= 2) f[u] = f[nxt[u]] + (p2 - p3);
			else if (p1 - p2 == 1){
				g[u] = g[nxt[u]];
				f[u] = f[g[u]] + (p2 - p3);
			}
			else if (p2 > p3) f[u] = len[nxt[u]] - 1 + (p2 - p3);
			else f[u] = 0;
//			if (u == 2) cerr << p1 << " " << p2 << " " << p3 << " ?\n";
		}
//		for (int u = 1; u <= n; u ++) cerr << f[u] << " ";
//		cerr << "\n";
		cout << accumulate(f + 1, f + n + 1, 0ll) << "\n";
	}
}
/*
0 1
7 5
1 5 7 10 11 12 16

*/