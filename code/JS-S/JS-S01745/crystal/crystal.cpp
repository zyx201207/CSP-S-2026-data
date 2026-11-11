#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const ll MAXN = 500005;
ll n,m,a[MAXN],s[MAXN];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i = 1;i <= n;i++)
		scanf("%lld",&a[i]);
	sort(a + 1,a + 1 + n);
	for(ll i = 1;i <= n;i++)
		s[i] = s[i - 1] + a[i];
	ll ans = 0;
	for(ll i = 1,j = 1;i <= n;i++)
	{
		while((i - j + 1) * a[i] - (s[i] - s[j - 1]) > m) j++;
		ans = max(ans,i - j + 1);
	}
	printf("%lld\n",ans);
	return 0;
}