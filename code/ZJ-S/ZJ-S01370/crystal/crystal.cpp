#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int n,ans=1;
long long m,a[maxn],q[maxn];
inline bool check(int x)
{
	for(int i=x;i<=n;i++)
	  if(a[i]*x-q[i]+q[i-x]<=m)
		return true;
	return false;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
	  scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	  q[i]=q[i-1]+a[i];
	int l=2,r=n;
	while(l<=r)
	  {
	  	int mid=(l+r)>>1;
	  	if(check(mid))
	  	  ans=mid,l=mid+1;
	  	else
	  	  r=mid-1;
	  }
	printf("%d",ans);
	return 0;
}
