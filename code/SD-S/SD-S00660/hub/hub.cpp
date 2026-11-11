#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
const int N=1e6+10;
int C,T,n,m,op[N],st[N],now,ans,mn,usd,dep[N];
vector<int> g[N];
void dfs(int u)
{
	st[u]=1;
	for(int v: g[u])
	{
		if(st[v]||!op[v]) continue;
		dfs(v);
	}
}
void dfs1(int u,int l,int dis)
{
	if(op[u]) mn=min(mn,dis);
	for(int v: g[u])
	{
		if(v==l) continue;
		dfs1(v,u,dis+1);
	}
}
void solve1()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	ans=n;
	for(int sta=0;sta<(1<<n);sta++)
	{
		int all=0;
		for(int i=1;i<=n;i++) op[i]=sta>>(i-1)&1,all+=op[i];
		if(all!=m) continue;
		int blk=0;
		for(int i=1;i<=n;i++) st[i]=0;
		for(int i=1;i<=n;i++)
		{
			if(op[i]&&!st[i]) blk++,dfs(i);
		}
		if(blk>2) continue;
		now=0;
		for(int i=1;i<=n;i++) mn=n,dfs1(i,0,0),now=max(now,mn);
		ans=min(ans,now);
	}
	cout<<ans<<'\n';
}
PII dfs2(int u,int l,int lim)
{
	dep[u]=dep[l]+1;
	int len=0,ddep=n+1;
	for(int v: g[u])
	{
		if(v==l) continue;
		PII t=dfs2(v,u,lim);
		int ln=t.first,dp=t.second;
		if(dp==-1) len=max(len,ln+1);
		else ddep=min(ddep,dp);
	}
	if(ddep==n+1)
	{
		if(len<lim) return {len,-1};
		usd++;
		return {0,dep[u]};
	}
	if(len+ddep-dep[u]<lim) return {0,ddep};
	if(len<lim) return {len,ddep};
	usd++;
	return {0,dep[u]};
}
bool check(int x)
{
	usd=0;
	PII t=dfs2(1,0,x);
	usd+=(t.first>0);
	return usd<=m;
}
void solve2()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int l=0,r=n;
	while(l<r)
	{
		int mid=l+r>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	cout<<l<<'\n';
}
void solve3()
{
	cin>>n>>m;
	for(int i=1;i<n;i++) cin>>ans>>ans;
	if(n==m)
	{
		cout<<0<<'\n';
		return;
	}
	if(m>=n/2)
	{
		cout<<1<<'\n';
		return;
	}
	for(int i=2;i<=n;i++)
	{
		int LL=i,RR=n/2-i;
		if(RR-LL+1<=m)
		{
			cout<<i<<'\n';
			return;
		}
		int del=RR-LL+1-m;
		if((del-1)/2+2<=i)
		{
			cout<<i<<'\n';
			return;
		}
	}
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>C>>T;
	while(T--)
	{
		if(C<=3) solve1();
		else if(C>=13) solve3();
		else solve2();
	}
	return 0;
}
