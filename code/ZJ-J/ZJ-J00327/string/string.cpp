#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, ans = 0;
	long long l = 0;
	string s = "";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		long long ai;
		char ci;
		cin >> ai >> ci;
		l += ai;
		for (int j = 1; j <= ai; j++) s += ci; 
	}
	for (long long i = 0; i < l / 2.0; i++)
	{
		if (s[i] != s[l - 1 - i]) ans++;
	}
	cout << ans;
	return 0;
}
