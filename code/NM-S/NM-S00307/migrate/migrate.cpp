#include <bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t,n;
long long d,x[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>n>>d;
		for (int j=1;j<=n;j++)
		{
			cin>>x[j];
		}
		if (d>=abs(x[n]-x[1])) cout<<0;
		else cout<<1;
		if (i<t) cout<<"\n";
	}
	return 0;
}
