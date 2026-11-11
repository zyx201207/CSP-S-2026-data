// by 0x0F
#include <bits/stdc++.h>
using namespace std;
#define int long long
struct Segt {
	#define ls (p << 1)
	#define rs (p << 1 | 1)
	#define len(x) (tree[x].r - tree[x].l + 1)
	struct Node {
		int l, r, val, vr, lazy;
	} tree[2000010];
	void build(int p, int l, int r) {
		tree[p].l = l, tree[p].r = r;
		tree[p].val = tree[p].lazy = tree[p].vr = 0;
		if(l == r) return;
		int mid = l + r >> 1;
		build(ls, l, mid); build(rs, mid + 1, r);
	}
	void pushup(int p) {
		tree[p].val = tree[ls].val + tree[rs].val;
		tree[p].vr = tree[rs].vr;
	}
	void pushdown(int p) {
		if (tree[p].lazy == 0) return;
		tree[ls].val += len(ls) * tree[p].lazy, tree[ls].lazy += tree[p].lazy;
		tree[rs].val += len(rs) * tree[p].lazy, tree[rs].lazy += tree[p].lazy;
		tree[ls].vr += tree[p].lazy, tree[rs].vr += tree[p].lazy;
		tree[p].lazy = 0;
	}
	void modify(int p, int L, int R, int val) {
		if (L <= tree[p].l && tree[p].r <= R) {
			tree[p].val += len(p) * val, tree[p].lazy += val;
			tree[p].vr += val;
			return;
		}
		pushdown(p);
		int mid = tree[p].l + tree[p].r >> 1;
		if (L <= mid) modify(ls, L, R, val);
		if (mid < R) modify(rs, L, R, val);
		pushup(p);
	}
	int find(int p, int l, int r, int lmt) {
		if (tree[p].l == tree[p].r) return tree[p].l;
		pushdown(p);
		int mid = tree[p].l + tree[p].r >> 1;
		if (tree[rs].val + tree[ls].vr <= lmt) return find(ls, l, mid, lmt - tree[rs].val);
		else find(rs, mid + 1, r, lmt);
	}
	int query(int p, int L, int R) {
		if (L <= tree[p].l && tree[p].r <= R) return tree[p].val;
		pushdown(p);
		int mid = tree[p].l + tree[p].r >> 1, ans = 0;
		if (L <= mid) ans += query(ls, L, R);
		if (mid < R) ans += query(rs, L, R);
		return ans;
	}
} s;
int a[500010];
void solve() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	s.build(1, 1, n);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (i > 1) s.modify(1, 1, i - 1, a[i] - a[i - 1]);
		int p = s.find(1, 1, n, m);
		ans = max(ans, i - p + 1);
	}
	cout << ans << endl;
}
signed main() {
	ios::sync_with_stdio(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int T = 1;
//	cin >> T;
	while (T--) solve();
	return 0;
}
