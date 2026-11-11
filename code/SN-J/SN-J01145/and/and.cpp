#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,x;
	cin >> n >> m;
	int a[n+1],s[n+1];
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for (int i = 1;i <= n;i++)
	{
		s[i] = a[i] & a[i + 1];
	}
	int mmax = -1;
	for (int i = 1;i <= n;i++)
	{
		x = s[i];
		if (x > mmax)
		{
			mmax = x;
		}
	}
	cout << mmax;
	return 0;
}
