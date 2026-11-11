#include <bits/stdc++.h>
using namespace std; 
#define ll long long
constexpr ll N = 5e5 + 7;
ll A[N]; 
ll sum[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	scanf("%lld%lld",&n,&m);
	for (ll i = 1; i <= n; i ++) scanf("%lld",&A[i]);
	sort(A + 1,A + 1 + n);
	for (ll i = 1; i <= n; i ++) sum[i] = sum[i - 1] + A[i];
	ll ans = 0;
	ll i = 1,j = 1;
	while (j <= n)
	{
		if (A[j] * (j - i + 1) - (sum[j] - sum[i - 1]) <= m) ans = max(ans,j - i + 1),j ++;
		else if (i < j) i ++;
		else j ++;
	}
	printf("%lld\n",ans);
	return 0;
}
/*

5 8
-3 -1 2 2 7

*/
