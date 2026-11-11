#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define fir first
#define sec second
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define DEP(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define pb push_back
void Ios(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
const int maxn=3010;
vector<int> g[maxn];
int popc[100005];
bool st[maxn],ap[maxn];
int f[maxn];
int find(int x)
{
	if(x==f[x]) return x;
	return f[x]=find(f[x]);
}
int dis[maxn][maxn];
void dfs(int d,int x,int f,int dep)
{
	dis[d][x]=dep;
	for(auto it:g[x])
	if(it!=f) dfs(d,it,x,dep+1);
}
int c;
void solve()
{
	int n,k;
	cin>>n>>k;
	REP(i,1,n) g[i].clear();
	REP(i,1,n-1)
	{
		int u,v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	int ans=1e18;
	REP(i,1,n)
	dfs(i,i,0,0);
//	if(c==7)
//	{
//		if(k==1)
//		{
//			REP(i,1,n)
//			{
//				int mx=0;
//				REP(j,1,n)
//				if(j!=i) mx=max(mx,dis[i][j]);
//				ans=min(ans,mx);
//			}
//			cout<<ans<<"\n";
//			return;
//		}
//		else
//		{
//			REP(i,1,n)
//			REP(j,1,n)
//			{
//				
//			}
//		}
//	}
	REP(sta,0,(1<<n)-1)
	if(popc[sta]==k)
	{
		REP(j,1,n) st[j]=0,f[j]=j,ap[j]=0;
		REP(j,0,n-1)
		if((sta>>j)&1)
		st[j+1]=1;
		REP(i,1,n)
		if(st[i])
		for(auto it:g[i])
		if(st[it])
		f[find(i)]=find(it);
		int kuai=0;
		REP(i,1,n)
		if(st[i])
		{
			int fa=find(i);
			if(ap[fa]) continue;
			ap[fa]=1;
			kuai++;
		}
		if(kuai>2) continue;
		int mx=0;
		REP(i,1,n)
		if(!st[i])
		{
			int mn=1e18;
			REP(j,1,n)
			if(st[j]) mn=min(mn,dis[i][j]);
			mx=max(mx,mn);
		}
		ans=min(ans,mx);
	}
	cout<<ans<<"\n";
}
signed main()
{
	REP(i,1,10000) popc[i]=popc[i/2]+(i&1);
	Ios();
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int t;
	cin>>c>>t;
	while(t--) solve();
	return 0;
}