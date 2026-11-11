#include <iostream>
#include <algorithm>
using namespace std;
long long a[500010];
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n;
	long long m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int j = 1;
	long long sum = 0;
	int ans = 1;
	for (int i = 2; i <= n; i++)
	{
		sum += (long long)(a[i] - a[i - 1]) * (i - j);
		while (sum > m)
		{
			sum -= (a[i] - a[j]);
			j++;
		}
		ans = max(ans, i - j + 1);
	}
	cout << ans;
	return 0;
}
