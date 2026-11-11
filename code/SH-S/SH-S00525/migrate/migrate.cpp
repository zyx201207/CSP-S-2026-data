#include <bits/stdc++.h>
using namespace std;
#define int long long int
int minn = 1e9,cnt = 0;
int vis[1000005];
int x[1000005];
		int n,d;
void dfs(int now,int end,int dis)
{
	if (now == end)
	{
		if (dis < minn)
		{
			cnt = 1;
			minn = dis;
		}
		else if (dis == minn)
			cnt++;
	}
	for (int i = 1;i <= n;i++)
	{
		if (!vis[i] && abs(x[i] - x[now]) <= d)
		{
			vis[i] = 1;
			dfs(i,end,dis+1);
			vis[i] = 0;
		}
	}
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6


*/
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	if (c == 11 || c == 12)
	{
		while (t--)
		{
			int n,d;
			cin >> n >> d;
			for (int i = 1;i <= n;i++)
			{
				cin >> x[i];
			}
		}
		return 0;
	}
	while (t--)
	{
		cin >> n >> d;
		for (int i = 1;i <= n;i++)
		{
			cin >> x[i];
			vis[i] = 0;
		}
		int ans = 0;
		for (int i = 1;i <= n;i++)
		{
			for (int j = i;j <= n;j++)
			{
				minn = 1e9;
				cnt = 0;
				dfs(i,j,0);
				ans += (cnt == 2);
			}
		}
		cout << ans << '\n';
	}
}
