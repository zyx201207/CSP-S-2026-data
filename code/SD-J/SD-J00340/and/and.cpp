#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5 + 10;
const ll MOD = 998244353;
const ll inf = 9e18;
ll n,m;
ll a[N];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>n>>m;
	for(ll i = 1;i <= n;i++)
	{
		cin>>a[i];
	}
	ll ans = 0;
	for(ll i = 30;i >= 0;i--)
	{
		ll cnt = 0;
		for(ll j = 1;j <= n;j++)
		{
			if((a[j] & (1LL << i)) == (1LL << i))
			{
				cnt++;
			}
		}
		if(cnt >= m)
		{
			ans += (1LL << i); 
			for(ll j = 1;j <= n;j++)
			{
				if((a[j] & (1LL << i)) != (1LL << i))
				{
					a[j] = 0;
				}
			}
		}
	}
	
	cout<<ans;
	return 0;
}
