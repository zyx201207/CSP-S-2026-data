#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 500005;
ll n , m , l , r , ans , num , a[N];

signed main()
{
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	l = 1 , r = 0;
	scanf("%lld %lld" , &n , &m);
	for(ll i = 1 ; i <= n ; i++) scanf("%lld" , &a[i]);
	sort(a + 1 , a + n + 1);
	l = r = ans = 1 , num = 0;
	for(ll i = 2 ; i <= n ; i++)
	{
		num += (r - l + 1) * (a[i] - a[i - 1]);
		while(num > m) num -= (a[i] - a[l++]);
		r++; ans = max(ans , r - l + 1);
	}
	printf("%lld\n" , ans);
	return 0;
}
