#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e5+10;
int n,m;
int a[N],sum[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==a[i+1])
			continue;
		int l=1,r=i,tmp=0;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if((i-mid+1)*a[i]-(sum[i]-sum[mid-1])<=m)
				r=mid-1,tmp=mid;
			else
				l=mid+1;
		}
		ans=max(ans,i-tmp+1);
	}
	cout<<ans<<"\n";
	return 0;
}