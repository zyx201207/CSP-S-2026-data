#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
const int M = 4 * N;
#define int long long
int n, m, ans;
int a[N], b[N];
struct node
{
	int lazy;
	int data;
}tree[M];
void build(int rt, int l, int r)
{
//	cout << "rt:" << rt << " l:" << l << " r:" << r << " b[l]:" << b[l] << endl;
	if(l > r)	return;
	if(l == r)
	{
		tree[rt].data = b[l];
		tree[rt].lazy = 0;
		return;
	}
	int mid = l + (r - l) / 2;
	build(rt * 2, l, mid);
	build(rt * 2 + 1, mid + 1, r);
	tree[rt].data = tree[rt * 2].data + tree[rt * 2 + 1].data;
	tree[rt].lazy = 0;
}
void pushdown(int rt, int l, int r)
{
	if(tree[rt].lazy == 0)	return;
	int mid = l + (r - l) / 2;
	int l1 = l, r1 = mid;
	tree[rt * 2].data += tree[rt].lazy * (r1 - l1 + 1);
	tree[rt * 2].lazy += tree[rt].lazy;
	l1 = mid + 1, r1 = r;
	tree[rt * 2 + 1].data += tree[rt].lazy * (r1 - l1 + 1);
	tree[rt * 2 + 1].lazy += tree[rt].lazy;
	tree[rt].lazy = 0;
}
void update(int rt, int l, int r, int ul, int ur, int k)
{
	if(ul > r || ur < l)	return;
	if(ul <= l && ur >= r)
	{
		tree[rt].data += k * (r - l + 1);
		tree[rt].lazy += k;
		return;
	}
	pushdown(rt, l, r);
	int mid = l + (r - l) / 2;
	update(rt * 2, l, mid, ul, ur, k);
	update(rt * 2 + 1, mid + 1, r, ul, ur, k);
	tree[rt].data = tree[rt * 2].data + tree[rt * 2 + 1].data;
}
int query(int rt, int l, int r, int ql, int qr)
{
	if(ql > r || qr < l)	return 0;
	if(ql <= l && qr >= r)
	{
		return tree[rt].data;
	}
	pushdown(rt, l, r);
	int mid = l + (r - l) / 2;
	int lcnt = query(rt * 2, l, mid, ql, qr);
	int rcnt = query(rt * 2 + 1, mid + 1, r, ql, qr);
	return lcnt + rcnt;
}
signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = n;i >= 1; i--)
	{
		b[i] = a[n] - a[i];
	}
	bool flag = 1;
	for(int i = 2; i <= n - 1; i++)
		if((a[i] - a[i - 1]) != (a[i + 1] - a[i]))	flag = 0;
//	for(int i = 1;i <= n; i++)
	//	cerr << "i:" << i << " b[i]:" << b[i] << endl;
	
	build(1, 1, n);
//	cout << tree[1].data << endl;
	for(int i = n; i >= 1; i--)
	{
		if(i < n && flag)	break;
		if(i < n)	update(1, 1, n, 1, i, a[i] - a[i + 1]);
		int l = 1, r = i - 1, res = -1;
	//	for(int j = 1; j <= n; j++)
	//	{
	//		cout << "j:" << j << " b[j]:" << query(1, 1, n, j, j) << "\n";
	//	}
	//	cout << endl << endl;
		while(l <= r)
		{
			int mid = (l + r) >> 1;
			int jcr = query(1, 1, n, mid, i - 1);
			if(jcr <= m)	r = mid - 1, res = mid;
			else 			l = mid + 1;
		}
		if(res != -1)	ans = max(ans, i - res + 1);
	//	cout << query(1, 1, n, 1, i) << endl;
	}
	//if(flag)	cout << "11111\n";
	cout << ans;
	return 0;
}
/*
10 5
-100 -90 -80 -70 -60 -50 0 0 2 1233
*/
