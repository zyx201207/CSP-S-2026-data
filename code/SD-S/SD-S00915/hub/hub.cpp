#include<bits/stdc++.h>//25
#define LL long long
using namespace std;
const LL N=1000020;
vector <LL> a[N];
LL n,k;
LL f[N],vis[N];
void DFS (LL w)
{
	vis[w]=1;
	for (auto u:a[w]) if (f[u]==1&&vis[u]==0) DFS(u);
	return;
}
LL d[N];
void dfs (LL w,LL father,LL dis)
{
	d[w]=min(d[w],dis);
	for (auto u:a[w])
	{
		if (u==father) continue;
		dfs(u,w,dis+1);
	}
	return;
}
LL ans=1e18;
void check ()
{
	LL i,j;
	if (k>2)
	{
		LL cnt=0;
		for (i=1;i<=n;i++) vis[i]=0;
		for (i=1;i<=n;i++) if (f[i]==1&&vis[i]==0) cnt++,DFS(i);
		if (cnt>2) return;
	}
	for (i=1;i<=n;i++) d[i]=1e18;
	for (i=1;i<=n;i++) if (f[i]==1) dfs(i,0,0);
	LL o=0;
	for (i=1;i<=n;i++) o=max(o,d[i]);
	ans=min(ans,o);
	return;
}
void solve (LL w,LL v)
{
	if (w==n+1)
	{
		if (v==0) check();
		return;
	}
	f[w]=0;solve(w+1,v);
	if (v!=0) f[w]=1,solve(w+1,v-1),f[w]=0;
	return;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0); 
	LL i,j;
	LL C,T;
	cin>>C>>T;
	while (T--)
	{
		cin>>n>>k;
		for (i=1;i<n;i++)
		{
			LL w1,w2;
			cin>>w1>>w2;
			a[w1].push_back(w2);
			a[w2].push_back(w1);
		}
		if (C==13||C==14)
		{
			LL m=n/2;
			if (k==n) cout<<0<<"\n";
			else if (k>=m) cout<<1<<"\n";
			else
			{
				if (k>2) m-=(k-2),k=2;
				if (k==1) cout<<m/2+1<<"\n";
				else cout<<m/4+1<<"\n";
			}
		}
		else
		{
			ans=1e18;
			solve(1,k);
			cout<<ans<<"\n";	
		}
		for (i=1;i<=n;i++) a[i].clear();
	}
	return 0;
}

