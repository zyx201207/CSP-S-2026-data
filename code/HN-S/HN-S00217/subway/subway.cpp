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
constexpr int N=505,M=5e5+5;
constexpr int inf=0x3f3f3f3f3f3f3f3f;
int omegaufo,n,m,d,q;
int a[M];
vector<pair<int,int> >edge[M];
int dp[N][N];
void Init()
{
}
void Solve()
{
	memset(dp,0x3f,sizeof dp);
	cin>>omegaufo>>n>>m>>d>>q;
	FOR(i,1,m)cin>>a[i];
	FOR(i,1,n)
	{
		dp[i][i]=0;
		int k;
		cin>>k;
		FOR(j,1,k)
		{
			int x,w;
			cin>>x>>w;
			edge[x].emplace_back(i,w);//第x个地铁站所连接的线路
		}
	}
	FOR(i,1,m)for(auto E1:edge[i])for(auto E2:edge[i])
	{
		int u=E1.first,w1=E1.second,v=E2.first,w2=E2.second;
		dp[u][v]=min(dp[u][v],w1+w2);
	}
	FOR(k,1,n)FOR(i,1,n)if(dp[i][k]!=inf)FOR(j,1,n)dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		int ans=inf;
		for(auto E1:edge[x])for(auto E2:edge[y])
		{
			int u=E1.first,w1=E1.second,v=E2.first,w2=E2.second;
			ans=min(ans,a[x]+a[y]+w1+w2+dp[u][v]);
		}
		cout<<ans<<'\n';
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	florrio;
	double _st=clock();
	int T=1;
	//cin>>T;
	FOR(i,1,T)
	{
		Solve();
	}
	cerr<<"used time:"<<(clock()-_st)/CLOCKS_PER_SEC<<"s\n";
	return 0;
}
//这么水？？30min切T2的来了
