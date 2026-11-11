#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
#include<bitset>

using namespace std;
#define ll long long
#define endl '\n'
#define pii pair<int, int>
const int N = 1e6 + 1;
vector<int> e[N];
int k, n, r, h, far, D;
bitset<N> usd;
int dfs1(int u, int fa, int dep) {
	int d = 0;
	for(auto v : e[u])
		if(v != fa) {
			d = max(d, dfs1(v, u, dep+1));
		}
	if(d <= r) usd.reset(u);
	if(dep > D) far = u, D = dep;
	return d+1;
}
int dfs2(int u, int fa) {
	if(!usd.test(u)) return -1;
	int d = -1, cnt = 0;
	for(auto v : e[u])
		if(v != fa) 
			d = max(d, dfs2(v, u));
	return d+1;
}
int dfs3(int u, int fa, int d) {
	if(!usd.test(u)) return 0;
	int siz = 0;
	for(auto v : e[u])
		if(v != fa)
			siz += dfs3(v, u, d+1);
	int cnt = 0;
	for(auto v : e[u]) cnt += usd.test(v);
	if(d >= r || cnt > 2) h = siz;
	return siz;
}
bool check() {
	D = 0;
	for(int i = 1; i <= n; i++) usd.set(i);
	dfs1(1, 1, 0), dfs1(far, far, 0);
	if(usd.count() <= k) return true;
	int Max = n;
	for(int i = 1; i <= n; i++) {
		int cnt = 0;
		for(auto v : e[i]) cnt += usd.test(v);
		if(cnt == 2 && usd.test(i)) {
			int t = 0;
			for(auto v : e[i])
				dfs3(v, i, 0), t += h;
			Max = min(Max, t);
		}
	}
	return Max != n && Max <= k;
}

int Main() {
	cin >> n >> k;
	if(k == n) cout << 0 << endl;
	if(k == n-1) cout << 1 << endl;
	for(int i = 1; i <= n; i++)
		e[i].clear();
	for(int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	int L = 1, R = n-1;
	while(L < R) {
		r = (L + R) / 2;
		if(check())
			R = r;
		else
			L = r+1;
	}
	cout << L << endl;
	return 0;
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t; cin >> c >> t;
	while(t--)
		Main();
	return 0;
}

