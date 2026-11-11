#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,a[N],cnt[N],c,ans,sum[N],kc,cnt1[N],v[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
		if(i!=1&&a[i]==a[i-1]) ++cnt[c],v[i]=c;
		else
		{
			++c;
			v[i]=c;
			cnt[c]=1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(v[i]==v[i-1]) continue;
		if(a[i]-a[i-1]>m) continue;
		int l=0,r=i-1;
		while(l<r)
		{
			int mid=l+r>>1;
			int w=sum[i-1]-sum[mid-1];
			if(a[i]*(i-mid)-w<=m) r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+cnt[v[i]]);
	}
	cout<<ans;
	return 0;
}
