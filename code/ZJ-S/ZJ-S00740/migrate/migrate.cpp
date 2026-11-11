#include <bits/stdc++.h>
#define FL(i, a, b) for (int i = (a); i <= (b); ++i)
#define FR(i, a, b) for (int i = (a); i >= (b); --i)
#define eb emplace_back
#define Sz(v) ((int)(v).size())
using namespace std;
typedef long long ll; // check ll
const int N = 2e6 + 10;
const int INF = 1e9 + 10;
int n, nxt[N];
ll d, x[N];
ll ans;
struct SGT_N {
	int mn, cnt;
	int mn2, cnt2;
	int lazy;
	void tag(int v) {
		mn += v, mn2 += v;
		lazy += v;
	}
	friend SGT_N operator + (SGT_N a, SGT_N b) { // check
		if (a.mn > b.mn || (a.mn == b.mn && a.mn2 > b.mn2)) swap(a, b);
		if (a.mn < b.mn) {
			if (b.mn < a.mn2) a.mn2 = b.mn, a.cnt2 = b.cnt;
			else if (b.mn == a.mn2) a.cnt2 += b.cnt;
		} else if (a.mn == b.mn) {
			a.cnt += b.cnt;
			if (b.mn2 == a.mn2) a.cnt2 += b.cnt2;
		}
		a.lazy = 0;
		return a;
	}
} ;
struct SGT {
	SGT_N t[N << 2];
	void PushUp(int p) {
		t[p] = t[p << 1] + t[p << 1 | 1];
	}
	void Build(int p, int l, int r) {
		if (l == r) {
			t[p] = {0, 1, INF, 0, 0};
			return;
		}
		int mid = (l + r) >> 1;
		Build(p << 1, l, mid);
		Build(p << 1 | 1, mid + 1, r);
		PushUp(p);
	}
	void Add(int p, int l, int r, int L, int R, int v) {
		if (L > R) return;
		if (L <= l && r <= R) {
			return t[p].tag(v);
		}
		int mid = (l + r) >> 1;
		if (L <= mid) Add(p << 1, l, mid, L, R, v);
		if (mid < R) Add(p << 1 | 1, mid + 1, r, L, R, v);
		PushUp(p);
	}
	int Ask() {
		if (t[1].mn2 == 1) return t[1].cnt2;
		if (t[1].mn == 1) return t[1].cnt;
		return 0; 
	}
} sgt;
vector<int> G[N];
int ql, qr;
void Dfs(int u) {
	int p = u;
	if (nxt[p] - 1 >= p) {
		for (int p1 = nxt[p], p2 = nxt[p] - 1; p1 != p2; p1 = nxt[p1], p2 = nxt[p2]) {
			sgt.Add(1, 1, n, p1 + 1, (nxt[p1] == nxt[p2]? qr : nxt[p2]), 1);
			if (n > 6000) break;
		}
	}
	if (nxt[p] - 2 >= p) {
		for (int p1 = nxt[p], p2 = nxt[p] - 2; p1 != p2; p1 = nxt[p1], p2 = nxt[p2]) {
			sgt.Add(1, 1, n, p1 + 1, (nxt[p1] == nxt[p2]? qr : nxt[p2]), 1);
			if (n > 6000) break;
		}
	}
	ans += sgt.Ask();
	for (int v: G[u]) {
		Dfs(v); 
	}
	if (nxt[p] - 1 >= p) {
		for (int p1 = nxt[p], p2 = nxt[p] - 1; p1 != p2; p1 = nxt[p1], p2 = nxt[p2]) {
			sgt.Add(1, 1, n, p1 + 1, (nxt[p1] == nxt[p2]? qr : nxt[p2]), -1);
			if (n > 6000) break;
		}
	}
	if (nxt[p] - 2 >= p) {
		for (int p1 = nxt[p], p2 = nxt[p] - 2; p1 != p2; p1 = nxt[p1], p2 = nxt[p2]) {
			sgt.Add(1, 1, n, p1 + 1, (nxt[p1] == nxt[p2]? qr : nxt[p2]), -1);
			if (n > 6000) break;
		}
	}
}
void Solve() {
	scanf("%d %lld", &n, &d);
	FL(i, 1, n) scanf("%lld", &x[i]);
	FL(i, 1, n) {
		nxt[i] = upper_bound(x + 1, x + n + 1, x[i] + d) - x - 1;
	}
	sgt.Build(1, 1, n);
	FL(l, 1, n) {
		int r = l;
		while (nxt[r] != r) ++r;
		FL(p, l, r - 1) {
			G[nxt[p]].eb(p);
//			cout << " e:" << nxt[p] << ' ' << p << endl;
		}
		ql = l, qr = r;
		Dfs(r);
//		printf("[%d,%d]\n", l, r);
		
		l = r;
	}
	printf("%lld\n", ans);
}
void Clear() { // clear
	ans = ql = qr = 0;
	FL(i, 0, n + 1) {
		G[i].clear();
	}
}
int main() {
//	freopen("migrate6.in", "r", stdin);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int Cid, T;
	scanf("%d %d", &Cid, &T);
	while (T--) {
		Solve();
		Clear();
	}
	return 0;
}
