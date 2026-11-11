#include<bits/stdc++.h>
using namespace std;
long long x[10000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		long long n,d;
		cin>>n>>d;
		for(int j=1;j<=n;j++)
		{
			cin>>x[j];
		}
	}
	return 0;
}
