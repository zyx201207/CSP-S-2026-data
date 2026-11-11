#include <bits/stdc++.h>
using namespace std;

long long l[200005];
char c[200005];

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> l[i] >> c[i];
	long long a = 0, b = 0, ans = 0, ai = 1, bi = n, an = 1, bn = n;
	while (ai < n + 1 || bi > 0)
	{
		if (a == 0) 
		{
			an = ai;
			a = l[ai++];
		}
		if (b == 0)
		{
			bn = bi;
			b = l[bi--];
		} 
		long long t = min(a, b);
		a -= t;
		b -= t;
		if (c[an] != c[bn]) ans += t; 
	}
	cout << ans / 2 << '\n';
	return 0;
}
