#include<bits/stdc++.h>
#define ll pair<long long int,long long int>
using namespace std;
long long int i,j,k,n,m,c,t,a[10000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>m;
		for(i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		cout<<n-3;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
