#include<bits/stdc++.h>
using namespace std;
const int Maxn=1e5+10;
const int N=501;

struct edge{
	int v,w,next;
}edge[Maxn];

int head[Maxn],cnt;

void add(int u,int v,int w)
{
	edge[++cnt].v=v;
	edge[cnt].w=w;
	edge[cnt].next=head[u];
	head[u]=cnt;
}

struct node{
	int id,num;
	friend bool operator <(node a,node b){
		return a.num>b.num;
	}
};

priority_queue<node> q;

int dis[Maxn],vis[Maxn];

int c,n,m,d,T,x,y,sum;
int w[Maxn],k[N],a[N][Maxn],t[N][Maxn];

void init()
{
	for(int i=1;i<=Maxn;i++)
		dis[i]=INT_MAX,vis[i]=0;
}

void work(int s,int pos)
{
	q.push((node){s,0});
	dis[s]=0;
	while(!q.empty())
	{
		node tmp=q.top();
		int u=tmp.id;
		for(int i=head[u];i!=0;i=edge[i].next)
		{
			int v=edge[i].v;
			if(!vis[v])
			{
				vis[v]=1;
				if(dis[v]<dis[u]+edge[i].w)
				{
					dis[v]=dis[u]+edge[i].w;
					q.push((node){v,dis[v]});
				}
			}
		}
		q.pop();
	}
	cout<<dis[pos]+w[s]+w[pos]<<'\n';
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>T;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
			if(j!=1)
				for(int to=j-1;to>=0;to--)
				{
					add(a[i][to],a[i][j],t[i][to]+t[i][j]);
					add(a[i][j],a[i][to],t[i][to]+t[i][j]);
				}
		}
	}
	while(T--)
	{
		cin>>x>>y;
		work(x,y);	
	}
	return 0;
}
