#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll x;
char c;
string s;
ll ans;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> x >> c;
		for (int j = 0; j < x; j++)
		{
			s += c;
		}
	}
	for (int i = 0, j = s.size(); i < s.size(); i++, j--)
	{
		if (s[i] != s[j])
		{
			ans++;
		}
	}
	cout << ans - 1;
	return 0;
}
