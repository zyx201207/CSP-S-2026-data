#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long

const int maxn = 2e5 + 10;

int n;

ll a[maxn];
char c[maxn];

struct str
{
	ll l, r;
	char ch;
} sec[maxn];

signed main ()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n;
	ll lst = 0, len = 0;
	int id = 0;
	ll maxx = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> c[i];
		len += a[i];
		maxx = max(maxx, a[i]);
	}
	if (maxx * (ll)n <= 100000000)
	{
		string s = " ";
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= a[i]; j++)
			{
				s += c[i];
			}
		}
		ll an = 0;
		for (int i = 1; i <= len / 2; i++)
		{
			if (s[i] != s[len - i + 1]) an++;
		}
		cout << an;
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		id++;
		sec[id].l = lst + 1;
		sec[id].r = lst + a[i];
		sec[id].ch = c[i];
		lst = sec[id].r;
		if (len % 2 == 0)
		{
			if (sec[id].l <= len / 2 && sec[id].r > len / 2)
			{
				ll rr = sec[id].r;
				sec[id].r = len / 2;
				id++;
				sec[id].l = len / 2 + 1;
				sec[id].r = rr;
				sec[id].ch = sec[id - 1].ch;
			}
		}
		else
		{
			if (sec[id].l < len / 2 + 1 && sec[id].r > len / 2 + 1)
			{
				int rr = sec[id].r;
				sec[id].r = len / 2;
				id++;
				sec[id].l = len / 2 + 1;
				sec[id].r = len / 2 + 1;
				sec[id].ch = sec[id - 1].ch;
				id++;
				sec[id].l = len / 2 + 2;
				sec[id].r = rr;
				sec[id].ch = sec[id - 1].ch;
			}
		}
	}
	
	ll ans = 0;
	
	int tail = id;
	ll pos = len;
	//cout << id << '\n';
	
	for (int i = 1; i <= id; i++)
	{
		if (sec[i].l > len / 2) break;
		int qi = sec[i].r, mo = len + 1 - sec[i].r;
		//cout << i << ' ' << qi << ' ' << mo << '\n';
		while (sec[tail].l >= mo)
		{
			//cout << "before: " << ans << ' ' << tail << ':' << sec[tail].l << ' ' << sec[tail].r << ' ' << pos << '\n';
			if (sec[tail].ch == sec[i].ch) ans += 0;
			else ans += (pos - sec[tail].l + 1);
			pos = sec[tail].l - 1;
			tail--;
			//cout << "then: " << ans << ' ' << tail << ':' << sec[tail].l << ' ' << sec[tail].r << ' ' << pos << '\n';
		}
		if (sec[tail].r >= mo)
		{
			if (sec[tail].ch != sec[i].ch) ans += (pos - mo + 1);
			pos = mo - 1;
		}
	}
	
	cout << ans;
	
	return 0;
}














