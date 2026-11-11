#include <bits/stdc++.h>

using namespace std;
#define MAXN 1010000
#define LL long long

LL n, m;
LL a[MAXN];


int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a+n);
	LL ans = 1;
	LL res = 1;
	int l = 0;
	LL cost = 0;
	for (int i = 1; i < n; i++)
	{
		cost += res * (a[i] - a[i-1]);
		res++;
		while (cost > m)
		{
			cost -= a[i] - a[l];
			l ++;
			res --;
		}
		ans = max(ans, res);
	}
	cout << ans << endl;
	return 0;
}