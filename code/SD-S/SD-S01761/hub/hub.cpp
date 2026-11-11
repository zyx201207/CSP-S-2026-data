#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
const int N = 2000006;
const int inf = 1e9;

int c, T;
int n, k;
vector<int> g[N];

struct SOLVE1 {
	int m;
	bool check(int x) {
		int pl = x, pr = m - x;
		if(pl >= pr) return true;
		int gap = pr - pl + 1 - k;
		if(gap <= 0) return true;
		if((gap + 1) / 2 + 1 <= x) return true;
		return false;
	}
	void solve() {
		m = n / 2;
		int l = 0, r = n + 1;
		while(l + 1 < r) {
			int mid = (l + r) / 2;
			if(check(mid)) r = mid;
			else l = mid;
		}
		cout << r << endl;
	}
}; 
struct SOLVE2 {
	int ans = inf;
	int vis[N];
	void dfs(int u, int mask) {
		vis[u] = 1;
		for(int v : g[u]) {
			if(vis[v]) continue;
			if(!(mask & (1 << (v - 1)))) continue;
			dfs(v, mask);
		}
	}
	bool check(int mask) {
		if(__builtin_popcount(mask) != k) return false;
		if(__builtin_popcount(mask) == 2) return true;
		for(int i = 1; i <= n; i++)
			vis[i] = 0;
		int cnt = 0;
		for(int i = 1; i <= n; i++) {
			if(!(mask & (1 << (i - 1)))) continue;
			if(vis[i]) continue;
			cnt++;
			if(cnt > 2) return false;
			dfs(i, mask);
		}
		if(cnt > 2) return false;
		return true;
	}
	int bfs(int s, int mask) {
		if(mask & (1 << (s - 1))) return 0;
		vector<int> dis(n + 1), vis(n + 1);
		for(int i = 1; i <= n; i++)
			dis[i] = inf, vis[i] = 0;
		dis[s] = 0;
		queue<int> q;
		q.push(s);
		while(!q.empty()) {
			int u = q.front();
			q.pop();
			for(int v : g[u]) {
				if(vis[v]) continue;
				vis[v] = 1;
				dis[v] = dis[u] + 1;
				if(mask & (1 << (v - 1))) return dis[v];
				q.push(v);
			}
		}
		return -1;
	}
	int calc(int mask) {
		int ans = 0;
		for(int i = 1; i <= n; i++)
			ans = max(ans, bfs(i, mask));
		return ans;
	}
	void solve() {
		for(int mask = 0; mask < (1 << n); mask++) {
			if(!check(mask)) continue;
			bitset<20> tmp;
			tmp = mask;
//			cout << tmp << ' ' << mask << ' ' << calc(mask) << endl; 
			ans = min(ans, calc(mask));
		} 
		cout << ans << endl;
//		cout << check(262) << endl;
	} 
};
void solve() {
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		g[i].clear();
	for(int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if(c == 13 || c == 14) {
		(new SOLVE1()) -> solve();
	} else {
		(new SOLVE2()) -> solve();
	}
}
int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	cin >> c >> T;
	while(T--) {
		solve();
	}
    return 0;
}
