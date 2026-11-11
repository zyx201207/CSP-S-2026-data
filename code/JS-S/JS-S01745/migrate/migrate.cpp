#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
using namespace std;
const ll MAXN = 2000005;
ll C,T,n,d,x[MAXN],pl[MAXN],pr[MAXN],cl[MAXN],cr[MAXN];
void solve()
{
	scanf("%lld%lld",&n,&d);
	for(ll i = 1;i <= n;i++)
		scanf("%lld",&x[i]);
	for(ll i = 1,j = 1;i <= n;i++)
	{
		while(x[i] - x[j] > d) j++;
		pl[i] = j;
	}
	for(ll i = n,j = n;i;i--)
	{
		while(x[j] - x[i] > d) j--;
		pr[i] = j;
	}
	pr[0] = 0,pl[n + 1] = n + 1;
	for(ll i = 1;i < n;i++)
	{
		if(pl[i + 1] == pl[i]) cl[i] = 1;
		else cl[i] = cl[pl[i]] + pl[i + 1] - pl[i];
	}
	for(ll i = n;i > 1;i--)
	{
		if(pr[i - 1] == pr[i]) cr[i] = 1;
		else cr[i] = cr[pr[i]] + pr[i] - pr[i - 1];
	}
	ll ans = 0;
	for(ll i = 2;i + 2 <= n;i++)
	{
		if(pr[i] > max(i + 1,pr[i - 1]) && pl[i + 1] < min(i,pl[i + 2]))
		{
			ll vr = pr[i] - max(i + 1,pr[i - 1]) + cr[pr[i]] - 1;
			if(pr[i + 1] > pr[i]) vr = pr[i] - max(i + 1,pr[i - 1]);
			ll vl = min(i,pl[i + 2]) - pl[i + 1] + cl[pl[i + 1]] - 1;
			if(pl[i] < pl[i + 1]) vl = min(i,pl[i + 2]) - pl[i + 1];
			ans += vl * vr;
			//cerr<<i<<" "<<vl<<" "<<vr<<endl;
		}
	}
	printf("%lld\n",ans);
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&C,&T);
	while(T--) solve();
	return 0;
}