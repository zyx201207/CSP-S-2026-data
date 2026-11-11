//SN-J01007
//¶­¹ú¶°
#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int ans;
bool vis[200005];
void dfs(int p,int cnt,int last)
{
	if(p==m)
	{
		ans=max(cnt,ans);
		return;
	}
	for(int i=last+1;i<=n;i++)
	{
		if(vis[i])continue;
		vis[i]=1;
		dfs(p+1,(cnt&a[i]),i);
		vis[i]=0;
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n;
	cin>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		vis[i]=1;
		dfs(1,a[i],0);
		vis[i]=0;
	}
	cout<<ans;
	return 0;
}
