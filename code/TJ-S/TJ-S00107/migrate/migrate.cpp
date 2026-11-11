#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(d<a[2]-a[1]) cout<<0<<endl;
		else
		{
			int len=d/(a[2]-a[1])+1;
			cout<<n-len<<endl;
		}
	}
	return 0;
}
