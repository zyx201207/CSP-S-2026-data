#include<bits/stdc++.h>
#define i128 __int128
#define ll long long
#define Pii pair<int,int>
#define fi first
#define se second

using namespace std;
const int N=1e6+10;

int n,k,ans,rtu,rtv,dep[N],dp[N]; Pii e[N];
vector<int> vt[N],t[N],zh[3];

inline bool cr(int a,int b)
{
	return !((a==rtu&&b==rtv)||(a==rtv&&b==rtu));
}

inline void dfs1(int x,int f)
{
	dep[x]=0;
	for(auto a:vt[x])
		if(a!=f&&cr(x,a))
			dfs1(a,x),dep[x]=max(dep[x],dep[a]+1);
}

inline int dfs2(int x,int f,int v)
{
	dp[x]=max(dep[x],v); int v1=-1e9,v2=-1e9,nw=0,qwq=dp[x];
	for(auto a:vt[x])
		if(a!=f&&cr(x,a))
		{
			if(dep[a]>v1) v2=v1,v1=dep[a],nw=a;
			else if(dep[a]>v2) v2=dep[a];
		}
	for(auto a:vt[x])
		if(a!=f&&cr(x,a))
			qwq=min(qwq,dfs2(a,x,max(v,(a==nw?v2:v1)+1)+1));
	return qwq;
}

inline void dfs3(int x,int f,int v,int op)
{
	if(dp[x]==v) zh[op].push_back(x);
	for(auto a:vt[x])
		if(a!=f&&cr(x,a)) dfs3(a,x,v,op);
}

inline int ge(int res)
{
	int v=k;
	while(1)
	{
		while(v&&(!t[res].empty()))
		{
			int x=t[res].back(); t[res].pop_back(); --v;
			for(auto a:vt[x])
				if(dep[a]<dep[x]&&cr(x,a))
					t[dep[a]].push_back(a);
		}
		if(t[res].empty()) --res;
		if(!v) return res;
	}
}

inline void solve(int u,int v)
{
	rtu=u; rtv=v; zh[0].clear(); zh[1].clear(); int nw;
	for(int j=1;j<=n;++j) t[j].clear();
	dfs1(u,0); nw=dfs2(u,0,0); dfs3(u,0,nw,0);
	dfs1(v,0); nw=dfs2(v,0,0); dfs3(v,0,nw,1);
	for(auto a:zh[0])
		for(auto b:zh[1])
		{
			dfs1(a,0); dfs1(b,0);
			t[dep[a]].push_back(a);
			t[dep[b]].push_back(b);
			ans=min(ans,ge(max(dep[a],dep[b])));
		}
}

inline void dfs(int x,int f,int v)
{
	if(v>4) return;
	for(auto a:vt[x])
		if(a!=f) solve(x,a),dfs(a,x,v+1);
}

inline void solve()
{
	cin>>n>>k; ans=1e9; int u,v;
	for(int i=1;i<=n;++i) vt[i].clear();
	for(int i=1;i<n;++i)
	{
		cin>>u>>v; e[i]={u,v};
		vt[u].push_back(v);
		vt[v].push_back(u);
	}
	if(n==k) {cout<<"0\n"; return;}
	if(n>4000)
	{
		rtu=rtv=0; dfs1(1,0); int nw=dfs2(1,0,0);
		zh[2].clear(); dfs3(1,0,nw,2);
		for(auto a:zh[2]) dfs(a,0,0);
	}
	else for(int i=1;i<n;++i) solve(e[i].fi,e[i].se);
	cout<<ans+1<<"\n";
}

signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int c,t; cin>>c>>t;
	while(t--) solve();
	return 0;
}