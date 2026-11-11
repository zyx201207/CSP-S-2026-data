#include<bits/stdc++.h>
using namespace std;
int main ()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	long long a[n+1];
	char c[n+1];
	for ( int i = 1; i <= n; i++ )
	{
		cin >> a[i] >> c[i];
	}
	unsigned long long ans = 0;
	int l = 1 , r = n;
	while ( l < r )
	{
		if ( c[l] != c[r] )
		{
			if ( a[l] >= a[r] )
			{
				ans += a[r];
				a[l] -= a[r];
				r--;
			}
			else
			{
				ans += a[l];
				a[r] -= a[l];
				l++;
			}
		}
		else
		{
			if ( a[l] >= a[r] )
			{
				a[l] -= a[r];
				r--;
			}
			else
			{
				a[r] -= a[l];
				l++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
