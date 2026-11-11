#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i ++ )
#define per(i, l, r) for(int i = (l); i >= (r); i -- )
#define frein(s) freopen(s, "r", stdin)
#define freout(s) freopen(s, "w", stdout)
#define endl '\n'
using namespace std;

static constexpr int N = 1e6 + 5;
static constexpr int INF = 0x3f3f3f3f;
static int c, T, n, k, dis[5005][5005];
vector<int> t[N];

struct dsu {
	int fa[N];
	void init() { rep(i, 1, n) fa[i] = i; }
	int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
	void merge(int x, int y) { fa[find(x)] = find(y); }
} d;

void dfs(int s, int u, int fa) {
	for(auto v : t[u]) {
		if(v == fa) continue;
		dis[s][v] = dis[s][u] + 1;
		dfs(s, v, u);
	}
}

int solve(int S) {
	vector<int> res;
	if(__builtin_popcount(S) != k) return INF;
	d.init();
	rep(i, 1, n) for(auto v : t[i])
		if(((S >> (i - 1)) & 1) && ((S >> (v - 1)) & 1)) d.merge(i, v);
	rep(i, 1, n) if((S >> (i - 1)) & 1) res.push_back(d.find(i));
	sort(res.begin(), res.end());
	res.erase(unique(res.begin(), res.end()), res.end());
	if(res.size() > 2) return INF;
	int ans = 0;
	rep(i, 1, n) {
		int cur = INF;
		rep(j, 1, n) if((S >> (j - 1)) & 1) cur = min(cur, dis[i][j]);
		ans = max(ans, cur);
	}
	return ans;
}

int main() {
	frein("hub.in"), freout("hub.out");
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> T;
	while(T -- ) {
		cin >> n >> k;
		rep(i, 1, n) t[i].clear();
		rep(i, 1, n - 1) {
			int u, v;
			cin >> u >> v;
			t[u].push_back(v);
			t[v].push_back(u); 
		}
		if(c <= 3) {
			rep(i, 1, n) dfs(i, i, 0);
			int ans = INF;
			rep(S, 0, (1 << n) - 1) ans = min(ans, solve(S));
			cout << ans << endl; 
		} else {
			int m = n / 2;
			if(k == n) cout << 0 << endl;
			else if(k >= m) cout << 1 << endl;
			else cout << (m - k + 3) / 4 + 1 << endl;
		}
	}
	return 0;
}
//code by wsy_I.luogu uid: 1152799
/*
100+100+56+25=281。燃尽了。 
in:
0 1
9 3
1 2
2 8
4 7
6 5
7 9
8 5
5 3
3 9

out:
2
*/