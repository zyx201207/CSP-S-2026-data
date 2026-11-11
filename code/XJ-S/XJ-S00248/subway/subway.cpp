#include <bits/stdc++.h>
using namespace std;
const int N=500+5;
const int M=5e4+5;
const int inf=0x3f3f3f3f;
int c,n,m,d,q,ans;
int w[N],k[N];
int ti[M][N];
int head[M],nxt[M],to[M],tot;
int lin[M];
void add(int x,int y,int z)
{
	nxt[++tot]=head[x];
	to[tot]=y;
	lin[tot]=z;
	head[x]=tot;
}

struct node{
	int v,lin,w,flag;
};
int vis[M][N],visl[N];
//int dist[M][N];
bool operator <(node x,node y)
{
	if(x.w!=y.w) return x.w>y.w; 
	return visl[x.lin]>visl[y.lin];
}
int bfs(int s,int e)
{
	int ans=w[e]+w[s];
	priority_queue<node> q;
//	node t;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			vis[i][j]=0;
//			dist[i][j]=inf;
		}
	}
	for(int j=1;j<=n;j++)visl[j]=0;
	for(int i=1;i<=n;i++)
	{
		if(ti[s][i]){
			q.push({s,i,ti[s][i],0});
		}
	}
	while(!q.empty())
	{
		node t=q.top();
		q.pop();
		if(vis[t.v][t.lin]||visl[t.lin]>d)continue;
		vis[t.v][t.lin]=1;
		visl[t.lin]+=t.flag;
		if(t.v==e)
		{
			ans+=t.w+ti[t.v][t.lin];
			break;
		}
		for(int i=head[t.v];i;i=nxt[i]){
			int v=to[i],li=lin[i];
			if(vis[v][li]||li!=t.lin)continue;
			if(t.flag)continue;
			q.push({v,li,t.w,1});
//			cout<<v<<" "<<li<<" "<<t.w<<" "<<ti[v][li]<<'\n';
		}
		for(int i=1;i<=n;i++)
		{
			if(ti[t.v][i]&&!vis[t.v][i]&&i!=t.lin){
				q.push({t.v,i,t.w+ti[t.v][i]+ti[t.v][t.lin],0});
//				cout<<ti[t.v][i]<<" "<<ti[t.v][t.lin]<<'\n';
			}
		}
	}
	return ans;
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1,t1,t2;i<=n;i++)
	{
		cin>>k[i];
		cin>>t1>>t2;
		ti[t1][i]=t2;
		for(int j=2,x,y;j<=k[i];j++)
		{
			cin>>x>>y;
			ti[x][i]=y;
			add(t1,x,i);
			add(x,t1,i);
		}
	}
	int x,y;
	while(q--)
	{
		cin>>x>>y;
		cout<<bfs(x,y)<<'\n';
	}
	return 0;
}

