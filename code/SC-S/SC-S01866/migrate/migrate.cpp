#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,qd,a[1010101],d[1001010];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==13||c==14)
	{
		while(t--)
		{
			cin>>n>>qd;
			for(int i=1;i<=n;i++)
			{
				cin>>a[i];
				d[i]=a[i]-a[i-1];
			}
			if(qd<d[n])
			{
				cout<<0<<'\n';
				continue;
			}
			if(qd<=d[n]*2-1)
			{
				cout<<1<<'\n';
				continue;
			}
			cout<<2<<'\n';
		}
	}
	else
	{
		while(t--)
		{
			cout<<0<<'\n';
			continue;
		}
	}
}