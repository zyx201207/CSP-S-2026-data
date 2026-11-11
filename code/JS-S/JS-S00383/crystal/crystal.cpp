#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define req(i,a,b) for(int i=(a);i>=(b);i--)
#define int long long
#define ll __int128
#define MAXN 500005
int n,m;
int a[MAXN];
int s[MAXN];
bool check(int len)
{
	ll v;
	int l,r;
	rep(i,1,n-len+1)
	{
		l=i,r=i+len-1;
		v=(ll)a[r]*(r-l+1)-((ll)s[r]-(ll)s[l-1]);
		if(v<=m) return 1;
	}
	return 0;
}
signed main()
{
	FAST_IO;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	rep(i,1,n) cin>>a[i];
	sort(a+1,a+n+1);
	rep(i,1,n) s[i]=s[i-1]+a[i];
	int l=1,r=n,mid,ans=-1;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans<<'\n';
	return 0;
}
