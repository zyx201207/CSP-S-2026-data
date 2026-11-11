#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],qly=-1e18,ans[200005];
bool flag=true,flagg=true,flaggg=true,vis[200005];
map<long long,long long>mp;
void dfs(int x)
{
	if(x==m+1)
	{
		long long maxx=ans[1];
		for(int i=2;i<=m;i++)
		{
			maxx&=ans[i];
		}
		qly=max(qly,maxx);
		return;
	}
	else
	{
		for(int i=x;i<=n;i++)
		{
			if(vis[i]==false)
			{
				vis[i]=true;
				ans[x]=a[i];
				dfs(x+1);
				ans[x]=0;
				vis[i]=false;
			}
		}
	}
}
int main()
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
		if(i!=1&&a[i]!=a[i-1])
		{
			flag=false;
		}
		if(a[i]!=i-1)
		{
			flagg=false;
		}
		if(a[i]>=4)
		{
			flaggg=false;
		}
		if(a[i]<=4)
		{
			mp[a[i]]++;
		}
	}
	if(n<=20)
	{
		dfs(1);
		cout<<qly;
	}
	else if(n<=2000&&m==1)
	{
		for(int i=1;i<=n;i++)
		{
			qly=max(qly,a[i]);
		}
		cout<<qly;
	}
	else if(n<=2000&&m==n)
	{
		qly=a[1];
		for(int i=2;i<=n;i++)
		{
			qly&=a[i];
		}
		cout<<qly;
	}
	else if(n<=2000&&m==2)
	{
		dfs(1);
		cout<<qly;
	}
	else if(flag==true)
	{
		cout<<a[1];
	}
	else if(flagg==true)
	{
		sort(a+1,a+1+n);
		long long qly=a[n];
		for(int i=2;i<=m;i++)
		{
			qly&=a[n-i+1];
		}
		cout<<qly;
	}
	else if(flaggg==true)
	{
		if(m==1&&mp[3]!=0)
		{
			cout<<3;
		}
		else if(mp[3]>=m)
		{
			cout<<3;
		}
		else if(mp[3]+mp[2]>=m)
		{
			cout<<2;
		}
		else if(mp[3]+mp[1]>=m)
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	else 
	{
		cout<<0;
	}
	return 0;
}
/*
4 2
3 15 12 12
*/