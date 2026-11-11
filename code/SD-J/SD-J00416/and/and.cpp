#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],vis[200005],maxn;
bool cmp(int x,int y)
{
	return x>y;
}
void dfs(int step,int ans)
{
	if(step>n)
	{
		if(ans!=m)
			return;
	    bool flag=0;
	    int sns=0;
		for(int i=1;i<=n;i++)
		{
			if(vis[i]==1 && flag==0)
			{
				sns=a[i];
				flag=1;
			}
			else if(vis[i]==1)
			{
				sns=sns&a[i];
			}
		}
		maxn=max(maxn,sns);
		return;
	}
	vis[step]=1;
	dfs(step+1,ans+1);
	vis[step]=0;
	dfs(step+1,ans);
	return;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	if(n<=20)
	{
		dfs(1,0);
		cout << maxn;
	}
	else
	{
		sort(a+1,a+n+1,cmp);
		bool flag=0;
		int ans=0;
		for(int i=1;i<=m;i++)
		{
			if(flag==0)
			{
				ans=a[i];
				flag=1;
			}
			else
		    {
		    	ans=ans&a[i];
			}
		}
	}
	return 0;
}
