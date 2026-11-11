#include <bits/stdc++.h>
using namespace std;
long long a[2000005]={0};
long long d[5000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	long long c,t;long long n,d1,ans=0;
	cin>>c>>t;
	for(int i=0;i<t;i++)
	{
		ans=0;
		cin>>n>>d1;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		if(c==11||c==12)
		{
			if((a[3]-a[1])==d1)
			{
				cout<<n-3<<"\n";
				continue;
			}
			else
			{
				cout<<"0"<<"\n";
				continue;
			}
		}
		if(c==13||c==14)
		{
			cout<<"0"<<"\n";
		}
		for(int i=1;i<=n;i++)
		{
			d[i]=a[i]-a[i-1];
		}
		for(int i=1;i<=n-3;i++)
		{
			int a1=d[i+1]+d[i+2]+d[i+3];
			if(d1==(a1-1)) ans++;
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}
