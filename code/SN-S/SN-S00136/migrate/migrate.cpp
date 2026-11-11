#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2000003;
ll o,T,n,d,a[N],cnt=0,minn;
vector<ll>g[5003];int vis[5003];
ll ab(ll x){return x>0ll?x:-x;}
void dfs(ll u,ll ed,ll tot)
{
	if(u==ed)
	{
		if(tot>minn) return;
		else if(tot==minn) cnt++;
		else cnt=1,minn=tot;
		return;
	}
	for(int i=0;i<g[u].size();i++)
	{
		int v=g[u][i];
		if(vis[v]) continue;
		vis[v]=1;
		dfs(v,ed,tot+1);
		vis[v]=0;
	}
}
void work1()
{
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			if(i==j) continue;
			if(ab(a[i]-a[j])>d) continue;
			g[i].push_back(j);
			g[j].push_back(i);
		}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			minn=1e18;cnt=0;
			dfs(i,j,0);
			if(cnt==2)
			{
				ans++;
			}
		}
	}
	cout << ans << '\n';
}
void work2()
{
	if(d<=a[2]-a[1])
	{
		cout << 0 << '\n';
		return;
	}
	ll bl=d/(a[2]-a[1]);
	ll ans=0ll;
	for(int i=1;i<=n;i++)
		if(i+bl+bl-1<=n) ans++;
	cout << ans << '\n';
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> o >> T;
	while(T--)
	{
		cin >> n >> d;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		if(o<=10) work1();
		else if(o<=12) work2();
	}
	return 0;
}

