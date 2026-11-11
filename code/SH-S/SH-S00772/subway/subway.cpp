#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[1005],k[505],a[1005][505],t[1005][505];
long long dfs(long long ans,long long cur,long long end,long long dep)
{
	if(cur == end)
	{
		return ans;
	}
	if(dep > n)
	{
		return 1LL * 1e18;
	}
	long long cnt = 1LL * 1e18;
	for(int i = 1;i <= n;i++)
	{
		if(k[i] == 1)
		{
			continue;
		}
		if(a[i][1] == cur)
		{
			cnt = min(cnt,dfs(ans + t[i][1] + t[i][2],a[i][2],end,dep + 1));
		}
		if(a[i][2] == cur)
		{
			cnt = min(cnt,dfs(ans + t[i][1] + t[i][2],a[i][1],end,dep + 1));
		}
	}
	return cnt;
}
long long dfs2(long long ans,long long cur,long long end,long long dep)
{
	if(cur == end)
	{
		return ans;
	}
	if(dep > n)
	{
		return 1LL * 1e18;
	}
	long long cnt = 1LL * 1e18;
	for(int i = 1;i <= n;i++)
	{
		if(k[i] == 1)
		{
			continue;
		}
		int cu = -1;
		for(int j = 1;j <= k[i];j++)
		{
			if(a[i][j] == cur)
			{
				cu = j;
			}			
		}
		if(cu != -1)
		{
			for(int j = 1;j <= k[i];j++)
			{
				if(j == cu)
				{
					continue;
				}	
				cnt = min(cnt,dfs(ans + t[i][cu] + t[i][j],a[i][j],end,dep + 1));		
			}
		}
	}
	return cnt;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("subway.in","w",stdin);
	freopen("subway.out","r",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++)
	{
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++)
	{
		cin >> k[i];
		for(int j = 1;j <= k[i];j++)
		{
			cin >> a[i][j] >> t[i][j];
		}
	}
	if(c <= 11 && c >= 7)
	{
		for(int i = 1;i <= q;i++)
		{
			int x,y;
			cin >> x >> y;
			cout << w[x] + w[y] + dfs(0,x,y,0) << endl;
		}
	}
	else
	{
		for(int i = 1;i <= q;i++)
		{
			int x,y;
			cin >> x >> y;
			cout << w[x] + w[y] + dfs2(0,x,y,0) << endl;
		}
	}
	return 0;
} 
