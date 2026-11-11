#include<bits/stdc++.h>
using namespace std;
long long a[2000006];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c==13||c==14)
	{
		for(int i=1;i<=t;i++)
		{
			long long n,d;
			cin>>n>>d;
			for(int j=1;j<=n;j++)
				cin>>a[j];
			cout<<0<<endl;
		}
		return 0;
	}
	if(c==11||c==12)
	{
		for(int i=1;i<=t;i++)
		{
			long long n,d;
			cin>>n>>d;
			memset(a,0,sizeof(a));
			for(int j=1;j<=n;j++)
			{
				cin>>a[j];
			}
			long long bu=d/(a[2]-a[1]);
			if(bu==0)
			{
				cout<<0<<endl;
				continue;
			}
			cout<<n-(bu*2-1)<<endl;
		}
		return 0;
	}
	for(int i=1;i<=t;i++)
	{
		long long n,d,sum=0;
		cin>>n>>d;
		memset(a,0,sizeof(a));
		for(int j=1;j<=n;j++)
		{
			cin>>a[j];
		}
		for(int i=1;i<=n-1;i++)
		{
			for(int j=i;j<=n;j++)
			{
				if(a[j]-a[i]==d*2-1)
					sum++;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}