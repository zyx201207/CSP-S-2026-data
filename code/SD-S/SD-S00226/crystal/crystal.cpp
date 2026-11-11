#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
const int N=5e5+50;
int a[N],s[N];
int n,m;
inline bool check(int l,int r,int x)
{
	return a[r]*(r-l)-s[r-1]+s[l-1]<=m;
}
inline int getans(int x,int p)
{
	int l=1,r=p,ans=p;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid,p,x))
		{
			ans=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	return p-ans+1;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int ans=1;
	for(int i=1;i<=n;i++)
		ans=max(ans,getans(a[i],i));
	cout<<ans;
	return 0;
}
