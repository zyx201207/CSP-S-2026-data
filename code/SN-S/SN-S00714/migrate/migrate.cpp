#include <iostream>
using namespace std;
int c,t;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		int n,d;
		cin>>n>>d;
		int x[n],sum[n];
		for(int j=1;j<=n;j++)
		{
			cin>>x[j];
		}
		for(int j=n;j>=1;j--)
		{
			int k=x[j];
			for(int f=j-1;f>=1;f--)
			{
				if(k-x[f]<=d)
				{
					sum[f]++;
				}
			}
		}
	}
	return 0;
}
