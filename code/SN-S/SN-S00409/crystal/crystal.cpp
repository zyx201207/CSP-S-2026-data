#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+7;
int a[N],sum[N];
int ans = 0;
int now = 0;
int l = 1;
int n,m;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i<=n;i++) sum[i] = sum[i-1]+a[i];
	for(int i = 1;i<=n;i++)
	{
		now = (i-l+1)*a[i]-(sum[i]-sum[l-1]);
		if(now<=m)
		{
			ans = max(ans,i-l+1);
		} 
		else
		{
			while(1)
			{
				now-=a[i]-a[l];
				l++;
				if(now<=m) break;
			}
			ans = max(ans,i-l+1);
		}
	}
	cout<<ans<<"\n";
	return 0;
}
