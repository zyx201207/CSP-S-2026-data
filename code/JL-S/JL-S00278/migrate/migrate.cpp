// C

#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6+10;
typedef long long LL;

LL c, T, n, d;
LL x[maxn];
LL e[maxn], ne[maxn], h[maxn], idx;
LL ans = 0;
LL road[100000];

void addedge(LL a, LL b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void fileread()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
}

void fastio()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
}

void clr()
{
	memset(x, 0, sizeof x);
	memset(e, 0, sizeof e);
	memset(h, -1, sizeof h);
	memset(ne, 0, sizeof ne);
	idx = n = d = ans = 0;
}


/*
void debug()
{
	cout << endl;
	for(int i = 1 ; i <= n ; i ++)
		cout << road[i] << ' ';
	cout << endl;

}
*/


void dfs(LL u, LL ed, LL tick)
{
	if(u > ed)
		return;
	if(u == ed)
	{
		road[tick] ++;
		return;
	}
	for(LL i = h[u] ; i != -1 ; i = ne[i])
	{
		LL j = e[i];
		dfs(j, ed, tick+1);
	}
}

void solve1()
{
	for(LL i = 1 ; i <= n ; i ++)
	{
		cin >> x[i];
	}
	if(n < 4)
	{
		cout << 0 << endl;
		return;
	}
	for(LL i = 1 ; i <= n ; i ++)
		for(LL j = i+1 ; j <= n ; j ++)
			if(abs(x[j] - x[i]) <= d)
				addedge(i, j);

	for(LL i = 1 ; i <= n ; i ++)
		for(LL j = i+3 ; j <= n ; j ++)
		{
			memset(road, 0, sizeof road);
			dfs(i, j, 0);

			/*
			cout << i << ' ' << j << '-' << ' ';
			debug();
			*/

			for(LL k = 1 ; k < n ; k ++)
			{
				if(road[k] != 0 && road[k] != 2)
					break;
				if(road[k] == 2)
				{
					ans ++;
					break;
				}
			}

		}
	cout << ans << endl;
}

signed main()
{
	fileread();
	fastio();
	//cout << 'a';
	cin >> c >> T;
	while(T --)
	{
		clr();
		cin >> n >> d;

		if(c <= 6)
			solve1();

	}
}

