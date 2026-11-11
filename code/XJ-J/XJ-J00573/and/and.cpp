#include <bits/stdc++.h>
using namespace std;
long long a[200005];
bool cmp(long long x, long long y)
{
	return x > y;
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m, s3 = 0, s2 = 0, f = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] > 3) f = 1;
		if (a[i] == 3) s3++;
		if (a[i] == 2) s2++;
	}
	if (f == 0)
	{
		if (m > s3)
		{
			if (m - s3 <= s2) cout << 2;
			else cout << 1;
		}
		else cout << 3;
		return 0;
	}
	else
	{
		sort(a + 1, a + n + 1, cmp);
		cout << a[m];
    }
	return 0;
}
