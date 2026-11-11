#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m;
bool flag = 0;
int ans = -1;
int a[N]; bool b[N];
struct num
{
	int val, cnt;
	bool operator < (const num & o) const
	{
		if (cnt != o.cnt)
			return cnt > o.cnt;
		else
			return val > o.val;
	}
} nm[N];
inline int read()
{
	int x = 0, c = getchar(), k = 1;
	while (c != '-' && (c < '0' || c > '9')) c = getchar();
	if (c == '-') k = -1, c = getchar();
	do x = x * 10 + (c ^ 48), c = getchar();
	while ('0' <= c && c <= '9');
	return x * k; 
}
inline void write(int x)
{
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) write(x / 10);
	putchar(x % 10 ^ 48);
}
void dfs(int u, int ch)
{
	if (ch >= m)
	{
		int res = INT_MAX;
		if (!flag)
		{
			for (int i = 1; i <= n; i ++)
				if (b[i]) res &= a[i];
		}
		else
		{
			for (int i = 1; i <= n; i ++)
			{
				if (!b[i])
				{
					res &= a[i];
					write(a[i]);
				}
			}
		}
		ans = max(res, ans);
		return;
	}
	if (ch > m)
		return;
	if (n - u + 1 + ch < m)
		return;
	b[u] = 0; dfs(u + 1, ch);
	b[u] = 1; dfs(u + 1, ch + 1);
	b[u] = 0;
}
signed main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	n = read(), m = read();
	int mid = (1 + n) >> 1;
	bool flag = 1;
	for (int i = 1; i <= n; i ++)
	{
		a[i] = read();
		if (a[i] != i - 1) flag = 0;
	}
	if (n <= 2000 || m == n - 1)
	{
		if (m > mid)
		{
			m = n - m;
			flag = 1;
		}
		dfs(1, 0);
		write(ans);
	}
	else if (flag)
	{
		ans = INT_MAX;
		for (int i = n; i >= n - m + 1; i --)
			ans &= a[i];
		write(ans);
	}
	else
	{
		for (int i = 1; i <= n; i ++)
		{
			int x = a[i];
			nm[i].val = a[i];
			while (x)
			{
				if (x & 1) nm[i].cnt ++;
				x >>= 1;
			}
		}
		sort(nm + 1, nm + n + 1);
		ans = INT_MAX;
		for (int i = 1; i <= m; i ++)
			ans &= nm[i].val;
		write(ans);
	}
	return 0;
}
