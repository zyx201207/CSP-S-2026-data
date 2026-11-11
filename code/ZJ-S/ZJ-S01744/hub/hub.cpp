#include <bits/stdc++.h>
#define int long long
using namespace std;

#define FOR(x, y, z) for(int (x) = (y); (x) <= (z); (x)++)
#define ROF(x, y, z) for(int (x) = (y); (x) >= (z); (x)--)s
#define mp make_pair
#define pb push_back

const int N = 1e6 + 10;
int n, k, fa[N], ans[N], up[N];
pair<int, int> fir[N], sec[N], thi[N];
vector<int> g[N];

void dfs(int u, int pre){
	fa[u] = pre;
	fir[u] = sec[u] = thi[u] = mp(0, u);
	for(int v : g[u]) if(v != pre){
		dfs(v, u);
		pair<int, int> now = mp(fir[v].first + 1, v);
		if(now > fir[u]) swap(now, fir[u]);
		if(now > sec[u]) swap(now, sec[u]);
		if(now > thi[u]) swap(now, thi[u]);
	}
	return ;
}
void dfs2(int u, int pre){
	for(int v : g[u]) if(v != pre){
		pair<int, int> now = mp(fir[u].first + 1, u);
		if(fir[u].second == v) now = mp(sec[u].first + 1, u);
		if(now > fir[v]) swap(now, fir[v]);
		if(now > sec[v]) swap(now, sec[v]);
		if(now > thi[v]) swap(now, thi[v]);
		dfs2(v, u);
	}
	return ;
}

void get1(int u, int pre, int dis){
	ans[u] = up[u] = 0;
	int now = fir[u].first;
	if(fir[u].second == pre) now = sec[u].first;
	if(now >= dis) ans[u] = 1;
	for(int v : g[u]) if(v != pre){
		get1(v, u, dis);
		ans[u] += ans[v];
	}
	return ;
}
void get2(int u, int pre, int dis){
	int all = 0;
	for(int v : g[u]) if(v != pre) all += ans[v];
	for(int v : g[u]) if(v != pre){
		up[v] = up[u] + all - ans[v];
		int now = fir[u].first;
		if(fir[u].second == v) now = sec[u].first;
		if(now >= dis) up[v]++;
		get2(v, u, dis);
	}
	return ;
}

bool check(int u, int pre, int dis, int nowdis, int top){
	if(pre == -1){
		int now = up[u];
		for(auto i : g[u]) if(i != fa[u]) now += ans[i];
		if(now + 1 <= k) return true;
		int flg = 0;
		for(int v : g[u]){
			if(v == fa[u]) flg |= check(v, u, dis, -1e9, now - up[u]);
			else flg |= check(v, u, dis, -1e9, now - ans[v]);
			if(flg) return true;
		}
		return false;
	}

	int now = up[u];
	for(auto i : g[u]) if(i != fa[u]) now += ans[i];
	if(pre == fa[u]) now -= up[u];
	else now -= ans[pre];
	if(now + top + 2 <= k) return true;

	nowdis++; if(nowdis > dis) return false;
	for(int v : g[u]) if(v != pre){
		int now = 0;
		if(fir[u].second != pre && fir[u].second != v) now = fir[u].first;
		else if(sec[u].second != pre && sec[u].second != v) now = sec[u].first;
		else if(thi[u].second != pre && thi[u].second != v) now = thi[u].first;
		if(now + 1 > dis) continue;
		if(check(v, u, dis, max(nowdis, now + 1), top)) return true;
	}
	return false;
}

bool Check(int mid){
	get1(1, -1, mid); get2(1, -1, mid);
	FOR(i, 1, n) if(check(i, -1, mid, -1e9, 0)){
		return true;
	}
	return false;
}

int debug = 0;
void solve(){
	FOR(i, 0, n) fa[i] = ans[i] = up[i] = 0, fir[i] = sec[i] = thi[i] = mp(0, 0), g[i].clear();

	cin >> n >> k; FOR(i, 1, n - 1){int x, y; cin >> x >> y, g[x].pb(y), g[y].pb(x);}
	dfs(1, -1); dfs2(1, -1);

	int L = 0, R = n - 1, res = 0;
	while(L <= R){
		int mid = (L + R) >> 1;
		if(Check(mid)) res = mid, R = mid - 1;
		else L = mid + 1;
	}
	cout << res << "\n";
	return ;
}

signed main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int c, t; cin >> c >> t;
	while(t--) solve();
	return 0;
}