#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 6; 
long long n, a, m, maxn;
char c;
string s;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	s += ' ';
	for (int i = 1; i <= n; i++)
	{
		cin >> a >> c;
		for (long long j = 1; j <= a; j++)
		{
			m++;
			s += c;
		}
	}
	if (n == 1)
	{
		cout << 0;
		return 0;
	}
	for (long long i = 1; i <= m; i++)
	{
		if (s[i] != s[m + 1 - i])
		{
			maxn++;
		}
	}
	cout << maxn / 2;
	return 0;
}
