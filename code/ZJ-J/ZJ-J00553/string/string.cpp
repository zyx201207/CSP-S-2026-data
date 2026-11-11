#include <bits/stdc++.h>
using namespace std;
int n;
unsigned long long l = 0;
string s;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		char a;
		cin >> x >> a;
		l += x;
		for (int j = 1; j <= x; j++)
			s += a;
	}
	unsigned long long ans = 0;
	for (unsigned long long  i = 0; i < l / 2; i++)
	{
		if (s[i] != s[l - 1 - i])
			ans++;
	}
	cout << ans;
	return 0;
}

