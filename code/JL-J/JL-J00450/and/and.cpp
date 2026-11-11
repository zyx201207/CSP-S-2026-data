#include<bits/stdc++.h>
using namespace std;
long long a[10010];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n , m;
	cin >> n >> m;
	long long i = 1;
	for (; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	long long s = a[n];
	for (long long j = 1; j < m; j++)
	{
		s = s & a[n-1];
		
	}
	cout <<	s << endl;
	return 0;
}
