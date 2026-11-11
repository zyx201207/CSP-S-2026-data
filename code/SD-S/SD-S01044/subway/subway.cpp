#include<bits/stdc++.h>
using namespace std;

inline int read();

const int N=210,M=410;

int csd,n,m,d,q,w[N],t[N][M];
vector<int>xian[N];
int idx=0,head[M*M];struct edge
{
	int v,nt;
	long long w;
}e[M*M<<2];inline void add(int u,int v,long long w){e[++idx]={v,head[u],w};head[u]=idx;return ;}
long long dis[N*M];
bool vis[M*M];
bool viss[N][M];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	csd=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;++i)
	{
		w[i]=read();
	}
	for(int i=1;i<=n;++i)
	{
		int k=read();
		int st=read();
		xian[st].push_back(i);
		t[i][st]=read();	
		viss[i][st]=1;
		for(int j=2;j<=k;++j)
		{
			int A=read(),T=read();
			xian[A].push_back(i);
			viss[i][A]=1;
			add(st+(i-1)*(m+1),A+(i-1)*(m+1),0);
			add(A+(i-1)*(m+1),st+(i-1)*(m+1),0);
			st=A;
			t[i][A]=T;
		}
	}
	for(int i=1;i<=m;++i)
	{
		for(int j=0;j<xian[i].size();++j)
		{
			for(int k=0;k<xian[i].size();++k)
			{
				if(j!=k)
				{
					add(i+(xian[i][j]-1)*(m+1),i+(xian[i][k]-1)*(m+1),t[xian[i][j]][i]+t[xian[i][k]][i]);
				}
			}
		}
	}
//	for(int i=1;i<=m*(m+1);++i)
//	{
//		cout<<i<<"->\n";
//		for(int j=head[i];j;j=e[j].nt)
//		{
//			int v=e[j].v;
//			long long w=e[j].w;
//			cout<<v<<" "<<w<<"\n";
//		}
//	}
	while(q--)
	{
		int x=read(),y=read();
		long long ans=0x3f3f3f3f3f3f3f3f;
		for(int i=1;i<=n;++i)
		{
			if(!viss[i][x])
			{
				continue;
			}
			for(int j=1;j<=n;++j)
			{
				for(int k=1;k<=m;++k)
				{
					dis[k+(j-1)*(m+1)]=0x3f3f3f3f3f3f3f3f;
					vis[k+(j-1)*(m+1)]=0;
				}
			}
			dis[x+(i-1)*(m+1)]=0;
			priority_queue<pair<long long,int> >q;
			q.push({0,x+(i-1)*(m+1)});
			while(!q.empty())
			{
				long long k=-q.top().first;
				int u=q.top().second;
				q.pop();
				if(vis[u])
				{
					continue;
				}
				vis[u]=1;
				for(int j=head[u];j;j=e[j].nt)
				{
					int v=e[j].v;
					long long w=e[j].w;
//					cout<<u<<" "<<v<<" "<<w<<"\n"; 
					if(dis[v]>k+w)
					{
						dis[v]=k+w;
						q.push({-dis[v],v});
					}
				}
			}
			for(int j=1;j<=n;++j)
			{
				if(!viss[j][y])
				{
					continue;
				}
				ans=min(ans,t[i][x]+t[j][y]+dis[y+(j-1)*(m+1)]);
//				cout<<i<<" "<<j<<" "<<y+(j-1)*(m+1)<<" "<<t[i][x]<<" "<<t[j][y]<<" "<<dis[y+(j-1)*(m+1)]<<"\n";
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}

inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')
		{
			f=-1;
		}
		c=getchar();
	}
	while(isdigit(c))
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}

