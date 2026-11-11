//SN-J00802 王欣甜 西安市铁一中学
#include <bits/stdc++.h>
#define ls p << 1
#define rs p << 1 | 1
#define mid ((l + r) / 2)
using namespace std;
const int maxn = 5e5 + 5;
int n, m;
int a[maxn], lst[maxn];
int id[maxn], cnt;
int ans[maxn];
int pre[maxn];
int t[maxn * 4];
void modify(int p, int l, int r, int x, int d) {
	if(x == 0)return;
	if(l == r) {
		t[p] = d;
		return;
	}
	if(x <= mid)modify(ls, l, mid, x, d);
	else modify(rs, mid + 1, r, x, d);
	t[p] = max(t[ls], t[rs]);
}
int query(int p, int l, int r, int ql, int qr) {
	if(ql > qr)return 0;
	if(ql <= l && qr >= r) {
		return t[p];
	}
	int ret = 0;
	if(ql <= mid)ret = max(ret, query(ls, l, mid, ql, qr));
	if(qr > mid)ret = max(ret, query(rs, mid + 1, r, ql, qr));
	return ret;
}
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		pre[i] = lst[a[i]];
		lst[a[i]] = i;
	}
//	for(int i = 1; i <= n; i++)cout << pre[i] << " ";
//	cout << endl;
	for(int i = n; i; i--) {
		modify(1, 1, m, id[a[i + 1]], pre[i + 1]);
		ans[a[i]] += i - query(1, 1, m, 1, cnt);
		if(!id[a[i]])id[a[i]] = ++cnt;
	}
	for(int i = 1; i <= m; i++)cout << ans[i] << " ";
} 
