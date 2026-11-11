#include<bits/stdc++.h>
using namespace std;
const long long INF=1e18;
int cid,n,m,d,q;
long long W[1000005],cnt[505];
vector<int>sp[505],gp[505];
vector<pair<int,long long>>g[1000005];
long long dis[505][505];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>cid>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>W[i];
	for(int i=1;i<=n;i++)
	{
		cin>>cnt[i];
		sp[i].resize(cnt[i]+5),gp[i].resize(cnt[i]+5);
		for(int j=1;j<=cnt[i];j++) cin>>sp[i][j]>>gp[i][j],g[sp[i][j]].push_back({i,gp[i][j]}); 
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i!=j) dis[i][j]=INF;
			else dis[i][j]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(auto x:g[i])
		{
			int u=x.first;
			long long w1=x.second;
			for(auto y:g[i])
			{
				int v=y.first;
				long long w2=y.second;
				dis[u][v]=min(dis[u][v],w1+w2);
				dis[v][u]=min(dis[v][u],w1+w2);
			}
		}
	}
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]); 
	while(q--)
	{
		int st,ed;cin>>st>>ed;
		long long ans=INF;
		for(auto x:g[st])
		{
			int u=x.first;
			long long w1=x.second;
			for(auto y:g[ed])
			{
				int v=y.first;
				long long w2=y.second;
				if(dis[u][v]!=INF) ans=min(ans,dis[u][v]+w1+w2+W[st]+W[ed]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
