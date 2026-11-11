#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;

typedef long long LL;

LL n;
LL a[N];
LL ans;
LL cnt;
LL m;

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	
	for (int i = 1; i <= n; i ++ )
		cin >> a[i];
	
	sort(a + 1, a + n + 1);
	
	LL l = 1;
	ans = 1;
	
	for (int i = 2; i <= n; i ++ )
	{
		cnt += 1ll * (i - l) * (a[i] - a[i - 1]);
		
		while (cnt > m)
		{
			cnt -= a[i] - a[l];
			l ++ ;
		}
		
		ans = max(ans, i - l + 1);
	}
	
	cout << ans << '\n';
	
	return 0;
}