#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int ans;
int a[555555];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int now=0,sum=0;
	for (int i=1,j=1;i<=n;i++)
	{
		sum+=now*(a[i]-a[i-1]);
		now++;
		while (j<=i&&sum>m)
		{
			sum-=(a[i]-a[j]);
			j++;
			now--;
		}
		ans=max(ans,now);
	}
	cout<<ans;
	return 0;
}