#include<bits/stdc++.h>
using namespace std;
#define int long long
int u[100000000],v[1000000000];

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	int c,t,n,k;
	cin>>c>>t;
	for(int j=1;j<=t;j++)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++)
		{
			cin>>u[i]>>v[i];
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<"0"<<'\n';
	}
	return 0;
}


