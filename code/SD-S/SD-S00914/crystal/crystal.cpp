#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],ans,p[N],val;
int l,r;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	stable_sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		p[i]=a[i]-a[i-1];
	}
	l=1;r=1;
	while(l<=r&&r<=n)
	{
		while(val+p[r+1]*(r-l+1)<=m&&r+1<=n)
		{
			val+=p[r+1]*(r-l+1);r++;
//			cout<<"gengxin:"<<l<<' '<<r<<' '<<val<<'\n';
		}
		ans=max(ans,r-l+1);
//		cout<<l<<' '<<r<<' '<<ans<<'\n'<<'\n';
		l++;
		val-=a[r]-a[l-1];
	}
	cout<<ans;
	return 0;
}
