#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		ll n,d,x[2000001],ans=0;
		cin>>n>>d;
		for(ll i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		for(ll i=1;i<n;i++)
		{
			for(ll j=i+1;j<=n;j++)
			{
				if(x[j]-x[i]<2*d) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
