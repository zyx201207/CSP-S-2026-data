#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n, cnt = 0;
	long long len = 0, len1 = 0, len2 = 0;
	string s, s1, s2;
	cin >> n;
	for(long long i = 1; i <= n; i++)
	{
		long long a;
		char c;
		cin >> a >> c;
		len += a;
		for(long long i = 1; i <= a; i++)
		{
			s = s + c;
		}
	}
	len1 = len / 2;
	len2 = len / 2;
	for(long long i = 0; i <= len1 - 1; i++)
	{
		s1 = s1 + s[i];
	}
	for(long long i = 0; i <= len2 - 1; i++)
	{
		s2 = s2 + s[len - i - 1];
	}
	for(long long i = 0; i <= len1 - 1; i++)
	{
		if(s1[i] != s2[i])
		{
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
