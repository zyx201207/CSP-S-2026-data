#include <bits/stdc++.h>
using namespace std;
vector<int> v[1000005];
pair<int, int> md[1000005], sd[1000005], td[1000005];
int c, t, n, k, lim, cnt, od[1000005], s[1000005], fa[1000005], dep[1000005], dfn[1000005], tp[1000005], siz[1000005], son[1000005], s2[1000005];
void dfs(int x, int fa) {
	dep[x] = dep[::fa[x] = fa] + (siz[x] = s[x] = 1);
	for(int i : v[x])
		if(i ^ fa) {
			dfs(i, x), siz[x] += siz[i];
			if(md[i].first >= md[x].first)
				td[x] = sd[x], sd[x] = md[x], md[x] = {md[i].first + 1, i};
			else if(md[i].first >= sd[x].first)
				td[x] = sd[x], sd[x] = {md[i].first + 1, i};
			else
				td[x] = max(td[x], make_pair(md[i].first + 1, i));
			if(md[i].first >= lim)
				s[x] += s[i];
			if(siz[i] > siz[son[x]])
				son[x] = i;
		}
	return;
}
void dfs2(int x, int top) {
	if(od[x] <= lim)
		s2[x] = 1;
	dfn[x] = ++cnt, tp[x] = top;
	long long res = s[x] + s2[x];
	for(int i : v[x])
		if(i != fa[x])
			od[i] = max(od[x], md[x].second ^ i ? md[x].first : sd[x].first) + 1, s2[i] = res - (md[i].first < lim ? 0 : s[i]);
	if(son[x])
		dfs2(son[x], top);
	for(int i : v[x])
		if(i != fa[x] && i != son[x])
			dfs2(i, i);
	return;
}
int lca(int x, int y) {
	while(tp[x] ^ tp[y]) {
		if(dep[tp[x]] < dep[tp[y]])
			swap(x, y);
		x = fa[tp[x]];
	}
	return dep[x] < dep[y] ? x : y;
}
int dis(int x, int y) {
	return dep[x] + dep[y] - 2 * dep[lca(x, y)];
}
bool chk(int x, int y) {
	int L = lca(x, y);
	if(L != x && L != y) {
		int p = x, q = y;
		for(; fa[p] != L || fa[q] != L;) {
			if(dep[p] < dep[q])
				swap(p, q);
			int d = md[fa[p]].second ^ p ? md[fa[p]].first : sd[fa[p]].first;
			if(d + min(dis(fa[p], x), dis(fa[p], y)) > lim)
				return 0;
			p = fa[p];
		}
		if(s[x] + s[y] > k || max(od[L], md[L].second == p || md[L].second == q ? sd[L].second == p || sd[L].second == q ? td[L].first : sd[L].first : md[L].first) + min(dis(x, L), dis(y, L)) > lim)
			return 0;
		return 1;
	}
	if(L == x)
		swap(x, y);
	int p = x;
	while(fa[p] ^ L) {
		int d = md[fa[p]].second ^ p ? md[fa[p]].first : sd[fa[p]].first;
		if(d + min(dis(fa[p], x), dis(fa[p], y)) > lim)
			return 0;
		p = fa[p];
	}
	return s[x] + s2[y] + s[y] - 1 - (md[p].first < lim ? 0 : s[p]) <= k;
}
bool check(int lim) {
	for(int i = 1; i <= n; i++)
		md[i] = sd[i] = td[i] = {0, 0}, od[i] = s[i] = s2[i] = son[i] = 0;
	cnt = 0, ::lim = lim, dfs(1, 0), dfs2(1, 1);
	for(int i = 1; i <= n; i++)
		if(s[i] <= k && od[i] <= lim)
			return 1;
	for(int x = 1; x <= n; x++)
		for(int y = 1; y < x; y++)
			if(chk(x, y))
				return 1;
	return 0;
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while(t--) {
		cin >> n >> k;
		for(int i = 1, x, y; i < n; i++)
			cin >> x >> y, v[x].push_back(y), v[y].push_back(x);
		int l = -1, r = n;
		while(l + 1 < r) {
			int mid = l + r >> 1;
			if(check(mid))
				r = mid;
			else
				l = mid;
		}
		cout << r << '\n';
		for(int i = 1; i <= n; i++)
			v[i].clear();
	}
	return 0;
}