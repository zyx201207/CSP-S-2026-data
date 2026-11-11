#include<bits/stdc++.h>//T3
using namespace std;
int c,T,n,d,cnt,mdep;
int a[2000005];
int vis[2000005];
void dfs(int x,int y,int dep)
{
	if(x==y)
	{
		if(mdep==dep)cnt++;
		mdep=min(mdep,dep);
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		vis[i]=1;
		if(abs(a[x]-a[i])<=d) dfs(i,y,dep+1);
		vis[i]=0;
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				vis[i]=1;cnt=0;mdep=1e9;
				dfs(i,j,1);
				vis[i]=1;cnt=0;
				dfs(i,j,1);
				vis[i]=0;
				if(cnt==2) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
