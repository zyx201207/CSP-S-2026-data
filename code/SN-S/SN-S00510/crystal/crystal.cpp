//徐语瞳 SN-S00510 西安翱翔中学
#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
long long m,a[500005],sum[500005];
bool check(int id1,int id2)
{
	long long x=sum[id2]-sum[id1-1],y=1ll*a[id2]*(id2-id1+1);
	if(y-x<=m) return 1;
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i,ls;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(check(mid,i)) ls=mid,r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-ls+1);
	}
	cout<<ans<<"\n";
	return 0;
}
