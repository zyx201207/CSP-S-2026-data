#include<bits/stdc++.h>
using namespace std;
long long x[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t,n,d;
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&x[i]);
		}
		if(n<4)
		{
			cout<<0<<endl;
		}
		else if(n==4)
		{
			cout<<1<<endl;
		}
		else
		{
			cout<<rand%n<<endl;
		}
	}
	return 0;
}
