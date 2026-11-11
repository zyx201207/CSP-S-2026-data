/*
T3 migrate
 n 座岛屿，一条直线，
 第 i (1 ≤ i ≤ n) 座岛屿在坐标 xi，
 且 x1 < x2 < · · · < xn。
海鸟每次飞行的距离都不超过 d
若两座岛屿 i, j (1 ≤ i, j ≤ n) 满足|xi ? xj| ≤ d
可以从第 i 座岛屿直接飞到第 j 座岛屿。
总是会选择长度最短的路径。
对于两座岛屿 u, v (1 ≤ u <v ≤ n)，
若从第 u 座岛屿到第 v 座岛屿的长度最短的路径恰. 好. 有两条，
海鸟可以分成两群，分别沿其中一条飞往第 v 座岛屿
此时称 (u, v) 为双. 径. 岛. 屿. 对.
两条路径不同，当且仅当它们经过的岛屿序列不完全相同。
你需要帮助小 P 求出双径岛屿对的数量。
n <= 2e6
d <= 2e18
*/
#include <bits/stdc++.h>
using namespace std;
#define _for(i, a, b) for(int i = (a); i <= (b); ++i)
#define _rfo(i, a, b) for(int i = (a); i >= (b); --i)
using LL = long long;
using VI = vector<int>;
const int NN = 2E6 + 5;
LL X[NN], F[NN], G[NN], S[NN];
int R[NN], L[NN], c, T = 1;

struct DSU {
	int Fa[NN];
	int Find(int u) {
		return u == Fa[u] ? u : Fa[u] = Find(Fa[u]);
	}
	void Merge(int u, int v) {
		u = Find(u), v = Find(v), u = v;
	}
	void init(int n) {
		iota(Fa, Fa + n + 1, 0);
	}
} U;
LL n, d;

//lx:1/0 可以一次2/只能一样
int pd(int cur, int tar, int lx) {
//	cout << cur  << " ->" << tar << " :" << lx << "\n";
	assert(cur);
	if (X[tar] - X[cur] <= d)
		return lx == 0;
	if (U.Find(cur) == U.Find(tar))
		return lx == 0;
	if (R[cur] == L[cur])
		return pd(U.Find(cur), tar, lx);
	else if (R[cur] - L[cur] > 1)
		return 0;
	else if (lx == 0)
		return 0;
	return pd(L[cur], tar, 0) && pd(R[cur], tar, 0);
}

void solve() {
	cin >> n >> d;
	_for(i, 1, n) cin >> X[i];
	int l = 1, r = 1;//[L,R]
	while (X[r + 1] - X[l] <= d)
		++r;
	R[1] = r;
	_for(i, 2, n) {
		l++;
		if (r < l)
			r = l;
		while (r < n && X[r + 1] - X[l] <= d)
			++r;
		R[l] = r;
	}
	U.init(n);

	L[n] = n, F[n] = 0;
	_rfo(i, n - 1, 1) {
		F[i] = 1 + F[R[i]];
		L[i] = lower_bound(F + i + 1, F + n + 1, F[R[i]]) - F;
		if (L[i] == R[i])
			U.Merge(i, L[i]);
	}
	if (c <= 10) {
		LL ans = 0;
		_for(i, 1, n) _for(j, i + 1, n) {
			ans += pd(i, j, 1);
		}
		cout << ans << "\n";
	} else if (c <= 12) {
		LL nd = X[2] - X[1], k = d / nd;
		cout << n - 2 * k + 1 << "\n";
	}
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> T;
	while (T--)
		solve();
	return 0;
}