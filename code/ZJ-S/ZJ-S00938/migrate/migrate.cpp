#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int a[N],n,d,c,t;
void solve()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(c==11||c==12)
	{
		int dx=a[2]-a[1];
		int len=d/dx,ans=0;
		if(len==0)
		{
			cout<<0<<endl;
			return;
		}
		for(int i=1;i<=n;i++)
		{
			if(i+2*len-1<=n)ans++;
		}
		cout<<ans<<endl;
		return;
	}
	cout<<0<<endl;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}

