#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,d,a[200005],f[5005][5005],da=0;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c,t;
	cin>>c>>t;
	while(t--)
	{
		da=0;
		cin>>n>>d;
		for(ll i=1;i<=n;i++)
		{
			for(ll j=1;j<=n;j++) f[i][j]=0;
		}
		for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
		for(ll i=1;i<=n;i++)
		{
			for(ll j=i+1;j<=n;j++)
			{
				ll js=0;bool pd=0;
				for(ll k=i+1;k<j;k++)
				{
					for(ll z=k+1;z<j;z++)
					{
						if(k!=z&&a[k]-a[i]<=d&&a[j]-a[k]<=d&&a[z]-a[i]<=d&&a[j]-a[z]<=d) js++/*,cout<<i<<" "<<j<<""<<" "<<k<<" "<<z<<endl*/;
					}
				}
				if(js==1) da++;
			}
		}
		cout<<da<<endl;
	}
	return 0;
}
