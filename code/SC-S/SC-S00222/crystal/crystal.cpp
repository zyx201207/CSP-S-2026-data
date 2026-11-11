#include<bits/stdc++.h>
#define LL long long
#define IC ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
const LL N=5e5+5,inf=0x3f3f3f3f3f3f3f3f;
LL n,m,ans;
LL a[N],s[N];
bool check(LL mid)
{
	LL Min=inf;
	for(LL l=1;l<=n-mid+1;l++)
	{
		LL r=l+mid-1;
		Min=min(Min,a[r]*mid-s[r]+s[l-1]);
		if(Min<=m) return 1;
	}
	return Min<=m;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	IC
	cin>>n>>m;
	for(LL i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(LL i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
	}
	LL l=1,r=n;
	while(l<=r)
	{
		LL mid=l+((r-l)>>1);
		if(check(mid))
		{
			l=mid+1;
			ans=mid;
		}
		else r=mid-1;
	}
	cout<<ans;
	return 0;	
} 