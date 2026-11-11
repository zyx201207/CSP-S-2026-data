#include<bits/stdc++.h>
using namespace std;
int main ()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n , m;
	cin >> n >> m;
	long long a[n+5];
	a[n+1] = 1e10;
	for ( int i = 1; i <= n; i++ )
	{
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	long long b[n+5] = {};
	long long c[n+5] = {};
	long long d[n+5] = {};
	for ( int i = 1; i <= n; i++ )
	{
		b[i] = a[i+1]-a[i];
		c[i] = c[i-1]*2+b[i];
		d[i] = d[i-1]+c[i];
		cout << d[i] << endl;
	}
	for ( int i = n; i >= 1; i-- )
	{
		if ( d[i] <= m )
		{
			cout << i+1;
			break;
		}
	}
	return 0;
}
