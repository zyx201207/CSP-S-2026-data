#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505;
int c,n,m,d,q,dp[N][N],dis[N*501],vis[N*501],ds[N];
struct node{
	int st,val;
	bool friend operator<(node x,node y)
	{
		return x.val>y.val;
	}
};
vector<node> ve[N*501];
void add(int u,int v,int w)
{
	ve[u].push_back({v,w});
	ve[v].push_back({u,w});
}
void Init()
{
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i) cin>>ds[i];
	for(int i=1;i<=n;++i)
	{
		int k,lst=-1;
		cin>>k;
		for(int j=1;j<=k;++j)
		{
			int a,t;
			cin>>a>>t; 
			add(501*a,i*a,t);
			if(lst!=-1) add(i*lst,i*a,0);
			lst=a;
		}
	}
}
void dij(int st)
{
	priority_queue<node> q;
	q.push({st,0});
	dis[st]=0;
	while(!q.empty())
	{
		node h=q.top();
		q.pop();
		if(vis[h.st]) continue;
		vis[h.st]=1;
		for(auto it:ve[h.st])
		{
			if(dis[it.st]>dis[h.st]+it.val)
			{
				dis[it.st]=dis[h.st]+it.val;
				q.push({it.st,dis[it.st]});
			}
		}
	}
}
void solve()
{
	for(int i=1;i<=m;++i)
	{
		memset(vis,0,sizeof(vis));
		memset(dis,0x3f,sizeof(dis));
		dij(i*501);
//		for(int j=1;j<=m;++j)
//		{
//			cout<<dis[j*501]<<" ";
//		}
//		cout<<"\n";
		for(int j=1;j<=m;++j) dp[i][j]=dis[j*501];
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	Init();
//	for(int i=1;i<=501*501;++i)
//	{
//		for(auto it:ve[i])
//		{
//			cout<<i<<" "<<it.st<<" "<<it.val<<"\n"; 
//		}
//	 } 
	solve();
	while(q--)
	{
		int u,v;
		cin>>u>>v;
		cout<<dp[u][v]+ds[u]+ds[v]<<"\n";
	}

	return 0;
}

