#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2000005;
ll T,c,n,d,x[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&x[i]);
		}
		ll cha=x[2]-x[1];
		if(2*cha>d)
		{
			cout<<"0\n";
			continue;
		}
		else
		{
			ll duan=d/cha;
			ll ans=max(0LL,n-2*duan+1);
			cout<<ans<<"\n";
			continue;
		}
	}
	return 0;
}
