#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=505,M=500005,Q=100005;
const ll inf=1e18;
ll c[N];
struct no{
	int v;
	ll w;
}p;
struct note{
	int u;
	ll dis;
	bool operator < (const note b) const{
		return dis>b.dis;
	}
}pp;
int n,m,U[Q],V[Q];
vector<no>b[N],h[M];
ll dis[N+M],edge[M][2];
priority_queue<note>q;
ll dijkstra(int id)
{
	while(q.size())
	{
		q.pop();
	}
	ll d,w;
	int i,s,v,u,st=U[id],end=V[id];
	for(i=1;i<=n+m;i++)
	{
		dis[i]=inf;
	}
	dis[st]=0;
	pp.u=st;
	pp.dis=0;
	q.push(pp);
	while(q.size())
	{
		pp=q.top();
		q.pop();
		u=pp.u;
		d=pp.dis;
		if(d!=dis[u])
			continue;
		if(u==end)
		{
			return d;
		}
		if(u<=m)
		{
			s=h[u].size();
			for(i=0;i<s;i++)
			{
				v=h[u][i].v+m;
				w=h[u][i].w;
				if(dis[v]>d+w)
				{
					dis[v]=d+w;
					pp.u=v;
					pp.dis=dis[v];
					q.push(pp);
				}
			}
		}
		else
		{
			u-=m;
			s=b[u][0].v;
			for(i=1;i<=s;i++)
			{
				v=b[u][i].v;
				w=b[u][i].w;
				if(dis[v]>d+w)
				{
					dis[v]=d+w;
					pp.u=v;
					pp.dis=dis[v];
					q.push(pp);
				}
			}
		}
	}
}
inline void add(int u,int v,ll w)
{
	p.v=v;
	p.w=w;
	h[u].push_back(p);
}
ll D[1005][1005];
ll f(int id)
{
	while(q.size())
	{
		q.pop();
	}
	ll d,w;
	int i,s,v,u,st=U[id],end=V[id];
	if(D[st][end])
	{
		return D[st][end];
	}
	else if(D[end][st])
	{
		return D[end][st];
	}
	for(i=1;i<=m;i++)
	{
		dis[i]=inf;
	}
	dis[st]=0;
	pp.u=st;
	pp.dis=0;
	q.push(pp);
	while(q.size())
	{
		pp=q.top();
		q.pop();
		u=pp.u;
		d=pp.dis;
		if(d!=dis[u])
			continue;
		D[st][u]=D[u][st]=d;
		if(u==end)
		{
			return d;
		}
		s=h[u].size();
		for(i=0;i<s;i++)
		{
			v=h[u][i].v;
			w=h[u][i].w;
			if(dis[v]>d+w)
			{
				dis[v]=d+w;
				pp.u=v;
				pp.dis=dis[v];
				q.push(pp);
				if(D[v][end])
				{
					pp.u=end;
					pp.dis=D[v][end]+dis[v];
					q.push(pp);
				}
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ll ans,w,minn;
	int T,i,j,st,end,d,q,v,k;
	scanf("%d%d%d%d%d",&T,&n,&m,&d,&q);
	for(i=1;i<=m;i++)
	{
		scanf("%lld",&c[i]);
	}
	if(T>=1||T==0)
	{
		if(T>=1&&T<=6||T==0)
		{
			for(i=1;i<=n;i++)
			{
				scanf("%d",&k);
				p.v=k;
				p.w=0;
				b[i].push_back(p);
				for(j=1;j<=k;j++)
				{
					scanf("%d%lld",&v,&w);
					p.v=v;
					p.w=w;
					b[i].push_back(p);
					p.v=i;
					h[v].push_back(p);
				}
			}
			for(i=1;i<=q;i++)
			{
				scanf("%d%d",&U[i],&V[i]);
			}
			for(i=1;i<=q;i++)
			{
				printf("%lld\n",dijkstra(i)+c[U[i]]+c[V[i]]);
			}
		}
//		else if(T>=9&&T<=11)
//		{
//			int u[2];
//			ll ww[2];
//			for(i=1;i<=n;i++)
//			{
//				scanf("%d",&k);
//				for(j=1;j<=k;j++)
//				{
//					scanf("%d%lld",&u[j-1],&ww[j-1]);
//				}
//				if(k==1)
//					continue;
//				w=ww[0]+ww[1];
//				add(u[0],u[1],w);
//				add(u[1],u[0],w);
//			}
//			for(i=1;i<=q;i++)
//			{
//				scanf("%d%d",&U[i],&V[i]);
//			}
//			for(i=1;i<=q;i++)
//			{
//				printf("%lld\n",f(i)+c[U[i]]+c[V[i]]);
//			}
//		}
		else if(T>=7&&T<=11||T==0)
		{
			int u[2];
			ll ww[2];
			for(i=1;i<=m;i++)
			{
				for(j=1;j<=m;j++)
				{
					D[i][j]=inf;
				}
				D[i][i]=0;
			}
			for(i=1;i<=n;i++)
			{
				scanf("%d",&k);
				for(j=1;j<=k;j++)
				{
					scanf("%d%lld",&u[j-1],&ww[j-1]);
				}
				if(k==1)
					continue;
				w=ww[0]+ww[1];
				D[u[0]][u[1]]=D[u[1]][u[0]]=w;
			}
			for(i=1;i<=m;i++)
			{
				for(j=1;j<=m;j++)
				{
					for(k=1;k<=m;k++)
					{
						D[i][j]=min(D[i][j],D[i][k]+D[k][j]);
					}
				}
			}
			for(i=1;i<=q;i++)
			{
				printf("%lld",D[U[i]][V[i]]+c[U[i]]+c[V[i]]);
			}
		}
		else if(T>=20&&T<=21)
		{
			for(i=1;i<=n;i++)
			{
				scanf("%d",&k);
				for(j=1;j<=k;j++)
				{
					scanf("%d%lld",&v,&w);
					edge[v][i-1]=w;
				}
			}
			for(i=1;i<=q;i++)
			{
				scanf("%d%d",&U[i],&V[i]);
			}
			minn=inf;
			for(i=1;i<=m;i++)
			{
				if(edge[i][0]&&edge[i][1])
				{
					minn=min(minn,edge[i][0]+edge[i][1]);
				}
			}
			for(i=1;i<=q;i++)
			{
				st=U[i];
				end=V[i];
				ans=inf;
				if(edge[st][0]&&edge[end][0])
				{
					ans=min(ans,edge[st][0]+edge[end][0]);
				}
				if(edge[st][0]&&edge[end][1])
				{
					ans=min(ans,edge[st][0]+edge[end][1]+minn);
				}
				if(edge[st][1]&&edge[end][0])
				{
					ans=min(ans,edge[st][1]+edge[end][0]+minn);
				}
				if(edge[st][1]&&edge[end][1])
				{
					ans=min(ans,edge[st][1]+edge[end][1]);
				}
				printf("%lld\n",ans+c[U[i]]+c[V[i]]);
			}
		}
		else
		{
			for(i=1;i<=n;i++)
			{
				scanf("%d",&k);
				p.v=k;
				p.w=0;
				b[i].push_back(p);
				for(j=1;j<=k;j++)
				{
					scanf("%d%lld",&v,&w);
					p.v=v;
					p.w=w;
					b[i].push_back(p);
					p.v=i;
					h[v].push_back(p);
				}
			}
			for(i=1;i<=q;i++)
			{
				scanf("%d%d",&U[i],&V[i]);
			}
			for(i=1;i<=q;i++)
			{
				printf("%lld\n",dijkstra(i)+c[U[i]]+c[V[i]]);
			}
		}
	}
	return 0;
}
