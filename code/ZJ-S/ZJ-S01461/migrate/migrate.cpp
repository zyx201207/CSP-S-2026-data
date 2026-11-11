#include<bits/stdc++.h>
using namespace std;
long long f (long long n,long long d,long long a[],int x)
{
	if ( x == 1 )
	{
		return (long long)(1);
	}
	long long sum = 0;
	for ( int i = 1; i <= x; i++ )
	{
		if (f(i,d,a,i)==f(n-i,d,a,i)) sum++;
	}
	return sum;
}
int main ()
{
	freopen("migrate.in","r",stdin)
	freopen("migrate.out","w",stdout);
	long long c , t;
	cin >> c >> t;
	for ( int i = 1; i <= t; i++ )
	{
		long long n , d;
		cin >> n >> d;
		long long a[n+1];
		cin >> a[i];
		cout << f(n,d,a,n) << "\n";
	}
	
	return 0;
}
