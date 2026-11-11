#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5； 
int c,t,n,d,x[N];
void solve()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)
		cin>>x[i];
	if(c==11||c==12)
	{
		if(d<2*(x[2]-x[1]))
			cout<<0<<'\n';
		else
			cout<<n-2<<'\n';
		return;
	}
	else if(c==13||c==14)
	{
		cout<<n-2<<'\n';
		return;
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>t;
	while(t--)
		solve();
	return 0;
}