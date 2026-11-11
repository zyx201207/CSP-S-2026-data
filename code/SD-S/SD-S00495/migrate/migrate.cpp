#include <bits/stdc++.h>

#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,l,r) for(int i=r;i>=l;i--)
#define c1(x) __builtin_popcountll(x)
#define ull unsigned long long
#define lowbit(x) x&-x
#define int long long
#define pb push_back
#define db double

using namespace std;

typedef pair<int,int> pii;
typedef pair<db,db> pdd;

const int N=2e6+10; 
int c,n,d,x[N],cnt[N],deg[N],dis[N],ans;
bool vis[N];
vector<int> g[N],ng[N]; 

void bfs(int s)
{
	rep(i,s,n) vis[i]=0,dis[i]=1e18,cnt[i]=0,deg[i]=0,ng[i].clear();
	queue<int> q;
	q.push(s);
	dis[s]=0;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(int v:g[u])
		{
			if(dis[v]!=1e18) continue;
			dis[v]=dis[u]+1;
			q.push(v);
		}
	}
	rep(i,s,n)
		for(int j:g[i]) 
			if(dis[j]==dis[i]+1)
				ng[i].pb(j),deg[j]++;
	queue<int> qq;
	cnt[s]=1;
	qq.push(s); 
	while(!qq.empty())
	{
		int u=qq.front();qq.pop();
		for(int v:ng[u])
		{
			--deg[v];
			cnt[v]+=cnt[u];
			if(!deg[v]) qq.push(v);
		}
	}
	rep(i,s,n)
		if(cnt[i]==2)
			ans++;
}

void solve()
{
	cin>>n>>d;
	ans=0;
	rep(i,1,n) cin>>x[i],g[i].clear();
	rep(i,1,n)
		rep(j,i+1,n)
			if(abs(x[j]-x[i])<=d&&i!=j)
				g[i].pb(j);
	per(i,1,n-1) bfs(i);
	cout<<ans<<"\n";
}

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	IOS
	int T;
	cin>>c>>T;
	while(T--) solve();
	return 0;
}
/*CSP-S 2026 AK RP++!
有没有写freopen?
数组是否开够？
有没有爆空间？
有没有交错代码？
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/

