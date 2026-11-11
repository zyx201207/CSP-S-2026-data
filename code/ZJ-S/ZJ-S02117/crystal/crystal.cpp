#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+3;
int n,m,a[N],ans,l,r,s[N],t,w,f;
bool check(int mid)
{
	t=1;w=mid;
	while(w<=n&&t<=w)
	{
		int z=a[w]*mid;
		int sum=s[w]-s[t-1];
		if(z-sum<=m)return 1;
		t++;w++;
	}
	return 0;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	int minn=1e12;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		minn=min(minn,a[i]);
	}
	for(int i=3;i<=n;i++)
		if(a[i]-a[i-1]!=a[i-1]-a[i-2])
		{
			f=1;
			break;
		}
	if(f)sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	l=1;r=n;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid))
		{
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<ans;
}