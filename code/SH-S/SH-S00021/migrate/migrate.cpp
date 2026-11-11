#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M=2e6+50;
ll x[M];
ll a[M];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll c,T;
	cin>>c>>T;
	ll t=T;
	while(T--)
	{
		ll n,d;
		cin>>n>>d;
		for(ll i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		a[T]=(n/d)%3;
	}
	for(ll i=1;i<=t;i++)
	{
		cout<<a[i]<<'\n';
	}
}/*0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
