#include<bits/stdc++.h>
#define pre(i, l, r)	for(int i = (l); i <= (r); ++i)
#define fpre(i, r, l)	for(int i = (r); i >= (l); --i)
#define ll long long

using namespace std;

const int maxn = 1e6 + 5;
const int inf = 1e9;
const ll lnf = 2e18;

//有了u，我们枚举v，如果当前路径数量恰好等于2就可以
int c, t, n;
ll a[maxn], d;
int dis[maxn], f[maxn];

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &t);
	while(t--)
	{
		scanf("%d%lld", &n, &d);
		pre(i, 1, n)
			scanf("%lld", &a[i]);
		ll ans = 0;
		pre(i, 1, n)
		{
			pre(j, 1, n)	dis[j] = f[j] = 0;
			f[i] = 1;
			dis[i] = 0;
			pre(j, i + 1, n)
			{
				dis[j] = inf, f[j] = 0;
				fpre(k, j - 1, i)
					if(a[j] - a[k] <= d)
					{
						if(dis[k] + 1 < dis[j])
							dis[j] = dis[k] + 1, f[j] = f[k];
						else
							if(dis[k] + 1 == dis[j])
								f[j] = min(f[j] + f[k], 3);
					}
					else
						break;
			}
			pre(j, i, n)
				if(f[j] == 2)
					++ans;
		}
		printf("%lld\n", ans);
	}
	return 0;
}

/*
1 1
6 4
-3 0 1 2 3 4

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
