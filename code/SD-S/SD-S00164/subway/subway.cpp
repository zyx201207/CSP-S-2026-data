#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int M=5e5+5;
int c,n,m,d,qq;
long long val[M];
struct edge{int v;int w;};
vector <edge> g[M+10*N];
int k;
int cnt;
long long dis[M+10*N];
long long ans;
void dij(int s,int t)
{
	priority_queue <pair<int,int> > q;
	q.push({s,0});
	dis[s]=0;
	while(q.size())
	{
		int x=q.top().first;
		q.pop();
		if(x==t)
		{
			ans=min(ans,dis[t]);
			break;
		}
		for(auto to:g[x])
		{
			int y=to.v;
			int w=to.w;
			if(dis[y]<=dis[x]+w) continue;
			dis[y]=dis[x]+w;
			if(dis[y]>=ans) continue;
			q.push({y,-dis[y]});
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	freopen("subway6.in","r",stdin);
//	freopen("1.out","w",stdout);
	cin>>c>>n>>m>>d>>qq;
	cnt=m+1;
	for(int i=1;i<=m;i++) scanf("%lld",&val[i]);
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int now,t;
			cin>>now>>t;
			g[now].push_back({cnt,t});
			g[cnt].push_back({now,t});
		}
		cnt++;
	}
	while(qq--)
	{
		memset(dis,0x3f,sizeof(dis));
		ans=dis[0];
		int x,y;
		cin>>x>>y;
		dij(x,y);
		printf("%lld\n",ans+val[x]+val[y]);
	}
	return 0;
}
