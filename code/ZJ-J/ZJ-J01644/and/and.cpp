#include <bits/stdc++.h>
#define endl '\n'
#define ull unsigned long long
using namespace std;

const int N = 2e5 + 10;

ull n, m, a[N], dp[N], ans = 0;

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	dp[0] = 2147483647;
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = m; j >= 1; j--)
		{
			dp[j] = max(dp[j], (dp[j - 1] & a[i]));
			// cout << i  << "   " << m - j  << "     "<< "dp[" << j << "]: " << dp[j] << endl;
		}
		ans = max(dp[m], ans);
	}
	
	cout << ans << endl;
	
	return 0;
}
