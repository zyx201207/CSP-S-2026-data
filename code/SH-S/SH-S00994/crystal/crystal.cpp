#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int n,m;
int a[N] = {};
int b[N] = {};
int sum[N] = {};
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	srand(time(0));
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for (int i=2;i<=n;i++)
	{
		b[i-1] = a[i] - a[i-1];
	}
	int ans = -1e3;
	for (int i=1;i<=n-1;i++)
	{
		sum[i] = sum[i-1]+b[i]*i;
	}
	if (m>sum[n-1]) 
	{
		cout<<n;
		return 0;
	}
	for (int i=1;i<=n-1;i++)
	{
		if (sum[i]>m)
		{
			if (i>ans)
			{
				ans = i;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
