#include <bits/stdc++.h>
using namespace std;
int n, a[200005], m = 0;
long long num[27], z = 0, b = 0;
char c[200005], x;
int main()
{
	freopen("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i] >> c[i];
		num[c[i] - 'a'] += a[i];
		b += a[i];
		if (n % 2 == 1 && n % 2 + 1 == i)
		{
			b--;
		}
	}
	for (int i = 0;i <= 26;i++)
	{
		z = max(z, num[i]);
	}
	cout << b - z;
	return 0;
}
