#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	long long n,cnt = 0,ans = 0;
	cin >> n;
	string s;
	for (int i = 1;i <= n;i++)
	{
		long long t;
		char c;
		cin >> t >> c;
		cnt += t;
		for (int j = t;j >= 1;j--)
		{
			s[cnt - j] = c;
		}
	}
	for (int i = 0;i <= cnt / 2 - 1;i++)
	{
		for (int j = cnt - 1;j > cnt / 2;j--)
		{
			if (s[i] != s[j])
			{
				ans++;
			}
		}
	}
	cout << ans / 2;
	return 0;
}
