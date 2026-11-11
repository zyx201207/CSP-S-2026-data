#include<bits/stdc++.h>
#define int long long
#define rep(i, l, r) for(int i = (l); i <= (r); ++ i)
#define per(i, r, l) for(int i = (r); i >= (l); -- i)
#define pb push_back
#define endl '\n'
using namespace std;
const int N = 5e5 + 10;

int n, k, dis[N], mp[N], pa[N];
vector<int> p[N];
void dfs0(int u, int fa) {
	pa[u] = fa;
	for(auto v: p[u]) {
		if(v == fa) continue;
		dfs0(v, u);
	}
}
void dfs(int u, int fa, int len) {
	dis[u] = min(dis[u], len);
	for(auto v : p[u]) {
		if(v == fa) continue;
		dfs(v, u, len + 1);
	}
}
void Jail() {
	cin >> n >> k;
	rep(i, 1, n - 1) {
		int u, v;
		cin >> u >> v;
		p[u].pb(v);
		p[v].pb(u);
	}
	dfs0(1, 0);
	int ans = 1e9;
	rep(s, 0, (1 << n) - 1) {
		int cnt = 0;
		rep(i, 1, n) {
			if(s >> (i - 1) & 1) {
				mp[i] = 1;
				++ cnt;
			} else mp[i] = 0;
			dis[i] = n + 1;
		}
		if(cnt != k) continue;
		cnt = k;
		rep(i, 2, n) {
			if(mp[i] && mp[pa[i]]) {
				cnt --;
			}
		}
		if(cnt > 2) continue;
		
		rep(i, 1, n) if(mp[i]) dfs(i, 0, 0);
		int res = 0;
		rep(i, 1, n) res = max(res, dis[i]);
//		cout << "de : \n";
//		rep(i, 1, n) if(mp[i]) cout << i << ' ';
//		cout << endl;
//		rep(i, 1, n) cout << dis[i] << ' ';
//		cout << endl;
		ans = min(ans, res);
	}
	cout << ans << endl;
	rep(i, 1, n) p[i].clear();
}
signed main() {
	freopen("hub.in", "r", stdin); freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int Id, T = 1;
	cin >> Id >> T;
	while(T --) Jail();
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

0 1
5 2
1 2
2 3
3 4
4 5
*/
