#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,t;
ll n,d;
ll a[2000010];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		memset(a,0,sizeof(a));
		ll sum=0;
		cin>>n>>d;
		for(ll i=1;i<=n;i++)
		{
			cin>>a[i];
			sum+=a[i];
		}
		if((a[1]+a[n])*n/2==sum)
		{
			for(ll i=1;i+d+1<=n;i++)
			{
				ll j=i+d+2;
				if(is_prime(d,j))
				{
					ans++;
				}
			}
			cout<<ans<<endl;
		}
	}
}
