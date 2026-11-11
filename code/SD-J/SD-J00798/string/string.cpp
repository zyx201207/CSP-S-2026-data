#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n, ans = 0;
	string s = "";
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		int a;
		char c;
		cin >> a >> c;
		s.insert(s.size(), a, c);
	}
	string r = s;
	reverse(r.begin(), r.end());
	if (r == s)
	{
		cout << 0;
		return 0;
	}
	if (s.size() % 2 == 0)
	{
		for (int i = s.size() / 2;i < s.size();i++)
		{
			if (s[i] != r[i]) ans += 1;
		}
	}
	else
	{
		for (int i = s.size() / 2 + 1;i < s.size();i++)
		{
			if (s[i] != r[i]) ans += 1;
		}
	}
	cout << ans;
	return 0;
}
