#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 5;
int c,t;
int a[N] = {};
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while (t--)
	{
		int n,d;
		cin>>n>>d;
		memset(a,n+1,0);
		int cnt = 0;
		if (d!=2)
		{
			for (int i=1;i<=n;i++)
			{
				cin>>a[i];
			}
			for (int i=1;i+2<=n;i++)
			{
				if (a[i+2]-a[i] == d)
				{
					cnt++;
				}
			}
			cout<<cnt<<"\n";
		}
		else
		{
			for (int i=1;i<=n;i++)
			{
				cin>>a[i];
			}
			for (int i=1;i+3<=n;i++)
			{
				if (a[i]==a[i+1]-1&&a[i]==a[i+2]-2&&a[i]==a[i+3]-3)
				{
					cnt++;
				}
			}
			cout<<cnt<<"\n";
		}
	}
	return 0;
}
