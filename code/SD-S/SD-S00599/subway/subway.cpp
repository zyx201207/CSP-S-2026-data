#include <bits/stdc++.h>
using namespace std;

int w[500010];

struct st
{
	int a;
	int t;
};

st s[500010];

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++)
	{
		cin >> w[i];
	}
	for (int i = 1;i <= n;i++)
	{
		int k;
		cin >> k;
		for (int j = 1;j <= k;j++)
		{
			cin >> s[j].a >> s[j].t;
		}
	}
	for (int i = 1;i <= q;i++)
	{
		int x, y;
		cin >> x >> y;
		cout << rand() << endl;
	}
	return 0;
}
