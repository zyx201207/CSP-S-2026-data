#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,a[5000005],n,d;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		memset(a,0,sizeof(a));
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		int cha=a[2]-a[1];
		if(cha>=d)
		{
			cout<<0<<endl;
			continue;
		}
		d/=cha;
		int f=d+d-1;
		cout<<max(n-f,0ll)<<endl;
	}
	return 0;
}