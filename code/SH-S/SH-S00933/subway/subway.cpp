#include <bits/stdc++.h>

using namespace std;

struct plan
{
	int s, e;
}p[10000];
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q, w[10000], s[10000][10000][2], num;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
	{
		cin >> w[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		for (int j = 0; j < num; j++)
		{
			cin >> s[i][j][0] >> s[i][j][1];
		}
	}
	for (int i = 0; i < q; i++)
	{
		cin >> p[i].s >> p[i].e;
	}
	int minn = 5000000;
	for (int i = 0; i < q; i++)
	{
		for (int j = 0; j < n; j++)
			minn = min(s[j][p[i].s][1], minn);	
		cout << w[p[i].s] + w[p[i]];
	}
	return 0;
}
