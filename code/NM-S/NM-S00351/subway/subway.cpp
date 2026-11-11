#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, ans;
int w[10086];
struct lines
{
	int k;
	int a[114514], t[114514]; 
} l[505];

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
	{
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> l[i].k;
		for (int j = 1; j <= l[i].k; j++)
		{
			cin >> l[i].a[j] >> l[i].t[j];
		}
	}
	int x, y, status = 0;
	if (c >= 7 && c <= 11)
	{
		while (q--)
		{
			cin >> x >> y;
			if (x > y)
			{
				x += y;
				y = x - y;
				x -= y;
			}
			ans += (w[x] + w[y]);
			int status = 0;
			for (int i = 1; i <= n; i++)
			{
				if (l[i].a[2] == y)
				{
					ans += (l[i].t[1] + l[i].t[2]);
					break;
				} 
				if (l[i].a[1] == x || status == 1)
				{
					ans += (l[i].t[1] + l[i].t[2]); 
					status = 1;
				} 
			}
			cout << ans << endl;
			ans = 0;
		}
	}
	return 0;
}
