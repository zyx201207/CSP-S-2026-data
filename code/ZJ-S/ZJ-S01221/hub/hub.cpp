#include <bits/stdc++.h>
using ll = long long;
using namespace std;

namespace Yukari {

const int N = 1e6 + 10;
const int INF = 1e9;
int n, m; vector<int> tr[N];
int dia[N], dialen, idx[N];

namespace Diameter {
	int fa[N], mx, mxp;
	void DFS(int u, int f, int d) {
		fa[u] = f;
		if (d > mx) mx = d, mxp = u;
		for (int v : tr[u]) if (v != f)
			DFS(v, u, d + 1);
	}
	void getdia() {
		mx = -1; DFS(1, 0, 1); int s = mxp;
		mx = -1; DFS(s, 0, 1); int t = mxp;
		for (int i = t; i; i = fa[i]) dia[++ dialen] = i;
	}
}

int mxdep[N]; bool india[N];
void DFS0(int u, int f) {
	mxdep[u] = 0;
	for (int v : tr[u]) if (!india[v] && v != f)
		DFS0(v, u), mxdep[u] = max(mxdep[u], mxdep[v] + 1);
}

int lft[N]; 
int F[N][2], q[N], fr, tl;

bool check(int lim) {
	int cnt = m;
	for (int i = 1; i <= dialen; i ++) lft[i] = 0, F[i][0] = INF, F[i][1] = INF;
	for (int i = 1; i <= n; i ++) {
		if (mxdep[i] >= lim) {
			if (india[i]) lft[idx[i]] = idx[i];
			else -- cnt;
		} else if (india[i]) {
			int t = lim - mxdep[i];
			lft[min(dialen, idx[i] + t)] = max(lft[min(dialen, idx[i] + t)], max(1, idx[i] - t));
		}
	}
	
	for (int i = 1; i <= dialen; i ++) lft[i] = max(lft[i - 1], lft[i]);
	fr = 1, tl = 0;
	bool zero = true;
	for (int i = 1; i <= dialen; i ++) {
		if (zero) F[i][0] = 1;
		F[i][0] = min(F[i][0], F[i - 1][0] + 1);
		F[i][1] = F[i - 1][1] + 1;
		if (fr <= tl) F[i][1] = min(F[i][1], F[q[fr]][0] + 1);
		while (fr <= tl && F[q[tl]][0] >= F[i][0]) tl --;
		q[++ tl] = i;
		if (lft[i]) {
			zero = false;
			while (fr <= tl && q[fr] < lft[i]) ++ fr;
		}
	}
	int res = INF;
	if (zero) res = 0;
	for (int i = lft[dialen]; i <= dialen; i ++) res = min(res, min(F[i][0], F[i][1]));
	return res <= cnt;
}

void Main() {
	cin >> n >> m;
	for (int i = 1, u, v; i < n; i ++)
		cin >> u >> v, tr[u].push_back(v), tr[v].push_back(u);
	Diameter::getdia();
	
	for (int i = 1; i <= dialen; i ++) india[dia[i]] = true, idx[dia[i]] = i;
	for (int i = 1; i <= dialen; i ++) DFS0(dia[i], 0);

	int l = 0, r = n;
	while (l + 1 < r) {
		int mid = (l + r) >> 1;
		if (check(mid)) r = mid;
		else l = mid;
	}
	cout << (check(l) ? l : r) << "\n";
	for (int i = 1; i <= n; i ++) 
		tr[i].clear(), mxdep[i] = 0, dia[i] = 0, india[i] = 0, idx[i] = 0;
	dialen = 0;
	return ;
}

}

int main() {
	freopen("hub.in", "r", stdin); freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int typ, _; cin >> typ >> _;
	while (_ --) Yukari::Main();
	return 0;
}