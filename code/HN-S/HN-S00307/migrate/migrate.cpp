#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int a[2000020];
void solve()
{
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+d;j<=n;j++)
		{
			if(a[j]-a[j-1]>d)break;
			ans++;
		}
	}
	cout<<ans/(d+1)<<endl;
}

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
