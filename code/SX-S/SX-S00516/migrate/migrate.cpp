#include<bits/stdc++.h>
using namespace std;
int c;
long long t,n,d,x[10000000];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n>>d;
		for(int j=1;j<=n;j++)
		{
			cin>>x[j];
		}
		if(n<=3)
		{
			cout<<0;
			continue;
		}
		if(x[2]-x[1]>d/2)
		{
			cout<<0;
			continue;
		}
		else
		{
			cout<<x[n]/(2*d);
			continue;
		}
		/*for(int j=1;j<=n;j++)
		{
			cin>>x[j][0];
		}
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				if(x[j][0]+d>x[k][0])
				{

				}
			}
		}*/
	}
	return 0;
}