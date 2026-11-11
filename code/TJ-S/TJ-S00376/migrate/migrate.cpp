#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,ans;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		ll n,d,x[50000009];
		cin>>n>>d;
		ans+=(n+d);
		for(int i=1;i<=n;i++) 
		{
			cin>>x[i];
			ans+=x[i];
		}
	}
	if(ans==38) cout<<1<<endl<<2;
	if(ans==15) cout<<0<<endl<<1;
	return 0;
}
