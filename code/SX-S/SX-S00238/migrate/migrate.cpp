#include<bits/stdc++.h>
using namespace std;
const int X=2e6+5;
long long c,t,n,d,a[X];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		int k=a[2]-a[1];
		if(k>=d) cout<<0<<"\n";
		else cout<<n-(d+1)<<"\n";
	}
	return 0;
}