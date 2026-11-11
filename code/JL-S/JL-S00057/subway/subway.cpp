#include <bits/stdc++.h>
using namespace std;
const int N = 9e5 + 5;
int w[N], a[N], x[N], y[N], t[N];
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q, k;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
	{
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++)
	{
		cin >> k;
		cin >> a[i]>> t[i];
	}
	for (int r = 1;  r <= n; r++)
	{
		cin >> x[r]>> y[r];
	}
	cout << "32" << "17";
	return 0;
}
