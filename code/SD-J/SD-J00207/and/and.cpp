#include<bits/stdc++.h>
using namespace std;
int a[200005],n,m;
int dfs(int x,int y,int p) //考虑到了第x个数 ，一共选中y个数,&为p 
{	
	if(y + n - x + 1 < m) return -1;
	if(y == m) return p;
	if(p == 0)
	{
		return max(dfs(x + 1,y + 1,a[x]),dfs(x + 1,y,p));
	}
	else
	{
		return max(dfs(x + 1,y + 1,p & a[x]),dfs(x + 1,y,p));
	}
} 
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	if(m == 1)
	{
		int maxn = -1;
		for(int i = 1;i <= n;i++)
		{
			maxn = max(maxn,a[i]);
		}
		cout << maxn;
		return 0;
	}
	else if(m == 2)
	{
		int maxn = -1;
		for(int i = 1;i <= n;i++)
		{
			for(int j = i + 1;j <= n;j++)
			{
				maxn = max(maxn,a[i] & a[j]);
			}
		}
		cout << maxn;
		return 0;
	}
	else if(m == n)
	{
		int ans = a[1];
		for(int i = 2;i <= n;i++)
		{
			ans = ans & a[i];
		}
		cout << ans;
		return 0;
	}
	cout << dfs(1,0,0);
} 
