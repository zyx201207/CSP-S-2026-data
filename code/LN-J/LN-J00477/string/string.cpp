#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
long long n , a[N] , l = 1 , r , ans;
char b[N];
int main()
{
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	cin >> n;
	r = n;
	for (long long i = 1 ; i <= n ; i++)
	{
		cin >> a[i] >> b[i];
	}
	while (l != r && l <= r)
	{
		long long a1 = a[l] , a2 = a[r];
		char b1 = b[l] , b2 = b[r];
		if (b1 == b2)
		{
			if (a1 < a2)
			{
				l++;
				a[r] -= a1;
			}
			else if (a1 > a2)
			{
				r--;
				a[l] -= a2;
			}
			else
			{
				l++;
				r--;
			}
		}
		else
		{
			if (a1 < a2)
			{
				ans += a1;
				a[r] -= a1;
				l++;
			}
			else if (a2 < a1)
			{
				ans += a2;
				a[l] -= a2;
				r--;
			}
			else
			{
				ans += a1;
				l++;
				r--;
			}
		}
	}
	cout << ans;
	return 0;
}
