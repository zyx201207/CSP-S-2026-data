#include<bits/stdc++.h>
#define cs const
//#define int long long
#define fore(x,m,n) for(int x=m;x<=n;x++)
using namespace std;

using ll=long long;
int c,n,m,d,q;
cs int N=505,M=5e5+5;cs ll inf=1e18;
ll w[M];
vector<int> pts[M],tim[M];
ll dis[N][N];

signed main()
{
#ifndef Debug
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
#else
	freopen("subway7.in","r",stdin);
//	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	fore(i,1,m) cin>>w[i];
	fore(i,1,n)
	{
		int k;cin>>k;
		fore(j,1,k)
		{
			int u,x;cin>>u>>x;
			pts[u].push_back(i);
			tim[u].push_back(x);
		}
	}
	fore(i,1,n) fore(j,1,n) dis[i][j]=inf;
	fore(i,1,n) dis[i][i]=0;
	fore(i,1,m) if(pts[i].size()>=2)
	{
		fore(j,0,(int)pts[i].size()-1) fore(k,j+1,(int)pts[i].size()-1)
		{
			int u=pts[i][j],v=pts[i][k];
			dis[u][v]=min(dis[u][v],(ll)tim[i][j]+tim[i][k]);
			dis[v][u]=min(dis[v][u],(ll)tim[i][j]+tim[i][k]);
		}
	}
	fore(k,1,n)
	{
		fore(i,1,n) if(i!=k)
		{
			fore(j,1,n) if(j!=k&&j!=i)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	fore(i,1,q)
	{
		int x,y;cin>>x>>y;
		ll ans=inf;
		fore(i,0,(int)pts[x].size()-1) fore(j,0,(int)pts[y].size()-1)
		{
			int u=pts[x][i],v=pts[y][j];
			ans=min(ans,tim[x][i]+dis[u][v]+tim[y][j]);
		}
		cout<<w[x]+ans+w[y]<<'\n';
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

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

fin:15:11
by:luckyWu

exp:100
*/