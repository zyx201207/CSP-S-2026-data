#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
const int INF=1e18+7;
int n,m,a[N],sum[N];
bool check(int x)
{
	int cnt=INF;
	for(int i=x;i<=n;i++)
		cnt=min(cnt,a[i]*x-sum[i]+sum[i-x]);
	return cnt<=m;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	int l=1,r=n,mid,ans=-1;
	while(l<=r)
	{
		mid=l+r>>1;
		if(check(mid))
			l=mid+1,ans=mid;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
