#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500010];
struct subst
{
	int id,t; 
};
vector<subst> G[500010];
int dis[510][510];
#define int int
int main()
{
#define int long long
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	memset(dis,0x3f,sizeof dis);
	int c,n,m,d,q;
	cin >>c >>n >>m >> d >> q;
	for (int i = 1;i <= m;i++)
		cin >>a[i];
	for (int i = 1;i <= n;i++)
	{
		int k;
		cin >> k;
		while(k--)
		{
			int x,y;
			cin >>x >>y;
			G[x].push_back({i,y});
		}
	}
	for (int i = 1;i <= m;i++)
		if(G[i].size())
			for (auto x : G[i])
				for (auto y : G[i])
					if(x.id != y.id)
					{
						dis[x.id][y.id] = min(dis[x.id][y.id],x.t + y.t),dis[y.id][x.id] = min(dis[y.id][x.id],x.t + y.t);
						//cout << dis[x.id][y.id] << endl; 
					}
	for (int i = 1;i <= n;i++)
		dis[i][i] = 0;
	for (int k = 1;k <= n;k++)
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= n;j++)
				dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
	while(q--)
	{
		int x,y;
		cin >>x >>y;
		int ans = 1e18;
		for (auto i : G[x])
			for (auto j : G[y])
				ans = min(ans,dis[i.id][j.id] + i.t + j.t);
		cout << a[x] + ans + a[y] << endl;
	}
	return 0;
} 
