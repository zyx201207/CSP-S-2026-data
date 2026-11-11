#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],b[200005],ans=-1,maxn=-1;
bool vis[200005];
void print()
{
	long long k=b[1];
	for(int i=2;i<=m;i++)
		k=(k&b[i]);
	ans=max(ans,k);
}
void dfs(int dep)
{
	if(dep==m+1)
	{
		print();
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==false)
		{
			vis[i]=true;
			b[dep]=a[i];
			dfs(dep+1);
			vis[i]=false;
		}
	} 
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(m==1)
	{
		cout<<maxn;
		return 0;
	}
	if(m==n)
	{
		long long k=a[1];
		for(int i=2;i<=n;i++)
		k=(k&a[i]);
		cout<<k;
		return 0;
	}
	if(n<=2000)
	{
		memset(vis,false,sizeof(vis));
		dfs(1);
		cout<<ans;
	}
	else
	{
		sort(a+1,a+n+1);
		if(m==n-1)
		{
			long long k=a[2];
			for(int i=3;i<=n;i++)
				k=k&a[i];
			cout<<k;
			return 0;
		}
		if(m==2)
		{
			cout<<(a[n]&a[n-1]);
			return 0;
		}
		cout<<a[n];
	}
	return 0;
}
