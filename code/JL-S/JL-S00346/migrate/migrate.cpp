#include<bits/stdc++.h>
using namespace std;
int x[100005];
long long c,t,n,d;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		int o=0;
		cin>>n>>d;
		for(int j=1;j<=n;j++)
		{
			cin>>x[j];
		}
		for(int j=1;j<=n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				if((x[k]-x[j])/(d+d-1)==1 && k-j==3)
				{
					o++;
				}
			}
		}
		cout<<o<<"\n";
	}
}

