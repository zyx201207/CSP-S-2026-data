#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,d,a[1000005],minn=INT_MAX;
void solve()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(i>=j)
				continue;
			if(abs(a[i]-a[j])<=d)
			{
				minn=min(minn,abs(a[i]-a[j]));
				break;
			}
			else
			{
				break;
			}
		}
	}
	cout<<minn<<endl;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	
	while(t--)
	{
		solve();
	}
	return 0;
}
