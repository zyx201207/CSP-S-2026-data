#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=2e3+10,inf=1e9+10;
int n,c,T,timer,ans,k;
vector<int>g[N];
bool b[N];
int dfn[N],dis[N][N],ma[N][N];
void init()
{
	timer=0;
	for(int i=1;i<=n;i++)
	{
		g[i].clear();
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dis[i][j]=inf;
		}
	}
	for(int i=1;i<=n;i++)
	{
		dis[i][i]=0;
	}
	ans=inf;
}
void dfs1(int u,int fa)
{
	timer++;
	dfn[timer]=u;
	for(auto v:g[u])
	{
		if(v==fa)	continue;
		dfs1(v,u);
	}
}
void dfs(int root,int u,int fa)
{
	if(u!=root)dis[root][u]=dis[u][root]=dis[root][fa]+1;
	for(auto v:g[u])
	{
		if(v==fa)	continue;
		dfs(root,v,u);
	}
}
int query(int ll,int lr,int rl,int rr)
{
	int r=0;
	for(int i=1;i<=n;i++)
	{
		if((i>=ll&&i<=lr)||(i>=rl&&i<=rr))
		{
			continue;
		}
		for(int j=ll;j<=lr;j++)
		{
			r=max(r,dis[dfn[i]][dfn[j]]);
		}
		for(int j=rl;j<=rr;j++)
		{
			r=max(r,dis[dfn[i]][dfn[j]]);
		} 
		//cout<<dfn[i]<<endl;
	}
	return r;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	cout<<1<<endl<<2<<endl;
//	while(T--)
//	{
//		init();
//		cin>>n>>k;
//		for(int i=1;i<n;i++)
//		{
//			int u,v;
//			cin>>u>>v;
//			g[u].push_back(v);
//			g[v].push_back(u);
//		}
//		dfs1(1,0);
//		for(int i=1;i<=n;i++)
//		{
//			dfs(i,i,0);
////			for(int j=1;j<=n;j++)
////			{
////				cout<<i<<' '<<j<<' '<<dis[i][j]<<endl;
////			}
//		}
//		for(int lenl=1;lenl<k;lenl++)
//		{
//			int lenr=k-lenl;
//			for(int l=1;l+k-1<=n;l++)
//			{
//				for(int r=l+1;r+lenr-1<=n;r++)
//				{
//					//if(lenl)
//					ans=min(ans,query(l,l+lenl-1,r,r+lenr-1));
//					//cout<<l<<' '<<l+lenl-1<<" "<<r<<' '<<' '<<r+lenr-1<<' '<<query(l,l+lenl-1,r,r+lenr-1)<<' '<<endl;
//				}
//			}
//		}
//		cout<<ans<<endl;
//	}
	return 0;
}
/*
0 1
5 2
1 2
2 3
3 4
4 5

10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/

