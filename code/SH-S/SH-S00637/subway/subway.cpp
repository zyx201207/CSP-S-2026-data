#include <bits/stdc++>
using namespace std;

int c,n,m,d,q,w[500010],k[510],a[510][500010],t[510][500010],x[100010],y[100010],_a[500010][510],_k[500010];

int main()
{
	cin >> c >> n >> m >> d >> p;
	for (int i = 1;i <= m;i++) cin >> w[i];
	for (int i = 1;i <= n;i++) cin >> k[i];
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= k[i];j++)
		{
			cin >> a[i][j] >> t[i][j];
			_k[a[i][j]]++;
			a[_k[a[i][j]]] = i;
		}
	}
	for (int i = 1;i <= q;i++) cin >> x[i] >> y[i];
	for (int i = 1;i <= q;i++)
	{
		bool flag[500010];
		long long dis[500010];
		dis[x[i]] = w[x[i]];
		for (int j = 1;j <= m;j++) dis[j] = -1;
		for (int j = 1;j <= m;j++) flag[j] = false;
		queue<int> q;
		q.push(x[i]);
		flag[x[i]] = true;
		while (!q.empty())
		{
			int p=q.front();
			q.pop();
			for (int j = 1;j <= _k[p];j++)//遍历线路
			{
				for (int l = 1;l <= k[j];l++)//遍历线路上的站
				{
					if (flag[a[j][l]]) continue;
					dis[
				}
			}
		}
	}
	return 0;
} 
