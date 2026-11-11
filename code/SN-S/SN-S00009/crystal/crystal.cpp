#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 6;
long long n, m, a[N], maxn;
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin>> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++)
	{
		long long ans = 0, cnt = 0;
		for (int j = i; j >= 1; j--)
		{
			ans += a[i] - a[j];
			cnt++; 
		}
		if (ans <= m)
		{
			maxn = max(maxn, cnt);
		}
	}
	cout << maxn;
	return 0;
}
