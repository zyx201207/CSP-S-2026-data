#include<bits/stdc++.h>
#include<queue>
using namespace std;
#define PII pair<int,int>
int e[1001000][3];
int h[555555];
int cnt;
int dis[555555];
int W[500100];
int c,n,m,d,q;
inline void add(int u,int v,int w)
{
	e[++cnt][0]=h[u];
	e[cnt][1]=v;
	e[cnt][2]=w;
	h[u]=cnt;
}

inline void dijstra(int s)
{
	priority_queue<PII,vector<PII>,greater<PII> >Q;
	memset(dis,0x3f3f3f,sizeof(dis));
	dis[s]=0;
	Q.push({dis[s],s});
	while(!Q.empty())
	{
		auto pos=Q.top();
		Q.pop();
		int d=pos.first,u=pos.second;
//		cout<<"XXX"<<d<<" "<<u<<'\n';
		for(int i=h[u];i;i=e[i][0])
		{
			int v=e[i][1],w=e[i][2];
//			cout<<u<<" "<<v<<" "<<w<<'\n';
			if(dis[v]>d+w)
			{
				dis[v]=d+w;
				Q.push({dis[v],v});
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>W[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int a,t;
			cin>>a>>t;
			add(500000+i,a,t);
			add(a,500000+i,t);
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		dijstra(x);
		cout<<dis[y]+W[x]+W[y]<<'\n';
	}
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
