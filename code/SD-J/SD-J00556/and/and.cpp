#include <bits/stdc++.h>
using namespace std;
#define ll long long
constexpr ll N = 2e5 + 7;
ll A[N];
bool cmp(const ll &a,const ll & b) {return a > b;}
ll sum = 0;ll n,m;
void dfs(ll step,ll t,ll cnt)
{
	if (step == n + 1)
	{
		if (cnt == m) sum = max(sum,t);
		return ;
	}
	if (cnt > m) return ;
	if (t < sum) return ;
	dfs(step + 1,t & A[step],cnt + 1);
	dfs(step + 1,t,cnt);
	return ;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	bool f = true;
	bool f2 = true;
	for (ll i = 1; i <= n; i ++)
	{
		scanf("%lld",&A[i]);
		if (A[i] != (1ll << i) - 1) f = false;
		if (A[i] != i - 1) f2 = false;
	}
	sort(A + 1,A + 1 + n,cmp);
	if (m == 1) printf("%lld\n",A[1]);
	else if (f) printf("%lld\n",A[m]);
	else if (f2) printf("%lld\n",n - m);
	else if (m == n)
	{
		ll ans = A[1];
		for (ll i = 1; i <= n; i ++) ans &= A[i];
		printf("%lld\n",ans);
	}else if (n <= 20)
	{
		dfs(1,(1ll << 30) - 1,0);
		printf("%lld\n",sum);
	}
	else
	{
		dfs(1,(1ll << 30) - 1,0);
		printf("%lld\n",sum);
	}
	return 0;
} 
/*

 4 2
3 15 12 12

5 3
31 3 1 15 7

*/

