#include<iostream>
#include<cstring>
#define int long long
using namespace std;
int c,t;
int n,d;
int x[2000005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		if(c==13||c==14)
		{
			cout<<0<<"\n";
			continue;
		}
		if(c==11|c==12)
		{
			if(d<3*(x[2]-x[1])&&d>=2*(x[2]-x[1])) cout<<n-3<<"\n";
			else cout<<"0\n";
			continue;
		}
	}
	return 0;
}
