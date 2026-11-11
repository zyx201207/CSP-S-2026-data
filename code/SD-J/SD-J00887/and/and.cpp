#include<bits/stdc++.h>
using namespace std;
int  n,m;
int maxx;
int a[1000000];
bool vis[100000];
void dfs(int p,int ans)
{
	if(p==0)
	{
		maxx=max(maxx,ans);
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]!=1)
		{
			vis[i]=1;
			dfs(p-1,ans&a[i]);
			vis[i]=0;
		}
	}
}
int main ()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	memset(vis,0,sizeof(vis));
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		vis[i]=1;
		dfs(m-1,a[i]);
		vis[i]=0;
	}
	cout<<maxx;
	return 0;
}
