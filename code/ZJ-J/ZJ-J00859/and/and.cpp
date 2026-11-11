#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,m;
ll a[200005],mx;
bool vis[200005];
void dfs(int x,ll v)
{
	if(x==m+1)
		mx=max(mx,v);
	else
	{
		for(int i=1;i<=n;i++)
			if(!vis[i])
			{
				vis[i]=1;
				if(x==1)
					dfs(x+1,a[i]);
				else
					dfs(x+1,v&a[i]);
				vis[i]=0;
			}
	}
}
bool A()
{
	for(int i=1;i<=n;i++)
		if(a[i]&a[i]+1!=0)
			return false;
	return true;
}
bool B()
{
	for(int i=1;i<=n;i++)
		if(a[i]!=i-1)
			return false;
	return true;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(m==1)
	{
		for(int i=1;i<=n;i++)
			mx=max(mx,a[i]);
		cout<<mx;
	}
	else if(m==n)
	{
		ll ans=a[1];
		for(int i=2;i<=n;i++)
			ans=ans&a[i];
		cout<<ans;
	}
	else if(m==2&&n<=10000)
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i!=j)
					mx=max(mx,a[i]&a[j]);
		cout<<mx;
	}
	else if(n<=20)
	{
		dfs(1,0);
		cout<<mx;
	}
	else if(A())
	{
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
	}
	else if(B())
	{
		cout<<n-m;
	}
}