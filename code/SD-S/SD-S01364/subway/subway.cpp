#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <cstdio>
using namespace std;
long long c,n,m,d,q,w[100005],dis[10005][505],f[505][10005];
struct Node{long long v,tp;};
vector<Node>vec[100005];
long long spfa(int s,int e)
{
	memset(dis,0x3f,sizeof(dis));
	priority_queue<pair<long long,pair<int,int>>,vector<pair<long long,pair<int,int>>>,greater<pair<long long,pair<int,int>>>>q;
	for(int i=1;i<=m;i++)q.push({f[i][s],{i,s}}),dis[s][i]=f[i][s];
	while(!q.empty())
	{
		int tp1=q.top().second.first,u=q.top().second.second;
		q.pop();
		for(int p=0;p<vec[u].size();p++)
		{
			long long v=vec[u][p].v,tp2=vec[u][p].tp;
			if(tp1==tp2)
			{
				if(dis[v][tp2]>dis[u][tp1])
				{
					dis[v][tp2]=dis[u][tp1];
					q.push({dis[v][tp2],{tp2,v}});
				}
			}
			else
			{
				if(dis[v][tp2]>dis[u][tp1]+f[tp1][u]+f[tp2][v])
				{
					dis[v][tp2]=dis[u][tp1]+f[tp1][u]+f[tp2][u];
					q.push({dis[v][tp2],{tp2,v}});
				}
			}
		}
	}
	long long ans=0x3f3f3f3f3f3f3f3f;
	for(int i=1;i<=m;i++)ans=min(ans,dis[e][i]+f[i][e]);
	return ans;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(f,0x3f,sizeof(f));
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=n;i++)cin>>w[i];
	for(int i=1,k;i<=m;i++)
	{
		cin>>k;
		long long a,t,la=0;
		while(k--)
		{
			cin>>a>>t;
			f[i][a]=t;
			if(la)vec[a].push_back({la,i}),vec[la].push_back({a,i});
			la=a;
		}
	}
	while(q--)
	{
		int u,v;
		cin>>u>>v;
		cout<<w[u]+w[v]+spfa(u,v)<<'\n';
	}
	return 0;
}
