#include <bits/stdc++.h>
using namespace std;
long long a[500005];
int main ()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,cnt = 1;
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for (int i = 1;i <= n;i++)
	{
		if (m - i >= 0)
		{
			m -= i;
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}
