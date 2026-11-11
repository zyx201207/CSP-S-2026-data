#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int c, t, b[N];
long long a[N], d, n;
inline void read(long long &x)	{
	char ch = getchar();
	int f = 1;
	while (ch < '0' || ch > '9')	{
		if (ch == '-')	f = -1;
		ch = getchar();
	}
	x = 0;
	while (ch >= '0' && ch <= '9')	{
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	if (f == -1)	x = -x;
}
int main()	{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d %d", &c, &t);
	while (t--)	{
		read(n);
		read(d);
		for (int i = 1; i <= n; ++i)	read(a[i]);
		if (c == 11 || c == 12)	{
			int k = d / (a[2] - a[1]);
			if (k == 1 || k == 0)	{
				cout << 0 << endl;
				continue;
			}
			k = k * 2 - 1;
			if (n <= k)	cout << 0 << endl;
			else cout << n - k << endl;
			continue;
		}
		long long ans = 0;
		for (int i = 1, j = 1; i <= n; ++i)	{
			while (j < n && a[j + 1] - a[i] <= d)	j++;
			b[i] = j;
		}
		for (int i = 1; i <= n; ++i)	{
			int t = b[i];
			if (b[i] - i < 2)	continue;
			int p = b[b[i] - 1], q = b[b[i] - 2];
			ans += p - q;
		}
		cout << ans << endl;
	}
	return 0;
}
