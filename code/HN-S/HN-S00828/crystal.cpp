#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],qzh[500005];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int y=1,ans=0;
	for(int i=1;i<=n;i++)
	{
		qzh[i]=qzh[i-1]+a[i];
		while(a[i]*(i-y+1)-(qzh[i]-qzh[y-1])>m)
		{
			y++;
		}
		ans=max(ans,i-y+1);
	}
	cout<<ans;
	return 0;
}
