#include<bits/stdc++.h>
using namespace std;
long long n,d,a[2000010],cnt,c,t;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cnt=0;
		cin>>n>>d;
		for(long long i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(long long i=1;i<=n;i++)
		{
			long long o=a[i]+d;
			if(o>=a[n])break;
			long long p=upper_bound(a,a+n,o)-a-1;
			long long k=upper_bound(a,a+n,a[p]+d)-a-1;
			if(a[p]+d>=a[n])k=n;
			for(long long j=p+1;j<=k;j++)
			{
				long long v=a[j];
				long long y=lower_bound(a,a+n,a[j]-d)-a;
				if(p-y+1==2)cnt++;
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}