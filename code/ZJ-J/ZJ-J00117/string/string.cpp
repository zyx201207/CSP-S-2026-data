#include <bits/stdc++.h>
using namespace std;
int a[200000];
char c[200000];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	long long ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i] >> c[i];
	for (int i = 0, j = n - 1; i < j; )
	{
		//cout << i << ' ' << j << ' ' << a[i] << ' ' << a[j] << '\n';
		if (a[i] > a[j])
		{
			a[i] -= a[j];
			if (c[i] != c[j])
				ans += a[j];
			j--;
		}
		else if (a[i] < a[j])
		{
			a[j] -= a[i];
			if (c[i] != c[j])
				ans += a[i];
			i++;
		}
		else
		{
			if (c[i] != c[j])
				ans += a[i];
			i++;
			j--;
		}
	}
	cout << ans;
}
