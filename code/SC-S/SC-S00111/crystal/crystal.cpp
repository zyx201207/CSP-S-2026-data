#include <iostream>
#include <algorithm>
using namespace std;
long long a[500005], d[500005], s[500005];
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	long long m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 2; i <= n; i++)
	{
		d[i] = a[i] - a[i - 1];
		s[i] = d[i] + s[i - 1];
	}
	int maxn = -2e9;
	long long sum = 0, k = 1;
	for (int i = 1; i <= n && k <= n; i++)
	{
		sum -= s[k] - s[i - 1];
		bool flag = 0;
		for (int j = k + 1; j <= n; j++)
		{
			if (sum + (j - i) * d[j] > m)
			{
				maxn = max(maxn, j - i);
				k = j - 1;
				flag = 1;
				break;
			}
			else
			{
				sum += (j - i) * d[j];
			}
		}
		if (!flag)
		{
			maxn = max(maxn, n - i + 1);
			cout << maxn;
			return 0;
		}
	}
	cout << maxn;
	return 0;
}