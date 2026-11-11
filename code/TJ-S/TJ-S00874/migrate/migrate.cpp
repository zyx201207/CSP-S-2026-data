#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long a[2000006];
int dao[2000006];/**/
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=0,t=0,n=0,l1=0;
	long long d,ans;
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			dao[i]=0;
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]-a[i]<=d)
					dao[i]++;
				else
					break;
			}
		}
		l1=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1)
				l1++;
			if(a[i]>=2)
			{
				ans+=(l1+1);
				l1=0;
			}
		}
		cout<<ans<<endl;
	}/**/
	return 0;
}
