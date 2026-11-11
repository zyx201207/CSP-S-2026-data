#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],cnt,ans,maxx=-2e9,maxn=-2e9,res,maxa=-2e9,sum,f,flag,mx=-2e9;
void dfs(int x,int t)
{
	if(cnt!=1)
	{
		ans&=x;
	}
	if(cnt==m)
	{
		maxx=max(maxx,ans);
		cnt=0;
		return;
	}
	cnt++;
	for(int i=t+1;i<=n;i++)
	{
		dfs(a[i],i);
		ans=a[i+1];
	}
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum&=a[i];
		maxn=max(maxn,a[i]);
		if(a[i]==i-1&&flag==1)
		{
			flag=1;
		}
		else
		{
			flag=0;
		}
		
	}
	if(m==1)
	{
		cout<<maxn;
		return 0;
	}
	else if(m==n)
	{
		cout<<sum;
		return 0;
	}
	else if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				maxa=max(maxa,a[i]&a[j]);
			}
		}
		cout<<maxa;
		return 0;
	}
	else if(m==n-1)
	{
		for(int i=1;i<=n;i++)
		{
			f=0;
			for(int j=1;j<=i-1;j++)
			{
				if(j==1)
				{
					f=1;
					res=a[j];
				}
				else
				{
					res&=a[j];
				}
			}
			for(int j=i+1;j<=n;j++)
			{
				if(j==i+1&&f==0)
				{
					res=a[j];
				}
				else
				{
					res&=a[j];
				}
			}
			mx=max(mx,res);
		}
		cout<<mx;
		return 0;
	}
	else if(flag==1)
	{
		cout<<0;
		return 0;
	}
	else if(n>2000)
	{
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cnt=1;
		ans=a[i];
		dfs(a[i],i);
	}
	cout<<maxx;
}
