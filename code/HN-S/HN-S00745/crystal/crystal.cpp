#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long n, m, a[N], sum[N], l, r, mid, ans; 
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1;i <= n;i++)
	{
		sum[i] = sum[i - 1] + a[i];
	}
	for (int i = 1;i <= n;i++)
	{
		l = 1, r = i;
		while (l < r)
		{
			mid = (l + r) / 2;
			if ((i - mid + 1) * a[i] - (sum[i] - sum[mid - 1]) <= m)
			{
				r = mid;
			}
			else
			{
				l = mid + 1;
			}
		}
		ans = max(ans, i - l + 1);
	}
	cout << ans;
	return 0;
}
/*
5 5
1 2 4 8 9

*/
