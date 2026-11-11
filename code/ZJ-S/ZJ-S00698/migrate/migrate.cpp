#include<bits/stdc++.h>
#define N 2000005
using namespace std;
typedef long long ll;
ll x[N];
int main()
{
	std::ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c,T;
	cin>>c>>T;
	while(T--)
	{
		ll n,d,ans=0;
		bool flag=0;
		cin>>n>>d;
		for(ll i=1;i<=n;i++)
			cin>>x[i];
		for(ll i=1;i+3<=n;i++){
			if(x[i+3]-x[i]<=d){
				cout<<"0\n";
				flag=1;break;
			}
		}
		if(flag) continue;
		for(ll i=1;i<=n;i++)
		{
			if(x[i+1]-x[i]>d) continue;
			for(ll j=i+1;j<=n;j++)
			{
				ll y=x[j]-x[i];
				ll z=ceil((double)y/d);
				if(z*d>y&&z==2) ans++;
//				cout<<i<<"->"<<j<<" "<<z<<"\n";
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

