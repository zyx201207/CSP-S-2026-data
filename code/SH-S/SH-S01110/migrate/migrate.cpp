#include <bits/stdc++.h>
using namespace std;

int c, t, n;
long long d;

const int N = 2e6 + 5;
const long long INF = 1e16;

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> c >> t;

	while (t--)
	{
		cin >> n >> d;
		vector<long long> x(n + 2), rt(n + 2), f(n + 2), cnt(n + 2);
		for (int i = 1; i <= n; i++)
		{
			cin >> x[i];
		}
		
		int j = 2;
		for (int i = 1; i < n; i++)
		{
			while (x[j] - x[i] <= d && j <= n) j++;
			rt[i] = j - 1;
		}
		
		long long ans = 0;
		
		for (int i = 1; i <= n; i++)
		{
			for (int j = i; j <= n; j++) f[j] = cnt[j] = INF;
			f[i] = cnt[i] = 1;
			for (int j = i; j < n; j++)
			{
				if (cnt[j] == 2) ans++;
				for (int k = j + 1; k <= rt[j]; k++)
				{
					if (f[k] == f[j] + 1) cnt[k] += cnt[j];
					else if (f[k] > f[j] + 1) f[k] = f[j] + 1, cnt[k] = cnt[j];
				}
			}
			if (cnt[n] == 2) ans++;
		}
		
		cout << ans << '\n';
	}
	
	return 0;
}
