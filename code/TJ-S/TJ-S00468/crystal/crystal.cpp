#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long a[500005], ans;
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	cin >> n >> m;
	if (n > 10000)
	{
		long long left = 1, right = 1000000000;
		int fal = 1;
		while(left < right)
		{
			long long cen = (right + left) / 2;
			if (m / cen > (cen + 1) / 2.0)
			{
				left = cen + 1;
			}
			else if (m / cen < (cen + 1) / 2.0)
			{
				right = cen;
			}
			else
			{
				left = cen;
				break;
			}
		}
		cout << left + 1;
		return 0;
	}
	for (long long i = 1; i <= n; i ++) cin >> a[i];
	sort(a, a + n + 1);
	for (long long i = 2; i <= n; i ++)
	{
		long long high = a[i];
		long long mag = m;
		long long rep = 1;
		for (long long j = i - 1; j > 0; j --)
		{
			mag += a[j];
			mag -= high;
			if (mag < 0) break;
			rep ++;
		}
		ans = max(rep, ans);
	}
	cout << ans;
	return 0;
} 
