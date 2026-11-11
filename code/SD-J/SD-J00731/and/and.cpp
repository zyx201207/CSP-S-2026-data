#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#define endl '\n'
#define lc (x << 1)
#define rc (x << 1 | 1)
#define mid ((l + r) >> 1)

using namespace std;

typedef long long ll;

const int N = 2e5 + 10;
int n, m, res;
int a[N], sum[N << 2];

void pushup(int x)
{
	sum[x] = sum[lc] & sum[rc];
}

void build(int x, int l, int r)
{
	if(l == r)
	{
		sum[x] = a[l];
		return;
	}
	build(lc, l, mid);
	build(rc, mid + 1, r);
	pushup(x);
}

int query(int x, int l, int r, int from, int to)
{
	if(from <= l && r <= to)
	{
		return sum[x];
	}
	if(from <= mid) res &= query(lc, l, mid, from, to);
	if(to > mid) res &= query(rc, mid + 1, r, from, to);
	return res;
} 

bool cmp(int x, int y)
{
	return x > y;
}

signed main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	int maxn = 0, minn = 0x3f3f3f3f;
	bool flag = 1;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(a[i] != i - 1) flag = 0;
		maxn = max(maxn, a[i]);
		minn = min(minn, a[i]);
	}
	build(1, 1, n);
	if(m == 1)
	{
//		cout << 1;
		cout << maxn;
		return 0;
	}
	if(m == n)
	{
//		cout << 2;
		cout << query(1, 1, n, 1, n);
		return 0;
	}
	if(m == 2)
	{
//		cout << 3;
		int ans = 0;
		for(int i = 1; i <= n; i++)
		{
			for(int j = i + 1; j <= n; j++)
			{
				ans = max(ans, a[i] & a[j]);
			}
		}
		cout << ans;
		return 0;
	}
	if(m == n - 1)
	{
//		cout << 4;
		int ans = 0; 
		for(int i = 2; i < n; i++)
		{
			int cnt1 = 0, cnt2 = 0;
			res = a[1];
			cnt1 += query(1, 1, n, 1, i - 1);
			res = a[i + 1];
			cnt2 += query(1, 1, n, i + 1, n);
			ans = max(ans, cnt1 & cnt2);
		}
		cout << ans;
		return 0;
	}
	sort(a + 1, a + n + 1, cmp);
	cout << a[m];
	return 0;
}
/*
5 4
31 3 1 15 7
*/
//kskbl 
