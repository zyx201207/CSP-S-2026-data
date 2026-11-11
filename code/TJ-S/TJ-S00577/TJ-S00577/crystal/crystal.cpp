#include <bits/stdc++.h>
using namespace std;
long long m,n;
long long a[100010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	int sis = (1 + n) / 2;
	for (int i = sis - 1;i > 0;i--)
	{
		if (m != 0)
		{
			m = m - (a[sis] - a[i]);
			//cout << a[sis] - a[i] << endl;
			a[i] = a[sis];

		}
	}
	int cnt = 0;
	for (int i = 0;i < n;i++)
	{
		if (a[i] == a[sis])
		{
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}

