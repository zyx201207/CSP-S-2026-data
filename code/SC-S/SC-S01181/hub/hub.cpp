#include <bits/stdc++.h>
#define ll long long
using namespace std;
namespace sub1
{
	const int maxn = 1e3+5;
	int n , m , fa[maxn] , cntfa[maxn] , f[maxn][maxn] , ans;
	vector<int>g[maxn];
	bool mkd[maxn];
	int Find(int x){return fa[x]=x==fa[x]?x:Find(fa[x]);}
	void Merge(int x , int y){fa[Find(x)]=Find(y);}
	bool check()
	{
		for (int i = 1; i <= n; i++)fa[i]=i,cntfa[i]=0;
		for (int i = 1; i <= n; i++)
		{
			if (mkd[i])
			{
				for (auto v : g[i]) if (mkd[v])Merge(v , i);
			}
		}
		for (int i = 1; i <= n; i++)if(mkd[i])cntfa[Find(i)]++;
		int tmp = 0;
		for (int i = 1; i <= n; i++) if (cntfa[i]>=1)tmp++;
		return tmp <= 2;
	}
	void mark(int now , int cnt)
	{
		if (cnt == m)
		{
			if (check())
			{

				int now = 0;
				for (int i = 1; i <= n; i++)
				{
//					cout << mkd[i] << " ";
					if (mkd[i])continue;
					int now2 = 1e9+5;
					for (int j = 1; j <= n; j++)
					{
						if (mkd[j])now2=min(now2,f[i][j]);
					}
					now=max(now2 , now);
				}
				ans=min(ans,now);
//				cout << endl;
			}

			return;
		}
		if (now > n)return;
		mkd[now]=1;
		mark(now + 1 , cnt + 1);
		mkd[now]=0;
		mark(now + 1 , cnt);
		return;
	}
	void Solve()
	{

		cin >> n >> m;
		ans=1e9+5;
		for (int i = 1; i <= n; i++)for (int j = 1; j <= n; j++)f[i][j]=1e9+5;
		for (int i = 1; i <= n; i++)g[i].clear(),f[i][i]=0;
		for (int i = 1; i < n; i++)
		{
			int u , v;
			cin >>  u >> v;
			g[u].push_back(v),g[v].push_back(u);
			f[u][v]=f[v][u]=1;
		}
		if (m == n){cout << 0 << "\n";return;}
		for (int i = 1; i <= n; i++)
		{
			for (int k = 1; k <= n; k++)
			{
				if (i == k)continue;
				for (int j = 1; j <= n; j++)
				{
					f[i][j]=min(f[i][j] , f[i][k]+f[k][j]);
				}
			}
		}
		mark(1 , 0);
		cout << ans << "\n";
		return;
	}
};
namespace sub2
{
	const int maxn = 1e6+5;
	int n , m , fa[maxn] , cntfa[maxn] , f[maxn] , ans;
	vector<int>g[maxn];
	void Solve()
	{
		cin >> n >> m;
		ans=1e9+5;
		for (int i = 1; i <= n; i++)g[i].clear();
		for (int i = 1; i < n; i++)
		{
			int u , v;
			cin >>  u >> v;
			g[u].push_back(v),g[v].push_back(u);
		}
		if (m == n){cout << 0 << "\n";return;}
		if (m % 2 == 0)
		{
			int tmp = n >> 2;
			int t = m>>1;
			if (t >= tmp)ans=1;
			else ans = (tmp - t + 1);
		}
		else
		{
			m--;
			int tmp = n >> 2;
			int t = m>>1;
//			cout << tmp << " " << t << endl;
			if (t >= tmp)ans=1;
			else ans = (tmp - t + 1);
		}
		cout << ans << "\n";
	}
};
signed main()
{
	freopen("hub.in" , "r" , stdin);
	freopen("hub.out" , "w" , stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int c , t;
	cin >> c >> t;
	while(t--)
	{
		if (c != 13 && c != 14)sub1::Solve();
		else sub2::Solve();
	}
	return 0;
}

/*
13 1
9 3
1 2
2 3
3 4
4 5
1 6
2 7
3 8
4 9

*/