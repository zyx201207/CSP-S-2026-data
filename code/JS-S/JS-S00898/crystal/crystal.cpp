#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],f[500005];
bool check(int x)
{
	int c=x-1;
	int fl=0;
	for(int i=x;i<=n;i++)
	{
		int cnt=a[i]*c-(f[i-1]-f[i-x]);
		if(cnt<=m)
		{
			fl=1;
			break;
		}
	}
	return fl;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int tt=0-a[1];
	for(int i=1;i<=n;i++) a[i]+=tt;
	for(int i=1;i<=n;i++) f[i]=f[i-1]+a[i];
	int l=1,r=n;
	while(l<r)
	{
		int mid=(l+r+1)/2;
//		cout<<mid<<endl;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l<<endl;
	return 0;
}
