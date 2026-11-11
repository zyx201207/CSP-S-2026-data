#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long dp[200005];
int n,m;
long long fun()
{
	long long maxx=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i!=j)
			{
				maxx=max(maxx,a[i]&a[j]);
			}
		}
	}
	return maxx;
}
long long funn()
{
	int maxx=a[1];
	for(int i=2;i<=n;i++)
	{
		maxx&=a[i];
	} 
	return maxx;
}
int maxn=0;
int v[200005];
void dfs(int cnt,int sum)
{
	if(cnt==m)
	{
		maxn=max(maxn,sum);
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(v[i]==0)
		{
			v[i]=1;
			if(cnt==0)
			{
				dfs(cnt+1,a[i]);
			}
			else dfs(cnt+1,sum&a[i]);
			v[i]=0;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long maxx=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(m==1)
	{
		cout<<maxx;
		return 0;
	}
	if(m==2)
	{
		cout<<fun();
		return 0; 
	}
	if(m==n)
	{
		cout<<funn();
		return 0;
	}
	if(n<=20)
	{
		dfs(0,0);
		cout<<maxn;
		return 0;
	}
	sort(a+1,a+1+n);
	int ans=a[n];
	for(int j=n-1;j>=n-m+1;j--)
	{
		ans&=a[j];
	}
	cout<<ans;
	return 0;
}
