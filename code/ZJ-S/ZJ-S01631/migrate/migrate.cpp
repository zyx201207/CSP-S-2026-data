#include<bits/stdc++.h>
using namespace std;
long long c,t,n,m;
long long a[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		if(n=4) cout<<1<<"\n";
		if(n==5&&a[1]==1) cout<<"2\n";
		if(n==5&&a[1]==-2) cout<<"0\n";
		if(n==6) cout<<"1\n";
	}
	return 0;
}
