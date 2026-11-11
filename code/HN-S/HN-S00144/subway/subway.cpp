#include <bits/stdc++.h>
#define int long long
#define endl '\n';
using namespace std;
const int N = 5e5;
int lll,n,m,d,k,a[N],c,w,q = N,u[N],v[N];
vector <int> g[N];
bool vis[N];
void hh(int x,int z,int l)
{
	if (z == x)
	{
		q = min(q,l);
		return ;
	}
	for (auto e : g[x])
	{
		cout << e << " ";
		if (vis[e] != true)
		{
			vis[e] = true;
			hh(e,z,l+v[e]);
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> lll >> n >> m >> d >> k;
	for (int i = 1;i <= m;i++)
	{
		cin >> a[i];
	}
	for (int i = 1;i <= n;i++)
	{
		cin >> c;
		for (int j = 1;j <= c;j++)
		{
			cin >> u[i] >> v[i];
			g[u[i]].push_back(v[i]);
			g[u[i+1]].push_back(v[i]);
		}
	}
	while (k--)
	{
		memset(vis,0,sizeof vis);
		int u,v;
		cin >> u >> v;
		w += a[u];
		w += a[v];
		q = N;
		hh(u,v,0);
		cout << q << endl;
	}
	return 0;
}
/*
0 2 5 20 2 
4 1 9 2 5 
3 1 5 2 7 4 6 
3 2 3 3 4 5 7 
1 3 
1 2
*/
