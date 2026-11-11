#include <bits/stdc++.h>
using namespace std;
char s[200005];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	long long b = 1;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		long long t;
		char a;
		cin >> t >> a;
		for (long long i = b; i <= t + b - 1; i++)
		{
			s[i] = a;
		}
		b += t;
	}
	b -= 1;
	long long t = b / 2, ans = 0;
	for (long long i = 1; i <= t; i++)
	{
		if (s[i] != s[b - i + 1])
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}
