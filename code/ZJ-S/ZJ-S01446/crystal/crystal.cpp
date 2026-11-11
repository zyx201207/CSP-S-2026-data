#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans,a[500005],q[500005];
bool check(int x,int y)
{
	if((y-x+1)*a[y]-(q[y]-q[x-1])<=m) return true;
	else return false;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)
		q[i]=q[i-1]+a[i];
	for(int i=1;i<=n;++i)
	{
		int l=1,r=i+1,d=0;
		while(l<r)
		{
			int mid=l+((r-l)>>1);
			if(!check(mid,i)){
				l=mid+1;
			}
			else
			{
				r=mid;
				d=mid;
			}
		}
		ans=max(ans,i-d+1);
	}
	cout<<ans;
	return 0;
}
