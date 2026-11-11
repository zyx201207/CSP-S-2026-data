#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005],qzh[500005];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)cin >> a[i];
	sort(a+1,a+n+1);
	for(int i = 1; i <= n; i++)qzh[i]=qzh[i-1]+a[i];
	int l=1,r=1,tot,ans=0;
	while(l<=r&&r<=n)
	{
		tot=a[r]*(r-l)-(qzh[r-1]-qzh[l-1]);
		if(tot<=m)
		{
			ans=max(ans,r-l+1);
			r++;
		}
		else l++;
	}
	cout << ans;
	return 0;
}
