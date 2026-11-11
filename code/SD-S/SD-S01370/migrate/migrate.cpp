#include<bits/stdc++.h>
using namespace std;
long long c,t;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		long long ans=0;
		int n;
		long long d;
		long long a[100005];
		cin>>n>>d;
		if(n<=3)
		{
			cout<<0<<endl;
			continue;
		}
		for(int j=1;j<=n;j++)
		{
			cin>>a[j];
		}
		for(int j=1;j<=n;j++)
		{
			for(int k=j+3;k<=n;k++)
			{
				if(a[k]-a[j]>=d)
				{
					continue;
				}
				if(k-j==3)
				{
					if((a[j+1]-a[j]<=d)&&(a[k]-a[j+1]<=d)
					&&(a[j+2]-a[j]<=d)&&(a[k]-a[j+2]<=d))
					{
						ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
