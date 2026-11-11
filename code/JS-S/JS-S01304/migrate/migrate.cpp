#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
long long x[N];
int k[N], kkk[N];
long long dp1[N], dp2[N];
long long Dp1(int i, int j)
{
	if (j <= kkk[i])
	{
		if (kkk[i] == i) return 0;
		return 1;
	}
	return dp1[j];
}
long long Dp2(int i, int j)
{
	if (j <= kkk[i]) return 1;
	return dp2[j];
}
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int c, t;
	cin >> c >> t;
	while (t--)
	{
		long long n, d;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) cin >> x[i];
		for (int i = 1, j = 1; i <= n; i++)
		{
			while (x[i] - x[j] > d) j++;
			k[i] = j;
		}
		for (int i = 1, j = 1; i <= n; i++)
		{
			while (j < n && x[j + 1] - x[i] <= d) j++;
			kkk[i] = j;
		}
		long long ans = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = kkk[i] + 1; j <= n; j++)
			{
				if (x[j] - x[j - 1] > d) break;
				int t = max(k[j], i);
				dp1[j] = Dp1(i, t) + 1;
				dp2[j] = Dp2(i, t);
				if (Dp2(i, t) > 2) break;
				if (t + 1 < j && Dp1(i, t + 1) == Dp1(i, t))
				{
					dp2[j]++;
					if (t + 2 < j && Dp1(i, t + 2) == Dp1(i, t))
					{
						dp2[j]++;
						if (t + 3 < j && Dp1(i, t + 3) == Dp1(i, t)) dp2[j]++;
					}
				}
				if (dp2[j] == 2) ans++;
				//if (dp2[j] > 2) break;
			}
		}
		cout << ans << endl;
		continue;
	}
	return 0;
}
