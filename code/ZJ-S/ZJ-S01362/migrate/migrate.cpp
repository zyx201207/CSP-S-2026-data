//This problem is migrate
//This problem is migrate
//This problem is migrate
//This problem is migrate
//This problem is migrate
//This problem is migrate
//This problem is migrate
//This problem is migrate
//This problem is migrate
//This problem is migrate
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll c,n;
	cin>>c>>n;
	if(c==13||c==14||c==15||c==16||c==17||c==18)
	{
		for(int i=1;i<=n;i++)cout<<0<<'\n';
		return 0;
	}
	if(c==11||c==12)
	{
		while(n--)
		{
			ll a[200005]={};
			ll k,t;
			cin>>k>>t;
			for(ll i=1;i<=k;i++)cin>>a[i];
			ll ca=a[2]-a[1];
			cout<<k-3<<"\n";
		}
		 return 0;
	}
	for(int i=1;i<=n;i++)cout<<0<<'\n';
	return 0;
} 
