
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
constexpr int N=5005;
int p[N],dis[N];
vector<int>edge[N];
int id,T=1;
mt19937 rng(time(0));
int rnd(int l,int r)
{
	int x=rng();
	x=(x%(r-l+1)+(r-l+1))%(r-l+1)+l;
	return x;
}
bool vis[N];
void dfs(int u)
{
	if(vis[u])return ;
	vis[u]=1;
	for(auto v:edge[u])if(dis[v]==0)dfs(v);
}
void Init()
{
}
void Solve()
{
	int n,K;
	cin>>n>>K;
	FOR(i,1,n)edge[i].clear();
	FOR(i,1,n-1)
	{
		int u,v;
		cin>>u>>v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	if(n==K)
	{
		cout<<"0\n";
		return ;
	}
	FOR(i,1,n)p[i]=i;
	int ans=n+1;
	double nowt=clock();
	do
	{
		if((clock()-nowt)*2>=CLOCKS_PER_SEC)break;
		int now=0;
		queue<int>q;
		FOR(i,1,n)dis[i]=-1;
		FOR(i,1,K)q.push(p[i]),dis[p[i]]=0,vis[p[i]]=0;
		int cnt=0;
		FOR(i,1,K)if(!vis[p[i]])
		{
			dfs(p[i]);
			++cnt;
		}
		if(cnt>2)continue;
		while(!q.empty())
		{
			int u=q.front();q.pop();
			now=max(now,dis[u]);
			for(auto v:edge[u])if(dis[v]==-1)
			{
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
		ans=min(ans,now);
	}while(next_permutation(p+1,p+n+1));
	cout<<ans<<'\n';
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	//	freopen("hub.in","r",stdin);
	//freopen("hub.out","w",stdout);
	florrio;
	double _st=clock();
	cin>>id>>T;
	FOR(i,1,T)
	{
		Solve();
	}
	cerr<<"used time:"<<(clock()-_st)/CLOCKS_PER_SEC<<"s\n";
	return 0;
}
