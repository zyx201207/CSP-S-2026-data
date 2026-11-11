#include<bits/stdc++.h>
using namespace std;
long long n, m, a[200005], sum[200005];
int main() 
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(long long i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(i == 1)	sum[1] = a[i];
		else	sum[i] = sum[i-1]&a[i];
	}
	if(m == 1)
	{
		cout << 0;
	}
	else if(m == n)
	{
		long long t = a[1];
		for(long long i = 2; i <= n; i++)
		{
			t &= a[i];
		}
		cout << t;
	}
	else if(m == 2)
	{
		long long maxx = 0;
		for(long long i = 1; i <= n; i++)
		{
			for(long long j = i+1; j <= n; j++)
			{
				maxx = max(maxx, a[i] & a[j]);
			}
		}
		cout << maxx;
	}
	else if(m == n-1)
	{
		long long mmax = 0;
		for(long long i = 1; i <= n; i++)
		{
			mmax = max(mmax, sum[n]&i);
		}
		cout << mmax;
	}
	return 0;
}
