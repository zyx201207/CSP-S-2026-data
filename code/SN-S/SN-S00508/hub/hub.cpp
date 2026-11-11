//by : xt66666
//lihaoyang
//TYZ
//SN-S00508
//luogu uid : 去年就忘了，今年还是没记住

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define mid ((l+r)>>1)
#define lc t[p].ls
#define rc t[p].rs
#define pb push_back
#define fir first
#define sec second
ll n,k;
ll Test;
ll tot,to[2000010],nt[2000010],hd[2000010];
void add(ll x,ll y)
{
	to[++tot]=y;
	nt[tot]=hd[x];
	hd[x]=tot;
}
void solve13()
{
	cin>>n>>k;//for(int i=1;i<=n;i++)g[i].clear();
	for(int i=1;i<=tot;i++)nt[i]=hd[i]=to[i]=0;
	for(int i=1;i<=n;i++)hd[i]=0;
	for(int i=1;i<n;i++)
	{
		ll x,y;cin>>x>>y;
		add(x,y);add(y,x);
	}
	ll mx=n/2+2;
//	cout
	ll x=(mx-k)/4;
	if((mx-k)%4)x++;
	cout<<x<<endl;
}
ll st=0;
ll ste[1010][1010];
void dfs1(ll x,ll fa)
{
//	ste[st][x]=ste[st][fa]+1;
	for(int i=hd[x];i;i=nt[i])
	{
		ll y=to[i];
		if(y==fa)continue;
		ste[st][y]=ste[st][x]+1;
		dfs1(y,x);
	}
}
ll fa[1010];
ll find(ll x)
{
	if(fa[x]==x)return x;
	else return fa[x]=find(fa[x]);
}
bool vis[1010];
bool v[1010];
ll a[1010];
ll ans=1e18;
void dfs(ll x)
{
	if(x==k+1)
	{
		for(int i=1;i<=n;i++)fa[i]=i;
	
		for(int x=1;x<=n;x++)
		{
			if(vis[x])
			{
				for(int i=hd[x];i;i=nt[i])
				{
					ll y=to[i];
					if(vis[y])fa[find(y)]=find(x);
				}
			}
		}
		ll now=0;
		for(int i=1;i<=k;i++)v[a[i]]=0;
		for(int i=1;i<=n;i++)
		{
			if(!vis[i])continue;
			if(!v[find(i)])now++;
			v[find(i)]=1;
		}
		if(now>2)return;
		now=0;
		for(int i=1;i<=n;i++)
		{
			ll ret=1e18;
			for(int j=1;j<=k;j++)ret=min(ret,ste[i][a[j]]);
			now=max(now,ret);
		}
		ans=min(ans,now);
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			a[x]=i;
			vis[i]=1;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
/*
0 2
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
void solve()
{
	ans=1e18;
	cin>>n>>k;//for(int i=1;i<=n;i++)g[i].clear();
	for(int i=1;i<=tot;i++)nt[i]=hd[i]=to[i]=0;
	for(int i=1;i<=n;i++)hd[i]=0;
	for(int i=1;i<n;i++)
	{
		ll x,y;cin>>x>>y;
		add(x,y);add(y,x);
	}
	for(st=1;st<=n;st++)dfs1(st,0);
//	for(int i=1;i<=n;i++,cout<<endl)for(int j=1;j<=n;j++)cout<<ste[i][j]<<' ';
	dfs(1);
	cout<<ans<<endl;	
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll T=1;
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>Test>>T;
	if(Test==13||Test==14)while(T--)solve13();
	else while(T--)solve();
	return 0;
}

