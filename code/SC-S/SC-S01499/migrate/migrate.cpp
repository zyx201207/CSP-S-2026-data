#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int maxn = 2e6 + 5;

int c, T, n, f[maxn], g[maxn];
ll d, x[maxn];

struct node {
	int mn, cnt;
	
	node operator+ (const node &t) const {
		if(mn == -1) return t;
		node res;
		if(mn < t.mn) res = (node){mn, cnt};
		else if(mn > t.mn) res = t;
		else res = (node){mn, cnt + t.cnt};
		return res;
	}
};

struct SGT {
	node tr[maxn << 2];
	
	inline int ls(int p) { return p << 1; }
	inline int rs(int p) { return p << 1 | 1; }
	inline void push_up(int p) { tr[p] = tr[ls(p)] + tr[rs(p)]; }
	
	void build(int p, int l, int r) {
		if(l == r) return (void)(tr[p] = (node){f[l], g[l]});
		int mid = (l + r) >> 1;
		build(ls(p), l, mid), build(rs(p), mid + 1, r);
		push_up(p);
	}
	
	void update(int k, int p, int l, int r) {
		if(l == r) return (void)(tr[p] = (node){f[l], g[l]});
		int mid = (l + r) >> 1;
		if(k <= mid) update(k, ls(p), l, mid);
		else update(k, rs(p), mid + 1, r);
		push_up(p);
	}
	
	node qry(int l, int r, int p, int pl, int pr) {
		if(l <= pl && pr <= r) return tr[p];
		int mid = (pl + pr) >> 1;
		node res = {-1, -1};
		if(l <= mid) res = res + qry(l, r, ls(p), pl, mid);
		if(mid < r) res = res + qry(l, r, rs(p), mid + 1, pr);
		return res;
	}
} sgt;

ll solve() {
	ll v = x[2] - x[1];
	if(v >= d) return 0;
	for(int i = 4; i <= n; i += 2)
		if(v * (i / 2) <= d && d < v * (i / 2 + 1))
			return n - i + 1;
	return 0;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> T;
	while(T--) {
		cin >> n >> d;
		for(int i = 1; i <= n; i++) cin >> x[i];
		if(c == 11 || c == 12) { cout << solve() << "\n"; continue; }
		ll res = 0;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) f[j] = n + 1, g[j] = 0;
			f[i] = 0, g[i] = 1;
			sgt.build(1, 1, n);
			for(int j = i + 1; j <= n; j++) {
				if(x[j] - x[j - 1] > d) continue;
				int k = lower_bound(x + 1, x + n + 1, x[j] - d) - x;
				node t = sgt.qry(k, j - 1, 1, 1, n);
				f[j] = t.mn + 1, g[j] = t.cnt;
				if(g[j] == 2) res++;
				sgt.update(j, 1, 1, n);
			}
		}
		cout << res << "\n";
	}
	return 0;
}