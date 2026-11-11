#include<iostream>
using namespace std;
typedef long long ll;
ll d , x[2000005];
int C , l[2000005] , f[5005][5005] , g[5005][5005];
bool check(int l , int r)
{
	return x[r] - x[l] <= d;
}
void solve()
{
	int n; scanf("%d%lld" , &n , &d);
	for (int i = 1; i <= n; i++) scanf("%lld" , &x[i]);
	for (int i = 1 , j = 1; i <= n; i++)
	{
		while (j < i && !check(j , i)) j ++;
		l[i] = j;
	}
	if (C <= 10)
	{
		int p = 1 , ans = 0;
		for (int i = 2; i <= n; i++)
		{
			if (l[i] == i)
			{
				p = i;
				continue;
			}
			for (int j = l[i]; j < i; j++) f[j][i] = g[j][i] = 1;
			for (int j = p; j < l[i]; j++)
			{
				f[j][i] = f[j][l[i]] + 1;
				int s = l[i] , t = i - 1;
				while (s < t)
				{
					int mid = s + t + 1 >> 1;
					if (f[j][mid] == f[j][l[i]]) s = mid;
					else t = mid - 1;
				}
				g[j][i] = g[j][s] - g[j][l[i] - 1];
				if (g[j][i] == 2) ans ++;
				g[j][i] = min(g[j][i] , 3);
			}
			for (int j = p; j < i; j++) g[j][i] += g[j][i - 1];
		}
		printf("%d\n" , ans);
	}
	else if (C <= 12)
	{
		int c = min(d / (x[2] - x[1]) , (ll)(n));
		if (c <= 1 || n < c * 2 - 1) printf("0\n");
		else printf("%d\n" , n - c * 2 + 1);
	}
	else if (C <= 14)
	{
		int p = 0;
		for (int i = 1; i <= n; i++)
		{
			if (check(1 , i) && check(i , n))
			{
				p = i;
				break;
			}
		}
		l[n + 1] = n + 1;
		ll ans = 0;
		for (int i = p + 1; i <= n; i++)
		{
			if (l[i] == p - 1) ans += l[p + 1] - 1;
			else if (l[i] == p) ans += l[p + 2] - l[p + 1];
		}
		printf("%lld\n" , ans);
	}
}
int main()
{
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	int t; cin >> C >> t;
	while (t --) solve();
	return 0;
}
