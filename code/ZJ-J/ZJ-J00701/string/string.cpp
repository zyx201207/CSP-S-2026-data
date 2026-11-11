#include <bits/stdc++.h>
using namespace std;
long long n, ans = 0;
string s = "";
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		char y;
		cin >> x >> y;
		for (int i = 1; i <= x; i++) s += y;
	}
	for (int i = 0; i < s.size() / 2; i++)
	{
		if (s[i] != s[s.size() - i - 1]) ans++;
	}
	cout << ans;
	return 0;
}