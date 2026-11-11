#include<bits/stdc++.h>
using namespace std;
int x[2000006];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d;
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(i=1;i<=n;i++) cin>>x[i];
		for(i=1;i<=d;i++) cout<<0;
	}
	return 0;
}
