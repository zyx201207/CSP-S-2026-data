#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e5 + 5;
ll n;
ll num[MAXN];
char lett[MAXN];
string s;
ll ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (ll i = 1; i <= n; i++)
	{
		cin >> num[i] >> lett[i];
		for (ll j = 1; j <= num[i]; j++)
		{
			s.push_back(lett[i]);
		}
	}
	ll l = 0, r = s.size() - 1;
	while (l < r)
	{
		if (s[l] != s[r])
			ans++;
		l++, r--;
	}
	cout << ans << '\n';
	return 0;
}