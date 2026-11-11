#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=2e5+10;
int n,m,a[MAXN],ans=-1;
void dfs(int x,int now,int step)
{
	if(step==m)
	{
		ans=max(ans,now);
		return;
	}
	if(now<ans)
	{
		return;
	}
	for(int i=x+1;i<=n;i++)
	{
		if(x==0)
		{
			dfs(i,a[i],1);
		}
		else
		{
			dfs(i,now&a[i],step+1);
		}
	}
	return;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==m)
	{
		ans=a[1];
		for(int i=1;i<=n;i++)
		{
			ans&=a[i];
		}
	}
	else if(m==n-1)
	{
		int minn=INT_MAX,mini=-1;
		for(int i=1;i<=n;i++)
		{
			if(a[i]<minn)
			{
				mini=i;
				minn=a[i];
			}
		}
		ans=a[(mini+1)%n];
		for(int i=1;i<=n;i++)
		{
			if(i!=(mini+1)%n and i!=mini)
			{
				ans&=a[i];
			}
		}
	}
	else if(n<=20 or m<=n)
	{
		dfs(0,0,0);
	}
	else
	{
		sort(a+1,a+n+1,greater<int>());
		ans=a[1];
		for(int i=1;i<=m;i++)
		{
			ans&=a[i];
		}
	}
	cout<<ans;
	return 0;
}
/*
3
2 a
2 b
1 c
*/