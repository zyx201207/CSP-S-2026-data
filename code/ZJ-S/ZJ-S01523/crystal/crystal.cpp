#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,t,w,mid,m,i,ans,s,cnt,j,a[500010],sum[500010];
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	for(i=1;i<=n;i++)
	{
		s=0;cnt=0;
		t=1;w=i-1;
		while(t<=w)
		{
			mid=(t+w)/2;
			if(mid*a[i]-(sum[i-1]-sum[i-mid-1])<=m)cnt=mid,t=mid+1;
			else w=mid-1;
		}
		ans=max(ans,cnt+1);
	}
	cout<<ans;
}
