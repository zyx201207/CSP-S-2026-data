#include <bits/stdc++.h>
using namespace std;
int a[50005];
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	while (q--)
	{
		long long s = 0;
		for (int i = 1; i <= m; i++)
		{
			cin >> a[i];
			s += a[i];
		}
		cout << s << endl;
	}
	return 0;
}
