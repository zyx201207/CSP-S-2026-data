# include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
int c,t,a[N];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--)
	{
		int n,d;
		cin>>n>>d;
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			cnt=a[i]-a[i-1];
		}
		if((d/cnt)<2||(d==0))
		{
			cout<<0<<endl;
		}
		else
		{
			int ans=n-(d/cnt)*2+1;
			if(ans<0)
			{
				ans=0;
			}
			cout<<ans<<endl;
		}
	}
}
