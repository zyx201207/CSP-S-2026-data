#include <bits/stdc++.h>
using namespace std;
namespace WFH{void Main();}
signed main(){return WFH::Main(),0;}
namespace WFH
{
	#define ll long long 
	inline void write(ll x)
	{
		if(x < 0) putchar('-');
		if(x > 9) write(x/10);
		putchar(x%10+'0');
		return;
	}
	inline int read()
	{
		int x = 0,f = 1;
		char ch = getchar();
		while(ch > '9' || ch < '0') {if(ch=='-')f=-f;ch=getchar();}
		while(ch >='0' && ch <='9') x=x*10+ch-'0',ch=getchar();
		return x * f;
	}
	inline void out(ll x){write(x);putchar('\n');return ;}
	const int N = 5e5+7,M = 5e2 + 7;
	const ll INF = 1e18;
	int c,n,m,d,q;
	int valsub[N];
	vector<int> t[N],f[N];
	ll dis[M][M];
	#define se second
	#define fi first
	pair<int,int> st[N];
	ll ans[N];
	void solve()
	{
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j] = INF;
		for(int i=1;i<=n;i++) dis[i][i] = 0;
		for(int i=1;i<=m;i++) 
			for(int u = 0;u<f[i].size();u++)
				for(int v = u+1;v<f[i].size();v++)
					dis[f[i][u]][f[i][v]] = min(dis[f[i][u]][f[i][v]],(ll)t[i][u]+(ll)t[i][v]),dis[f[i][v]][f[i][u]] = dis[f[i][u]][f[i][v]];
		for(int k=1;k<=n;k++)
			for(int u=1;u<=n;u++)
				for(int v=1;v<=n;v++)
					if(dis[u][v] > dis[u][k] + dis[k][v]) dis[u][v] = dis[u][k] + dis[k][v];
		//for(int i=1;i<=n;i++) {for(int j=1;j<=n;j++)printf("%lld ",dis[i][j]);putchar('\n');}
		for(int i=1;i<=q;i++) 
		{
			int u = st[i].fi,v = st[i].se;
			ans[i] = 1e18;
			for(int j=0;j<f[u].size();j++)
				for(int k=0;k<f[v].size();k++)
					ans[i] = min(ans[i],t[u][j]+t[v][k]+dis[f[u][j]][f[v][k]]);
			ans[i] += (ll)valsub[u] + (ll)valsub[v];
		}
		return ;
	}
	void Main()
	{
		freopen("subway.in","r",stdin);
		freopen("subway.out","w",stdout);
		c = read();n = read(),m = read(),d = read();q = read();
		for(int i=1;i<=m;i++) valsub[i] = read();
		for(int i=1;i<=n;i++)
		{
			int k = read();
			for(int j=1;j<=k;j++)
			{
				int tott = read(),costt = read();
				f[tott].push_back(i);
				t[tott].push_back(costt);
			}
		}
		for(int i=1;i<=q;i++) 
		{
			int u = read(),v = read();
			st[i] = make_pair(u,v);
		}
		solve();
		for(int i=1;i<=q;i++) out(ans[i]);
		return ;
	}
}
