#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],qzh[500005];
bool chk(int x)
{
	int mn=LLONG_MAX;
	for(int i=1;i<=n-x+1;i++)
	{
		mn=min(mn,a[i+x-1]*x-(qzh[i+x-1]-qzh[i-1]));
	}
	return mn<=m;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],qzh[i]=a[i]+qzh[i-1];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) qzh[i]=a[i]+qzh[i-1];
	int l=1,r=n,mid;
	while(l<=r)
	{
		mid=l+r>>1;
		if(chk(mid)) l=mid+1;
		else r=mid-1;
	}
	cout<<l-1;
	return 0;
}
