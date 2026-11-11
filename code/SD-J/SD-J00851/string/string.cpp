#include <bits/stdc++.h>
using namespace std;
long long n, x, sum;
char c;
string s;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (long long i = 1; i <= n; i++)
	{
		cin >> x >> c;
		for (long long j = 1; j <= x; j++)
		{
			s += c;
		}
	}
	for (long long i = 0, j = s.length() - 1; i <= (s.length() - 1) / 2; i++, j--)
	{
		if (s[i] != s[j])
		{
			sum++;
		}
	}
	cout << sum;
	return 0;
}
