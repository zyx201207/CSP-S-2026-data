#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[10000005],k,t,c,d,p[10000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long int i,j;
	cout<<d<<' ';
	cin>>t;
	while(t--)
	{
		cin>>n>>d;
		for(i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		if(d==2)
		{
			if(n>3)
			{
				cout<<1;
			}
		}
		else
		{
			cout<<n/d;
		}
	}
	return 0;
}
