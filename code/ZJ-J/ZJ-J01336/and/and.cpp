#include<bits/stdc++.h>
using namespace std;
int maxn,n,m,a[210000],vis[210000];
void dfs(int k,int t)
{
	if(t==m)
	{
		maxn=max(maxn,k);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==1) continue;
		if(k&a[i]<=maxn) continue;
		vis[i]=1;
		dfs(k&a[i],t+1);
		vis[i]=0;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		vis[i]=1;
		dfs(a[i],1);
		vis[i]=0;
	}
	cout<<maxn;
	return 0;
}
