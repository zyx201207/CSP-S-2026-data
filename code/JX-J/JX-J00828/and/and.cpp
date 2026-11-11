#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	long long n, m, a[200005] = {0};
	long long sum = 4294967295, maxn = -1e18;
	bool vis[200005] = {0};
	cin >> n >> m;
	for(long long i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for(long long i = 1; i <= m; i++)
	{
		long long x, maxx = -1e18;
		for(long long j = 1; j <= n; j++)
		{
			if((sum & a[j]) >= maxx && vis[j] == 0)
			{
				x = j;
				maxx = sum & a[j];
			}
		}
		sum = sum & a[x];
		maxn = maxx;
		vis[x] = 1;
	}
	cout << maxn;
	return 0;
}
