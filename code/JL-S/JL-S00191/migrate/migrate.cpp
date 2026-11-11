#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	c=(c==0) ? 1 : c;
	for(long long i=0;i<c;i++)
	{
		long long num[1000000];
		for(long long j=0;j<t;j++)
		{
			long long n,d;
			cin>>n>>d;
			for(long long x=0;x<n;x++)
				cin>>num[x];
			if(d==1)
			{
				cout<<0<<endl;
				continue;
			}
			if(d==2)
			{
				cout<<ceil(n*1.0/d)-1<<endl;
				continue;
			}
			cout<<1<<endl;
		}
	}
	return 0;
}
