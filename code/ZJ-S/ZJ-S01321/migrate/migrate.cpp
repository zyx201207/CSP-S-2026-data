#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e6 + 10;
int x[N], n, d, k, c, t;
void work()
{
	scanf("%d%d", &n, &d);
	if(n <= 2)
	{
		puts("0");
		return;
	}
	for(int i = 1; i <= n; i ++) scanf("%lld", &x[i]);
	if(c == 11 || c == 12)
	{
		k = d / (x[2] - x[1]);
		if(k <= 1) puts("0");
		else printf("%d\n", max(0 * 1ll, n + 1 - 2 * k));
		return;
	}
	
	for(int l = 1, r = 1; l <= n; l ++)
	{
		while(r < n && x[r + 1] - x[l] <= d) r ++;
		suf[l] = r;
	}
	if(c == 13 || c == 14)
	{
		int res = 0;
		for(int i = 1; i <= n; i ++)
		{
			if(suf[i] == n) break;
			if(suf[i] == 2) continue;
			int s1 = suf[suf[i] - 1], s2 = suf[suf[i] - 2];
			res += s1 - s2;
		}
		cout << res << endl;
	}
	
	
}
signed main()
{
	//最后记得删掉//
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t --) work();
	
	return 0;
}

