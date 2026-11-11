#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 505,maxm = 5e5+5,inf = 1e18;
struct node
{
	int id,t;
};
int w[maxm],a[maxm];
int G[maxn][maxn];
vector<node> s[maxm];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int c,n,m,d,q,mx = 0;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= n;j++)
		{
			if (i == j) continue;
			G[i][j] = inf;
		}
	}
	for (int i = 1;i <= m;i++)
	{
		cin >> w[i];
	}
	for (int i = 1;i <= n;i++)
	{
		int k,t;
		cin >> k;
		for (int j = 1;j <= k;j++)
		{
			cin >> a[j] >> t;
			s[a[j]].push_back(node{i,t});
		}
	}
	for (int i = 1;i <= m;i++)
	{
		for (int j = 1;j < s[i].size();j++)
		{
			int id1 = s[i][j-1].id,t1 = s[i][j-1].t,id2 = s[i][j].id,t2 = s[i][j].t;
			G[id1][id2] = min(G[id1][id2],0ll+t1+t2);
			G[id2][id1] = min(G[id2][id1],0ll+t1+t2);
		}
	}
	for (int k = 1;k <= n;k++)
	{
		for (int i = 1;i <= n;i++)
		{
			for (int j = 1;j <= n;j++)
			{
				G[i][j] = min(G[i][j],G[i][k]+G[k][j]);
			}
		}
	}
	int x,y;
	while (q--)
	{
		cin >> x >> y;
		int ans = inf;
		for (int i = 0;i < s[x].size();i++)
		{
			for (int j = 0;j < s[y].size();j++)
			{
				int id1 = s[x][i].id,t1 = s[x][i].t,id2 = s[y][j].id,t2 = s[y][j].t;
				ans = min(ans,G[id1][id2]+t1+t2+w[x]+w[y]);
			}
		}
		cout << ans << endl;
	}
	return 0;
}