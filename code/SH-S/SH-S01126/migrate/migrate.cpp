#include <bits/stdc++.h>
using namespace std;
#define int long long
int ans=0;
int a[2000005];
void solve()
{
	int n,d;
	cin >> n >> d;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	int cha=a[2]-a[1];
	if((d>=cha&&d<cha*2)||cha>=d)
	{
		cout << 0 << endl;
		return;
	}
	else
	{
		cout << n-3 << endl;
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--)
	{
		solve();
	}
	return 0;
 } 
