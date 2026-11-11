#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,a[200006];
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		int n,m;
		cin>>n>>m;
		bool qw=0;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j];
			if(a[j]-a[j-1]>m&&qw==0)
			{
				n=j-1;
				qw=1;
			}
		}
		long long qs=0;
		for(int j=1;j<n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				int qa=0;
				for(int l=j+1;l<k;l++)
				{
					if(a[k]-a[l]<=m&&a[l]-a[j]<=m)
					{
						qa++;
					}
				}
				if(qa==2)
				{
					qs++;
				}
			}
		}
		cout<<qs<<endl;
	}
}