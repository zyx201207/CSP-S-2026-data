#include <bits/stdc++.h>
using namespace std;

struct st
{
	long long id,T;
};

st t[505];
int c,n,m,d,q;
long long a[500005],f[505][505];

void solvef()
{
	for(int i = 1;i <= m;i++)
	{
		cin >> a[i];
		for(int j = 1;j <= m;j++)
			if(i != j)
				f[i][j] = 2e9;
	}
	for(int i = 1;i <= n;i++)
	{
		int k;
		cin >> k;
		for(int j = 1;j <= k;j++)
		{
			cin >> t[j].id >> t[j].T;
			for(int o = 1;o < j;o++)
			{
				f[t[j].id][t[o].id] = min(t[j].T + t[o].T,f[t[j].id][t[o].id]);
				f[t[o].id][t[j].id] = f[t[j].id][t[o].id];
			}
		}
	}
	for(int k = 1;k <= m;k++)
		for(int i = 1;i <= m;i++)
			for(int j = 1;j <= m;j++)
				if(i != j && i != k && j != k)
					f[i][j] = min(f[i][j],f[i][k]+f[k][j]);
	for(int i = 1;i <= q;i++)
	{
		int u,v;
		cin >> u >> v;
		cout << f[u][v] + a[u] + a[v] << "\n";
	}
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	solvef();
	return 0;
}
