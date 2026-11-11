#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

inline ll read()
{
	ll f = 1, x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = x * 10 + (ch ^ 48);
		ch = getchar();
	}
	return f * x;
}

inline void write(ll x)
{
	if (x < 0)
	{
		putchar('-');
		x = -x;
	}
	if (x > 9)
		write(x / 10);
	putchar(x % 10 + '0');
}

constexpr int N = 5e5 + 2;
ll a[N];

ll my_abs(ll x) { return (x < 0)?(-x):(x); }

#define DEBUG 0

#if DEBUG
#define dbg(x) cerr << #x << ":" << x << '\n'
#else
#define dbg(x)
#endif

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n;
	ll m, cnt = 0;
	n = read(), m = read();
	for (int i = 0; i < n; ++i)
		a[i] = read();
	sort(a, a + n);
	int mid = n / 2;
	vector<ll> v;
	for (int i = 0; i < n; ++i)
	{
		if (a[i] == a[mid])
		{
			cnt++;
			continue;
		}
		v.push_back(my_abs(a[i] - a[mid]));
	}
	sort(v.begin(), v.end());
	for (ll i:v)
	{
		m -= i;
		if (m >= 0)
			cnt++;
		else
			break;
	}
	write(cnt);
	return 0;
}
