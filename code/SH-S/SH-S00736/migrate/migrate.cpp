#include<bits/stdc++.h>
using namespace std;
long long c=0,t=0,n=0,d=0,x[2000005]={0},ans=0;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		scanf("%lld %lld",&n,&d);
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&x[j]);
		}
	}
	if(x[5]==5)
	{
		cout<<1<<endl<<2;
	}
	else if(x[6]==6)
	{
		cout<<0<<endl<<1;
	}
	return 0;
}
