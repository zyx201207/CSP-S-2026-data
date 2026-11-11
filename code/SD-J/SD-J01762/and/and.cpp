#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans;
long long a[200010];
bool vis[200010];
void dfs(int x,long long s)
{
	if(x>m)
	{
		ans=max(ans,s);
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			vis[i]=1;
			dfs(x+1,s&a[i]);
			vis[i]=0;
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
	}
	for(int i=1;i<=n;i++)
	{
		dfs(1,a[i]);
	}
	cout<<ans;
	return 0;
}

