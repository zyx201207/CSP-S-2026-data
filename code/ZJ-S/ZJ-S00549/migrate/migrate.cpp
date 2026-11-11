#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,t,n,m,a[N],ans,dis[10005],cnt[10005];
bool vis[10005];
vector<int>g[10005];
void dij(int st)
{
	queue<int>q;
	q.push(st);
	for(int i=1;i<=2*n;i++) dis[i]=1e9,vis[i]=cnt[i]=0;
	dis[st]=0;cnt[st]=vis[st]=1;
	while(!q.empty())
	{
		int u=q.front();
//		cout<<u<<' '<<dis[u]<<' '<<cnt[u]<<'\n';
		q.pop();
		for(auto v:g[u])
		{
			if(dis[v]>=dis[u]+1) cnt[v]+=cnt[u];
			if(vis[v]) continue;
			dis[v]=dis[u]+1;
			q.push(v);
			vis[v]=1;
		}
	}
//	cout<<st<<'\n';
	for(int i=st+1;i<=n;i++)
		ans+=(cnt[i]==2);
}
void solve1()
{
	for(int i=1;i<=n;i++)
	{
		g[i].push_back(i+n);
//		cout<<i<<'\n';
		for(int j=i+1;j<=n;j++)
		{
			if(a[j]-a[i]>m) continue;
//			cout<<j<<' ';
			g[j+n].push_back(i),g[i+n].push_back(j);
		}
//		cout<<'\n';
	}
	ans=0;
	for(int i=1;i<n;i++)
		dij(i);
	cout<<ans<<'\n';
	for(int i=1;i<=n*2;i++) g[i].clear();
}
void solve2()
{
	if(n==1)
	{
		cout<<0<<"\n";
		return ;
	}
	int k=a[2]-a[1],d=(m/k);
	if(d<=1)
	{
		cout<<0<<"\n";
		return ;
	}
	int cnt1=0;
	for(int i=1;i+(d*2-1)<=n;i++)
		cnt1++;
	cout<<cnt1<<'\n';
}
void solve3()
{
	ans=0;
	for(int i=1;i<=n;i++)
	{
		int k=upper_bound(a+1,a+n+1,a[i]+m)-a;
		if(k-i==3&&k<=n) ans++;
	}
	cout<<ans<<'\n';
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(c<=10) solve1();
		else if(c>=11&&c<=12) solve2();
		else solve3();
 	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
13 2
5 3
-2 -1 0 1 2
6 2
-2 -1 0 1 2 3
*/
