#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n;
	cin >> n;
	string s;
	for (long long i = 0; i < n; i++)
	{
		long long a;
		string A;
		cin >> a >> A;
		for (long long i = 0; i < a; i++)
		{
			s += A;
		}
	}
	long long k = s.size();
	long long ans = 0;
	string a;
	for (long long i = k - 1; i >= 0; i--)
	{
		a += s[i];
	}
	for (long long i = 0; i < k; i++)
	{
		if (k / 2 == i)
		{
		   	break;
		}
		if (s[i] != a[i])
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}
