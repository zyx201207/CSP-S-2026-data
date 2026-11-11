#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e5 + 5;
int c,t;

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		int ans = 0;
		int n,d;
		int a[N],between = 0;
		cin>>n>>d;
		for(int j = 1;j <= n; j++)
		{
			cin>>a[j];
		}
		between = a[n] - a[n - 1];
		if(2 * between > d || between > d || d > 3 * between)
		{
			cout<<0<<'\n';
			continue;
		}
		for(int i = 1;i <= n - 3; i++)
		{
			if(d >= 2 * between && d < 3 * between)
			{
				ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
