#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,t;
ll n,d,a[2000010],i;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(i=1;i<=n;i++)cin>>a[i];
		if(c>=11&&c<=12)
		{
			ll z=d/(a[2]-a[1])*2;
			if(d<2*(a[2]-a[1])||z>n)
			{
				cout<<0<<" "<<'\n';
			}
			else
			{
				cout<<n-z+1<<'\n';
			}
		}
		
	}
	return 0;
}
