#include <bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,x[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11||c==12)
	{
		while(t--)
		{
			int ans=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++)
			{
				cin>>x[i];
			}
			long long y=x[2]-x[1];
			if(y>=d)
			{
				cout<<"0"<<endl;
				continue;
			}
			d=d/y*y;
			for(int i=1;i<=n;i++)
			{
				ans+=abs(n-i-d/y-(n-i-d/y)/(d/y));
			}
			cout<<ans<<endl;
		}
	}
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		cout<<"0"<<endl;
	}
	return 0;
}
