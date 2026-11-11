#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
unsigned long long n,m,a[N],dp[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	dp[1] = a[n];
	if(m == 1)
	{
		cout << dp[1];
		return 0;
	}
	for (int i = 1; i <= m - 1; i++)
	{
		dp[i + 1] = dp[i] & a[n - i];
	}
	cout << dp[m];
	return 0;
}
