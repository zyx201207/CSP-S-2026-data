#include <bits/stdc++.h>
#define Maxn 1000005

using namespace std;

int SubID, T;
int n, K, st, ed, lmt;
int fa[Maxn], dep[Maxn];
int nd[Maxn], mdp[Maxn];
int hv[Maxn], dis[Maxn];
int l, r, mid, pos;
int mxdp, vis[Maxn];
int t[Maxn], tot;
multiset<int> mst;
vector<int> d[Maxn];
vector<int> v[Maxn];

void init() {
	multiset<int>().swap(mst);
	for (int i = 0; i <= n; i ++) {
		fa[i] = dep[i] = nd[i] = mdp[i] = hv[i] = dis[i] = vis[i] = t[i] = 0;
		vector<int>().swap(v[i]);
	} n = K = st = ed = lmt = tot = 0;
	l = r = mid = pos = 0;
}

void DFS1(int x, int fath, int dp) {
	if (dp > mxdp) {
		st = x, mxdp = dp;
	} for (auto to : v[x]) {
		if (to == fath) { continue; }
		DFS1(to, x, dp + 1);
	}
} void DFS2(int x, int dp) {
	if (dp > mxdp) {
		ed = x, mxdp = dp;
	} for (auto to : v[x]) {
		if (to == fa[x]) { continue; }
		fa[to] = x, DFS2(to, dp + 1);
	}
}

void dfs(int x) {
	mdp[x] = dep[x];
	for (auto to : v[x]) {
		if (to == fa[x] || vis[to]) { continue; }
		fa[to] = x, dep[to] = dep[x] + 1, dfs(to);
		mdp[x] = max(mdp[x], mdp[to]);
	}
	
	if (mdp[x] - dep[x] < lmt) {
		nd[x] = 0; return ;
	} if (mdp[x] - dep[x] == lmt) {
		nd[x] = 1; return ;
	}
	
	nd[x] = 1;
	for (auto to : v[x]) {
		if (to == fa[x] || vis[to]) { continue; }
		nd[x] += nd[to];
	}
}

int Calc(int lgh) {
	for (int i = 0; i <= n; i ++) {
		nd[i] = mdp[i] = fa[i] = dep[i] = hv[i] = dis[i] = 0;
		vector<int>().swap(d[i]);
	}
	
	lmt = lgh;
	for (int i = 1, x = 0; i <= tot; i ++) {
		dep[x = t[i]] = 1;
		dfs(x);
		
		if (nd[x] == 0) {
			hv[i] = 0, dis[i] = (lmt - (mdp[x] - 1));
		} else {
			hv[i] = nd[x], dis[i] = 0;
		}
	}
	
	int res = 0;
	int pre = tot + 1;
	int suf = 0;
	for (int i = 1; i <= tot; i ++) {
		if (hv[i]) {
			pre = min(pre, i), suf = max(i, suf);
			res += (hv[i] - 1);
		}
	}
	
	if (lgh + 1 < pre) {
		hv[lgh + 1] = 1, dis[lgh + 1] = 0;
		pre = lgh + 1;
	} if (suf < tot - lgh) {
		hv[tot - lgh] = 1, dis[tot - lgh] = 0;
		suf = tot - lgh;
	}
	
	int ans = 0, lst = pre;
	for (int now = pre + 1; now <= suf; now ++) {
		if (hv[now]) {
			multiset<int>().swap(mst);
			mst.insert(now);
			for (int i = lst + 1; i < now; i ++) {
				if (lst < i - dis[i] && i + dis[i] < now) {
					d[i - dis[i]].push_back(i + dis[i]);
					mst.insert(i + dis[i]);
				}
			} ans = max(ans, (*mst.begin()) - lst - 1);
			for (int i = lst + 1; i < now; i ++) {
				for (auto tt : d[i]) { mst.erase(mst.find(tt)); }
				ans = max(ans, (*mst.begin()) - i - 1);
				if ((*mst.begin()) == now) { break; }
			} lst = now;
		}
	} return res + (suf - pre + 1) - ans;
}

void billtun() {
	init(), cin >> n >> K;
	for (int i = 1, a = 0, b = 0; i < n; i ++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	mxdp = 0, DFS1(1, 0, 1);
	mxdp = 0, DFS2(st, 1);
	
	vis[t[tot = 1] = ed] = 1;
	while (ed != st) {
		ed = fa[ed], vis[t[++ tot] = ed] = 1;
	} for (int i = 1; i <= n; i ++) {
		fa[i] = 0;
	}
	
	if (K == n) {
		cout << "0\n";
		return ;
	}
	
	l = 1, r = n - 1;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (Calc(mid) <= K) { pos = mid, r = mid - 1; }
		else { l = mid + 1; }
	} cout << pos << "\n";
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> SubID >> T;
	while (T --) { billtun(); }
	return 0;
}
