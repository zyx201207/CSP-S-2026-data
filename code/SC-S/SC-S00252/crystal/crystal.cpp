#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+9;
int n,m;
int a[maxn];
int sum[maxn];
bool ck(int l,int x)
{
	if(a[x]*(x-l+1)-sum[x]+sum[l-1]<=m) return 1;
	return 0;
}
int gt(int x)
{
	int l=1,r=x;
	int ans=r;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(ck(mid,x)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	return x-ans+1;
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
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int ans=0;
	//for(int i=1;i<=n;i++) cout<<gt(i)<<'\n';
	for(int i=1;i<=n;i++) ans=max(ans,gt(i));
	cout<<ans<<'\n';
	return 0;
}