/*
Calm down and trust yourself, control the match in your pace.
*/
#include<bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define int long long
#define I using
#define AK namespace
#define CSPS2026 std
I AK CSPS2026;
const int maxn=5e5+10,maxm=1e3+10,mod=998244353,inf=1e18;
int t,n,m,x,y,z,u,v,w,ans,arr[maxn],sum[maxn],pre[maxn];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	FastIO;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>arr[i];
	sort(arr+1,arr+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+arr[i];
	int l=1,r=1;
	while(r<=n)
	{
		if(arr[r]*(r-l+1)-(sum[r]-sum[l-1])<=m)
		{
			ans=max(ans,r-l+1);
			r++;
		}
		else
		{
			l++;
			ans=max(ans,r-l+1);
		}
	}
	cout<<ans;
	return 0;
}
/*
14:44 pass!!!
*/

