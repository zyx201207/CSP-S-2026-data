#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int ans;
bool f[25];
int maxx;
int sum[10];
void dfs(int n,int m,int cnt,int num)
{
	if(cnt>n)
	{
		if(num!=m)
		{
			return;
		}
		int sum=pow(2,30)-1;
		sum+=pow(2,30);
		for(int i=1;i<=n;i++)
		{
			if(f[i])
			{
				sum=sum&a[i];
			}
		}
		ans=max(ans,sum);
		return;
	}
	if(num==m)
	{
		dfs(n,m,cnt+1,num);
	}
	f[cnt]=1;
	dfs(n,m,cnt+1,num+1);
	f[cnt]=0;
	dfs(n,m,cnt+1,num);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	bool z=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxx=max(maxx,a[i]);
		double x=log2(a[i]+1);
		int y=log2(a[i]+1);
		if(x!=(double)y*1.0)
		{
			z=0;
		}
	}
	if(n<=20)
	{
		dfs(n,m,1,0);
		cout<<ans;
		return 0;
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m==n)
	{
		ans=pow(2,30)-1;
		ans+=pow(2,30);
		for(int i=1;i<=n;i++)
		{
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==2)
	{
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	if(maxx<4)
	{
		for(int i=1;i<=n;i++)
		{
			sum[a[i]]++;
		}
		if(sum[3]>=m)
		{
			ans=3;	
		}
		else if(sum[3]+sum[2]>=m)
		{
			ans=2;
		}
		else if(sum[3]+sum[1]>=m)
		{
			ans=1;
		}
		cout<<ans;
		return 0;
	}
	if(z)
	{
		ans=pow(2,30)-1;
		ans+=pow(2,30);
		sort(a+1,a+n+1);
		reverse(a+1,a+n+1);
		for(int i=1;i<=m;i++)
		{
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
