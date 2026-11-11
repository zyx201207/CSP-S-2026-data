#include <bits/stdc++.h>
using namespace std;
const long long N = 500005;
long long n , m , a[N] , L , R , sum[N];
bool check(long long num)
{
	for (long long l = 1 ; l + num - 1 <= n ; l++)
	{
		long long r = l + num - 1;
		if (a[r] * (r - l) - (sum[r - 1] - sum[l - 1]) <= m)
		{
			return true;
		}
	}
	return false;
}
int main()
{
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	cin >> n >> m;
	for (long long i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
	}
	sort(a + 1 , a + n + 1);
	for (long long i = 1 ; i <= n ; i++)
	{
		sum[i] = sum[i - 1] + a[i];
	}
	L = 1 , R = n;
	while (L < R)
	{
		long long mid = (L + R + 1) / 2;
		if (check(mid))
		{
			L = mid;
		}
		else
		{
			R = mid - 1;
		}
	}
	cout << L;
	return 0;
}
