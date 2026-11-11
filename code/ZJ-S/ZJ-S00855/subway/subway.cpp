#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,x,y;
int w[1010];
struct edge{
	int x,t; 
};
int ti[1010][20101];
int ans;
int vis[1010];
vector<int> s[1010];
vector<int> mp[1010];
void dfs(int xx,int time)
{
	if(xx==y)
	{
		ans=min(ans,time);
		return ;
	}
	for(int sub:s[xx])
	{
		for(int t:mp[sub])
		{
			if(vis[t]==1) continue;
			vis[t]=1;
			dfs(t,time+ti[sub][xx]+ti[sub][t]);
			vis[t]=0;
		}
	}
	return ;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int a,time;
			cin>>a>>time;
			ti[i][a]=time;
			s[a].push_back(i);
			mp[i].push_back(a);
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x>>y;
		ans=1e9;
		dfs(x,0);
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}