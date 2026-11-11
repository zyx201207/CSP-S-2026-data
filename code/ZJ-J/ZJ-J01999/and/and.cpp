#include<iostream>
#include<cmath>
using namespace std;
int n,m;
long long a[200005];
long long dfs(int x,long long val,int step)
{
	if (step==m)
	{
		return val;
	}
	long long da=0;
	for (int i=x+1;i<=n &&step<=m;i++)
	{
		da=max(da,dfs(i,a[i]&a[x],step+1));
	}
	long long ans=0;
	ans=max(ans,da);
	return ans;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long ans=0;
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if (n<=20)
	{
		for (int i=1;i<=n-m;i++)
		{
			ans=max(ans,dfs(i,a[i],1));
		}
		cout<<ans<<'\n';
		return 0;
	}
	else if (n<=2000)
	{
		if (m==1)
		{
			for (int i=1;i<=n;i++)
			{
				ans=max(ans,a[i]);
			}
			cout<<ans<<'\n';
			return 0;
		}
		else if (m==n)
		{
			ans=a[1];
			for (int i=2;i<=n;i++)
			{
				ans=a[i]&ans;
			}
			cout<<ans<<'\n';
			return 0;
		}
		else if (m==2)
		{
			for (int i=1;i<=n;i++)
			{
				for (int j=i+1;j<=n;j++)
				{
					ans=max(ans,a[i]&a[j]);
				}
			}
			cout<<ans<<'\n';
			return 0;
		}
	}
	else
	{
		for (int i=1;i<=n-m;i++)
		{
			ans=max(ans,dfs(i,a[i],1));
		}
		cout<<ans<<'\n';
		return 0;
	}
	return 0;
}