#include <bits/stdc++.h>
using namespace std;
long long n, k, sum = 0,minn = 1e9 + 9;
string s, a;
string d(string x)
{
	string x1;
	for(int i = x.size() - 1; i >= 0; i--)
	{
		x1 += x[i];
	}
	return x1;
}
bool f(string x)
{
	string x1 = d(x);
	if(x == x1) return 1;
	return 0;
}
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n ;i++)
	{
		cin >> k >> a;
		long long l = 0;
		minn = min(k, minn);
		l += k;
		for(int j = 1; j <= k; j++)
		{
			s += a;
		}
	}
	if(f(s))
	{
		sum = 0;
	}
	else if(n == 2)
	{
		sum = minn;
	}
	else
	{
		long long w = s.size() / 2;
		string s1 = d(s);
		for(int i = 0; i < w ;i++)
		{
			if(s[i] != s1[i])
			{
				sum ++;
			}
		}
	}
	cout << sum;
	return 0;
}
