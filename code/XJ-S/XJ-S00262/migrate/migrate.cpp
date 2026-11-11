#include<bits/stdc++.h>
using namespace std;
int x[10005],y[10005],n1[1005],d1[1005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d,sum=0;
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n1[i]>>d1[i];
		for(int j=1;j<=n1[i];j++)
		{
			cin>>x[j];
			for(int a=n;a>=1;a--)
			{
				if((x[a]-x[j])%2!=0)
			{
				sum++;
			}
	}
		}
	}
	cout<<sum;
	return 0;	
}
