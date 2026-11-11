#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[500005],m,cnt,l,r,ans;
signed main()
{
	cin.sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	l = 1,r = 1;
	for(;r <= n;r++)
	{
		cnt += (r-l) * (a[r]-a[r-1]);
		while(cnt>m)
		{
			cnt -= a[r]-a[l];
			l++;
		}
		ans = max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
