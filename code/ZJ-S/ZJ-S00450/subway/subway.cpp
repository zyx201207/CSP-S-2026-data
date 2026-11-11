#include<bits/stdc++.h>
using namespace std;
const int N=6e5+10;
vector<int> t[N],a[N];
int c,n,m,d,q,k[N],vis[N];
long long dis[N],ans,w[N];
struct edge{
	int to;
	long long w;
};
vector<edge>v[N];
struct node{
	int x;
	long long dis;
	bool operator<(const node&cmp)const{
		return dis>cmp.dis;
	}
};

void dijkstra(int s,int t){
	priority_queue<node>q;
	for(int i=1;i<=m+n;i++)dis[i]=1e18+10;
	for(int i=1;i<=m+n;i++)vis[i]=0;
	q.push({s+n,0});
	dis[s+n]=0;
	while(!q.empty())
	{
		node f=q.top();q.pop();
		if(f.dis>dis[f.x])continue;
		vis[f.x]=1;
		if(f.x==t+n)
		{
			ans=dis[f.x];
			return;
		}
		for(int i=0;i<v[f.x].size();i++)
		{
			int to=v[f.x][i].to;
			if(vis[to])continue;
			int w=v[f.x][i].w;
			if(dis[f.x]+w<dis[to])
			{
				dis[to]=dis[f.x]+w,q.push({to,dis[to]});
			}
		}
	}
	ans=-1;
	return;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%d",&w[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			v[x+n].push_back({i,y});
			v[i].push_back({x+n,y});
		}
	}
	while(q--)
	{
		int s,t;
		scanf("%d%d",&s,&t);
		dijkstra(s,t);
		printf("%lld\n",ans+w[s]+w[t]);
//		cout<<ans+w[s]+w[t]<<endl;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/