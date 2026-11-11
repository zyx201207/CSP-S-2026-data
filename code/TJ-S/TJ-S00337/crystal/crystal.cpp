#include <bits/stdc++.h>
using namespace std;

long long n,m,a[500000];
int b[100000000],ans = 0;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for(long long i = 1;i <= n;i++)
	{
		sort( a + 1 , a + n + 1);
		long long x = a[2] - a[1] + 1;
		if(m < x)
		{
			a[1] += m;
			break;
		}
		a[1] += x;
		m -= x;
	}
	for(long long i = 1;i <= n;i++)
	{
		b[a[i]]++;
		ans = max(b[a[i]],ans);
	}
	cout << ans;
	return 0;
}
