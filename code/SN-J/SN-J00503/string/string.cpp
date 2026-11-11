#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, a[200010];

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	ll ans = 0;
	string s;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		char c;
		cin >> c;
		for (int j = 1;j <= a[i];j++)
		{
			s += c;
		}
	}
	for (int i = 0;i < s.length()/2;i++)
	{
		if (s[i] != s[s.length() - i - 1])
			ans++;
	}
	cout << ans;
	return 0;
}
