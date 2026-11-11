#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=500010;
int n;
ll a[N],m,s[N];
bool b=1;
void solve1()
{
	int dis=a[2]-a[1];
	int l=1,r=n,mid,ans;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(mid*(mid+1)/2*dis<=m) ans=mid+1,l=mid+1;
		else r=mid-1;
	}
	printf("%d",ans);
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=3;i<=n;i++) if(a[i]-a[i-1]!=a[i-1]-a[i-2]) b=0;
	if(b)
	{
		solve1();
		return 0;
	}
	sort(a+1,a+1+n);
	int ans=1;
	ll num;
	for(int i=1;i<=n;i++)
	{
		num=0ll;
		for(int j=i-1;j>=1;j--)
		{
			num+=a[i]-a[j];
			if(num>m)
				break;
			ans=max(ans,i-j+1);
		}
	}
	printf("%d",ans);
	return 0;
}


