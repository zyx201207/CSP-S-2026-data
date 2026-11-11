#include <bits/stdc++.h>
using namespace std;

int c, n, m, d, q, aa, tt;

int w[505], k[505];

int minn = 1e9;

bool chk[500005];

struct Line
{
	vector <int> a, t;
	bool to[500005];
} l[505];

//vector <Line> l;

void dfs(int now, int x, int res, int lst)
{
	for (int i = 1; i <= n; i++)
	{
		if (lst != i) res += l[i].t[now] + l[i].t[lst];
		for (int j = 1; j <= k[i]; j++)
		{
			if (l[i].to[x])
			{
				minn = min(minn, res);
				res -= l[i].t[now];
				return ;
			}
			if (chk[l[i].a[j]]) continue;
			chk[l[i].a[j]] = true;
			dfs(l[i].a[j], x, res, i);
			chk[l[i].a[j]] = false;
		}
		if (lst != i) res -= l[i].t[now] + l[i].t[lst];
	}
}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++) scanf("%d", &w[i]);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &k[i]);
		l[i].t.push_back(0), l[i].a.push_back(0);
		for (int j = 1; j <= k[i]; j++)
		{
			scanf("%d%d", &aa, &tt);
			l[i].t.push_back(tt), l[i].a.push_back(aa), l[i].to[aa] = true;
        }
        
	}
	while (q--)
	{
		int x, y, z;
		minn = 1e9;
		scanf("%d%d", &x, &y);
		chk[x] = true;
		z = w[x] + w[y];
		dfs(x, y, z, 0);
		chk[x] = false;
		printf("%d\n", minn);
	}
	return 0;
}
