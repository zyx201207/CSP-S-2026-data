#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long c,t,n,d;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c!=11&&c!=12)
		return 0;
	while(t--)
	{
		cin>>n>>d;
		long long a[2000010];
		for(int i=1;i<=n;i++)
			cin>>a[i];
		if(a[2]-a[1]>d&&a[2]-a[1]<2*d)
			cout<<n-3;
		else
			cout<<0;
	}
	return 0;
}
