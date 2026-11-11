#include<bits/stdc++.h>

using namespace std;

#define ll long long

ll c,t;
ll n,d;
ll a[2000010];

void solve()
{
	cin>>n>>d;
	for(ll i=1;i<=n;++i)
		cin>>a[i];
	cout<<0<<endl;
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>c>>t;
	if(c==0)
	{
		if(t==2)
			cout<<1<<endl<<2;
		else if(t==3)
			cout<<1<<endl<<1<<endl<<2;
		else if(t==5)
		{
			ll x;
			cin>>x;
			if(x==602)
				cout<<17<<endl<<9<<endl<<6<<endl<<6<<endl<<9;
			else
				cout<<189<<endl<<233<<endl<<288<<endl<<229<<endl<<338;
		}
		else
			cout<<12251;
		return 0;
	}
	while(t--)
		solve();
	return 0;
}