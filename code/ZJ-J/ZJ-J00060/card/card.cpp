#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 2, M = 3e5 + 2;
int a[N];
int pos[N];
int cnt[M];
vector<int> cards;

#define DEBUG 0

#if DEBUG
#define dbg(x) cerr << #x << ":" << x << '\n'
#else
#define dbg(x)
#endif

inline int read()
{
	int f = 1, x = 0;
	char ch = getchar_unlocked();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')
			f = -1;
		ch = getchar_unlocked();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = x * 10 + (ch ^ 48);
		ch = getchar_unlocked();
	}
	return f * x;
}

inline void write(int x)
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
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	int n, m;
	n = read(), m = read();
	for (int i = 1; i <= n; ++i)
		a[i] = read();
	for (int i = 1; i <= n; ++i)
	{
		cards.clear();
		for (int j = i; j <= n; ++j)
		{
			if (pos[a[j]] == 0)
			{
				cards.push_back(a[j]);
				pos[a[j]] = cards.size();
				dbg(pos[a[j]]);
				dbg(a[j]);
				dbg(j);
			}
			else
			{
				dbg(j);
				int sz = cards.size();
				int tmp = pos[a[j]];
				for (int k = pos[a[j]] - 1; k < sz; k++)
					pos[cards[k]] = 0;
				cards.erase(cards.begin() + tmp - 1, cards.end());
				cards.push_back(a[j]);
				pos[a[j]] = cards.size();
			}
		}
		sort(cards.begin(), cards.end());
		cards.erase(unique(cards.begin(), cards.end()), cards.end());
		for (int j:cards)
		{
			cnt[j]++;
			pos[j] = 0;
		}
	}
	for (int i = 1; i < m; ++i)
	{
		write(cnt[i]);
		putchar(' ');
	}
	write(cnt[m]);
	return 0;
}
