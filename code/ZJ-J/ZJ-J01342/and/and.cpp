#include<bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, m;
long long a[N];
int f[N];
long long ans;
int FB = 1;
bool cmp(long long nu1, long long nu2)
{
	return nu1 > nu2;
}
void dfs(long long k, long long sum)
{
	if (k == m)
	{
		if (ans < sum)
		{
			ans = sum;
		}
		return;
	}
	if (sum == 0)
	{
		return;
	}
	if (sum <= ans)
	{
		return;
	}
	for (int i = 1; i <= n; i ++)
	{
		if (f[i])
		{
			continue;
		}
		f[i] = 1;
		dfs(k + 1, sum & a[i]);
		f[i] = 0;
	}
}
long long sovelB()
{
	long long sum = a[1];
	long long an = 0;
	for (int i = 2; i <= m; i ++)
	{
		sum = sum & a[i];
	}
	ans = sum;
	int j = 1;
	for (int i = m + 1; i <= n; i ++)
	{
		sum = sum & (!a[j]);
		j ++;
		sum = sum & a[i];
		if (an < sum)
		{
			an = sum;
		}
	}
	return an;
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		if (a[i] != i - 1)
		{
			FB = 0;
		}
	}
	sort(a + 1, a + n + 1, cmp);
	if (FB)
	{
		cout << sovelB();
		return 0;
	}
	else if (n >= 3000)
	{
		cout << a[m];
		return 0;
	}
	for (int i = 1; i <= n; i ++)
	{
		memset(f, 0, sizeof(f));
		f[i] = 1;
		dfs(1, a[i]);
	}
	cout << ans;
	return 0;
}