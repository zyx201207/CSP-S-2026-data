#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t,n,d;
ll a[20000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(ll i=1;i<=n;i++) cin>>a[i];
		ll z=a[2]-a[1];
		if(d<z) {
			cout<<0<<'\n';
			continue;
		}
		ll w=d/z;
		if(w==1) {
			cout<<0<<'\n';
			continue;
		}
		else cout<<max(0ll,n-2*w+1)<<'\n';
	}
	return 0;
}

