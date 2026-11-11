#include<bits/stdc++.h>
using namespace std;
const signed N=0;
int c,t,n,d;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1,a;i<=n;i++)cin>>a;
		cout<<n/d<<"\n";
	}
	return 0;
}
