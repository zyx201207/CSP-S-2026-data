#include <bits/stdc++.h>
using namespace std;
long long c,t;
long long n,d;
long long loc[2000005];

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int test=1;test<=t;test++)
	{
		long long ans=0;
		cin>>n>>d;
		for(long long i=1;i<=n;i++) cin>>loc[i];
		long long dist=0,k=2;
		for(long long i=2;i<n;i++)
		{
			k=i;
			dist=0;
			while(k<=n&&dist<(d*2))
			{
				dist+=loc[k]-loc[k-1];
				k++;
			}
			k--;
			if(dist>=(d*2)) dist-=loc[k]-loc[k-1];
			if(dist>d&&dist>(d*2-2)) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
