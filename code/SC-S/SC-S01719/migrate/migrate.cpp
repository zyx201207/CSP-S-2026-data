#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 2e6+56;
ll x[N];
ll dis[N];
ll n,d;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c,_;
	cin >> c>> _;
	while(_--)	
	{
		memset(x,0,sizeof(x));
		cin >> n >> d;
		for(int i = 1; i <= n ;i++)
		{
			cin >> x[i];
		}
		ll gc = x[2]-x[1];
		if(gc > d/2) cout<<0<<"\n";
		else
		{
			ll ans = 0;
			for(int i = d/gc+2; i <= d/gc*2;i++) ans += n-i+1;
			cout<<ans<<"\n";
		}
	}
	return 0;
	
	
	
}