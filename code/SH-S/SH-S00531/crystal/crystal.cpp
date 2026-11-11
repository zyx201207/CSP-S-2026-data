#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

long long a[500010], sum[500010];

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	sum[1] = 0;
	for(int i = 2; i <= n; i++)
	{
		sum[i] = sum[i - 1] + (a[i] - a[i - 1]) * (i - 1);
	}
	int ans = upper_bound(sum + 1, sum + n + 1, m) - sum - 1;
	cout << ans << endl;
	return 0;
}
