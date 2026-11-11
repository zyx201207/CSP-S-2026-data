#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,t,x[2000000],ans;
int main()
{
	freeopen("migrate.in","r",stdin);
	freeopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int q=0;q<t-1;q++)
	{
		ans=0;
		cin>>n>>d;
		for(int w=0;w<n;w++)cin>>x[w];
		for(int w=0;w<n-3;w++)
		{
			int e=w+3;
			if(x[e]-x[w]<2*d&&x[e-1]-x[w]<=d&&x[e-2]-x[w]<=d)ans++;
		}
		cout<<ans;
	}
	ans=0;
	cin>>n>>d;
	for(int w=0;w<n;w++)cin>>x[w];
	for(int w=0;w<n-3;w++)
	{
		int e=w+3;
		if(x[e]-x[w]<2*d&&x[e-1]-x[w]<=d&&x[e-2]-x[w]<=d)ans++;
	}
	cout<<ans;
	return 0;
}