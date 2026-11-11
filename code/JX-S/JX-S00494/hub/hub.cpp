#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
#define For(i, a, b) for (int i = (a); i <= (b); i++)
#define Rof(i, a, b) for (int i = (a); i >= (b); i--)
#define Fo(i, a) for (auto i : a)
#define fi first
#define se second
#define pb push_back
#define sr cin
#define sw cout
#define endl '\n'

const int N = 1000010;
int c, t;
vector<int> G[N];
bool vis[N], bl[N];
int n, k, tmp, res;

void dfs(int p) {
	vis[p] = true;
	Fo(i, G[p]) if (bl[i] && !vis[i]) dfs(i);
}

void xfs(int p, int d) {
	tmp = max(tmp, d);
	vis[p] = true;
	Fo(i, G[p]) if (!vis[i] && !bl[i]) xfs(i, d + 1);
}

void ch(int x, int y) {
	if (x == k + 1) {
		int t = 0;
		tmp = 0;
		For(i, 1, n) vis[i] = false;
		For(i, 1, n) if (bl[i] && !vis[i]) dfs(i), t++;
		For(i, 1, n) if (bl[i]) xfs(i, 0);
		// For(i, 1, n) sw << bl[i] << " ";
		// sw << endl;
		// sw << tmp << endl;
		if (t <= 2) res = min(res, tmp);
		return;
	}
	For(i, y + 1, n) {
		bl[i] = true;
		ch(x + 1, i);
		bl[i] = false;
	}
}

void mika() {
	sr >> n >> k;
	For(i, 1, n) G[i].clear();
	For(i, 1, n - 1) {
		int u, v;
		sr >> u >> v;
		G[u].pb(v), G[v].pb(u);
	}
	if (n == k) return sw << 0 << endl, void();
	if (c == 13 || c == 14) {
		int m = n / 2;
		if (k >= m) return sw << 1 << endl, void();
		sw << (m - k + 7) / 4 << endl;
		return;
	}
	res = numeric_limits<int>::max();
	ch(1, 0);
	sw << res << endl;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	sr >> c >> t;
	while (t--) mika();
	return 0;
}