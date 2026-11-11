#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=5e5+10,N=5e2+10,inf=1e18;
int ccc,n,m,d,q;
int k[N],cst[M],top[M];
int eg[N][N];
struct Edge{int u,w;};
Edge tj[M][21];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	memset(eg,0x3f,sizeof(eg));
	cin>>ccc>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)
		eg[i][i]=0;
	for(int i=1;i<=m;i++)
		cin>>cst[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1,u,ww;j<=k[i];j++)
		{
			cin>>u>>ww;
			tj[u][++top[u]]={i,ww};
		}
	}
	 for(int i=1;i<=m;i++)
	 {
	 	int sz=top[i];
	 	for(int j=1;j<=sz;j++)
	 	{
	 		for(int l=j+1;l<=sz;l++)
	 		{
	 			int u=tj[i][j].u,w1=tj[i][j].w;
	 			int v=tj[i][l].u,w2=tj[i][l].w;
	 			int tmpw=w1+w2;
	 			eg[u][v]=min(eg[u][v],tmpw);
	 			eg[v][u]=min(eg[v][u],tmpw);
	 		}
	 	}
	 }
	for(int l=1;l<=n;l++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				eg[i][j]=min(eg[i][j],eg[i][l]+eg[l][j]);
	int x,y;
	while(q--)
	{
		cin>>x>>y;
		int ans=inf;
		for(auto i:tj[x])
		{
			for(auto j:tj[y])
			{
				int u=i.u,v=j.u;
				int w1=i.w,w2=j.w;
				int sum=eg[u][v]+cst[x]+cst[y]+w1+w2;
				ans=min(ans,sum);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}