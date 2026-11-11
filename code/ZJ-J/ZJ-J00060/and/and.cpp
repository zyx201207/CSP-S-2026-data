#include<bits/stdc++.h>
using namespace std;

constexpr int N = 2e5 + 2;
long long a[N];
long long dp[N];
bool got[N];

#define DEBUG 0

#if DEBUG
#define dbg(x) cerr << #x << ":" << x << '\n'
#else
#define dbg(x)
#endif

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	dp[1] = -1;
	int tmp;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		if (dp[1] < a[i])
		{
			tmp = i;
			dp[1] = a[i];
		}
	}
	got[tmp] = true;
	for (int i = 2; i <= m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (got[j])
				continue;
			if (dp[i] < (dp[i - 1] & a[j]))
			{
				tmp = j;
				dp[i] = (dp[i - 1] & a[j]);
			}
		}
		got[tmp] = true;
	}
	cout << dp[m];
	return 0;
}
