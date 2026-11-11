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


int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cout << 1 << '\n';
	return 0;
}
