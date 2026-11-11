#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+7;
ll x[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	ll c,t;
	cin>>c>>t;
	while(t--)
	{
		ll n,d;
		cin>>n>>d;
		for(int i=0;i<n;i++) cin>>x[i];
		if(x[1]-x[0]<=d) cout<<n/2<<endl;
		else cout<<0<<endl;
	}
	return 0;
}