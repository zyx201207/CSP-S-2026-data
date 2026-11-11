#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5e5 + 5;
ll n,m,a[N],b[N];
bool check(ll x)
{
	for(ll i = 1;i <= n - x + 1;i++)
	{
		ll j = i + x - 1;//幸好a[i] <= 1e12 不然就爆long long 了 
		ll w = (j - i) * a[j] - (b[j - 1] - b[i - 1]);
//		cout << i << " " << j << " " << w <<<< '\n'; 
		if(w <= m)
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i = 1;i <= n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a + 1,a + n + 1);
	for(ll i = 1;i <= n;i++)
	{
		b[i] = b[i - 1] + a[i];
	}
	ll l = 1,r = n + 1,mid;
	while(l < r)
	{
		mid = (l + r) >> 1;
		if(check(mid))
		{
			l = mid + 1; 
		} 
		else
		{
			r = mid;
		}
	}
//	printf("%lld",r - 1);
	for(ll i = min(n,r + 1);i >= max(1ll,l - 1);i--) 
	{
		if(check(i))
		{
			printf("%lld",i);
			return 0;
		}
	}
	return 0;
}
