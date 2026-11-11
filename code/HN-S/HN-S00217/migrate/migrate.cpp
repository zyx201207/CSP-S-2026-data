//luogu uid:795344

/*
 * last 30min:
 * 1. freopen 
 * 2. long long
 * 3. Memory check
 * 4. Time Limit
 * 5. Array bouns
 * 6. Compile
 * */
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i,l,r) for(int i=l;i<=r;++i)
#define ROF(i,r,l) for(int i=r;i>=l;--i)
#define FORK(i,l,r,k) for(int i=l;i<=r;i+=k)
#define ROFK(i,r,l,k) for(int i=r;i>=l;i-=k)
#define florrio ios::sync_with_stdio(false),cin.tie(0)
constexpr int N=2e6+5;
int a[N];
vector<int>edge[N];
int dis[N],dp[N],dfn[N],idx;
//u 到 v 的 mindist 次数(距离为 d) = u 所有一步可达的点组成的集合，设为 S，S 中所有点到 v 的次数(长度必须为 d-1，这时候设为 T)
//发现 T 一定是 S 的一段后缀
//考虑对于每个 T 记录有多少个 v 满足条件
void Init()
{
}
void Solve()
{
	int n,d,ans=0;
	cin>>n>>d;
	FOR(i,1,n)edge[i].clear();
	FOR(i,1,n)cin>>a[i];
	ROF(i,n,1)
	{
		++idx;
		int x=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
		if(x>i)edge[i].push_back(x);
		if(x-1>i)edge[i].push_back(x-1);
		if(x-2>i)edge[i].push_back(x-2);
		queue<int>q;
		q.push(i);
		dis[i]=0,dp[i]=1;dfn[i]=idx;
		while(!q.empty())
		{
			int u=q.front();q.pop();
			for(auto v:edge[u])
			{
				if(dfn[v]!=idx)
				{
					dfn[v]=idx;
					dis[v]=dis[u]+1;
					dp[v]=dp[u];
					if(dp[v]==2)++ans;
					q.push(v);
				}
				else if(dis[u]+1==dis[v])
				{
					if(dp[v]==2)--ans;
					dp[v]=min(3ll,dp[u]+dp[v]);
					if(dp[v]==2)++ans;
				}
			}
		}
	}
	cout<<ans<<'\n';
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	florrio;
	double _st=clock();
	int id,T=1;
	cin>>id>>T;
	FOR(i,1,T)
	{
		Solve();
	}
	cerr<<"used time:"<<(clock()-_st)/CLOCKS_PER_SEC<<"s\n";
	return 0;
}
