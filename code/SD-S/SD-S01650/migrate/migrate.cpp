#include <bits/stdc++.h>
using namespace std;
long long a[20005],b[20005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t,n,d;
	cin>>c>>t;
	for(int k=1;k<=t;k++)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		if(a[n]-a[1]<=d)
		{
			cout<<"0"<<endl;
			continue;
		}
		else
		{
			for(int i=1;i<n;i++)
			{
				if(a[i]-a[i-1]>d&&a[i+1]-a[i]>d)
				{
					b[i]=1;
				}
			}
			if((a[n]-a[1])/d&&b[n]!=1&&b[1]!=1)
			{
				cout<<(a[n]-a[1])/2<<endl;
				continue;
			}
			else
			{
				if((a[n-1]-a[1])/d&&b[n-1]!=1&&b[1]!=1)
				{
					cout<<(a[n-1]-a[1])/2<<endl;
					continue;
				}
				else
				{
					if((a[n-1]-a[2])/d&&b[n-1]!=1&&b[2]!=1)
					{
						cout<<(a[n-1]-a[2])/2<<endl;
						continue;
					}
					else
					{
						if((a[n]-a[2])/d&&b[n]!=1&&b[2]!=1)
						{
							cout<<(a[n]-a[2])/2<<endl;
							continue;
						}
					}
				}
			}
		}
	}
	return 0;
}
