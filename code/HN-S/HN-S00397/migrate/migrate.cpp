#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000005],ans,k,u,y;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=c;i++)
	{
		cin>>n>>d;
		memset(x,0,sizeof(x));
		for(int j=1;j<=n;j++)cin>>x[i];
		if(d<x[1])
		{
			cout<<0<<endl;
			break;
		}
		k=d/x[1];
		u=(n-1)/k;
		y=(n-1)%k;
		if(y==0)
		{
			ans=(u-1)*(k-1)*(n-2-k)+1;
		}
		else
		{
			ans=(u-1)*(k-1)*(n-2-y-k)+y*(n-2-y-k-y);
		}
		cout<<ans<<endl;
	}
	return 0;
}
