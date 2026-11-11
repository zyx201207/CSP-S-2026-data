#include <iostream>
#include <cstdio>
#define ll long long
#define N 200007
using namespace std;

int n, l, r;
ll ans;

struct str
{
	ll cnt;
	char wod;
}s[N];

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i].cnt >> s[i].wod;
	}
	l = 1, r = n;
	while (l < r)
	{
		int min_cnt = min(s[l].cnt, s[r].cnt);
		if (s[l].wod != s[r].wod)
		{
			ans += min_cnt;
		}
		s[l].cnt -= min_cnt;
		s[r].cnt -= min_cnt;
		if (!s[l].cnt) l++;
		if (!s[r].cnt) r--;
	}
	cout << ans;
	return 0;
}
