#include<bits/stdc++.h>
using namespace std;
const int N = 500005;
long long n, m;
long long a[N];
long long b[N];
long long c[N];
bool ck(int d)
{
	for (int i = 1; i <= n - d; i ++)
	{
		long long sum = (d - 1) * a[i + d - 1];
		sum -= b[i + d - 2] - b[i - 1];
//		for (int j = i ; j <= i + d - 1; j ++)
//		{
//			sum += a[i + d - 1] - a[j];
//		}
//		cout << sum << " ";
		if (sum <= m)
		{
			return true;
		}
	}
	return false;
}
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i ++)
	{
		b[i] = b[i - 1] + a[i];
	}
//	for (int i = 1; i <= n; i ++)
//	{
//		cout << b[i] << " ";
//	}
//	cout << "\n";
	long long l = 1, r = n;
	while (l < r)
	{
		long long mid = (l + r + 1) >> 1;
		if (ck(mid))
		{
			l = mid;
		}
		else
		{
			r = mid - 1;
		}
//		cout << l << " " << r << "\n";
	}
	cout << l;
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/