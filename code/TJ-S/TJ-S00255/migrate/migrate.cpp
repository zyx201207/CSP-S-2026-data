#include <iostream>
#include <algorithm>
using namespace std;
long long x[2000010];
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, T;
	cin >> c >> T;
	while (T--)
	{
		long long d;
		int n;
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
		{
			cin >> x[i];
		}
		long long t = d / (x[2] - x[1]);
		if (t < 2 || x[n] <= d) cout << 0 << endl;
		else cout << max((long long)0, (2 * (long long)n  - 3 * t - 1) * t / 2) << endl;
	}
	return 0;
}
