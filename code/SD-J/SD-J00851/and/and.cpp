#include <bits/stdc++.h>
using namespace std;
string two(long long x)
{
	string s1, s2;
	while (x)
	{
		s1 += x % 2 + '0';
		x /= 2;
	}
	for (long long i = s1.length() - 1; i >= 0; i--)
	{
		s2 += s1[i];
	}
	return s2;
}
string f(string s1, string s2)
{
	string s3, s4;
	if (s1.length() >= s2.length())
	{
		long long n = s1.length() - s2.length();
		for (long long i = 1; i <= n; i++)
		{
			s3 += '0';
		}
		for (long long i = 0; i < s2.length(); i++)
		{
			s3 += s2[i];
		}
		for (long long i = 0; i < s1.length(); i++)
		{
			if ((s1[i] - '0') && (s3[i] - '0'))
			{
				s4 += '1';
			}
			else
			{
				s4 += '0';
			}
		}
	}
	else
	{
		long long n = s2.length() - s1.length();
		for (long long i = 1; i <= n; i++)
		{
			s3 += '0';
		}
		for (long long i = 0; i < s1.length(); i++)
		{
			s3 += s1[i];
		}
		for (long long i = 0; i < s2.length(); i++)
		{
			if ((s2[i] - '0') && (s3[i] - '0'))
			{
				s4 += '1';
			}
			else
			{
				s4 += '0';
			}
		}
	}
	return s4;
}
long long ten(string s)
{
	long long sum = 0, num = 0;
	for (long long i = s.length() - 1; i >= 0; i--)
	{
		sum += (s[i] - '0') * pow(2, num), num++;
	}
	return sum;
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);
	long long n, m, a[100001], maxx = 0;
	cin >> n >> m;
	for (long long i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (long long i = 1; i <= n; i++)
	{
		for (long long j = i + 1; j <= n; j++)
		{
			maxx = max(maxx, ten(f(two(a[i]), two(a[j]))));
		}
	}
	cout << maxx;
	return 0;
}
