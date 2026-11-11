#include<bits/stdc++.h>
#define int long long
#define lc p << 1
#define rc p << 1 | 1
using namespace std;
const int N = 2e5 + 10;
int n, a[N], m, tr[4 * N], ans;
void build(int p, int l, int r) {
	if(l == r) {
		tr[p] = a[l];
	} else {
		int mid = l + r >> 1;
		build(lc, l, mid);
		build(rc, mid + 1, r);
		tr[p] = tr[lc] & tr[rc];
	}
}
int query(int p, int l, int r, int jl, int jr) {
	if(jl <= l && r <= jr) {
		return tr[p];
	}
	int mid = l + r >> 1;
	int re1 = -1, re2 = -1, re;
	if(jl <= mid) re1 = query(lc, l, mid, jl, jr);
	if(mid < jr) re2 = query(rc, mid + 1, r,jl, jr);
	return (re1 & re2);
}
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	int ans = 0;
	build(1, 1, n);
	for(int i = 1; i + m - 1 <= n; i++) {
		ans = max(ans, query(1, 1, n, i, i + m - 1));
	}
	cout << ans;
	return 0;
}
