#include<bits/stdc++.h>
using namespace std;
long long a[500009],sum1=0,ans=0,sum2=0;
int n,t,d;
void flag()
{
	for(int i=1;i<=n-3;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[j]-a[i]>=2*d) break;
			for(int x=i+1;x<j;x++)
			{
				if(a[x]-a[i]<=d&&a[j]-a[x]<=d&&(a[x]-a[i]==d||a[j]-a[x]==d))
				{
					if(sum1) sum2=1;
					else sum1=1;
				}
			}
			if(sum1&&sum2) ans++;
		}
	}
	
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int gunmu;
	cin>>gunmu>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>d;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j];
		}
		flag();
		cout<<ans<<"\n";
		ans=0;
	}
	return 0;
}
