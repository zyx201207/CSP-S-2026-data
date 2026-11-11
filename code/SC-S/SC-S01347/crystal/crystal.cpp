#include<bits/stdc++.h>
#define LL long long
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define dow(i,j,k) for(int i=j;i>=k;i++)
using namespace std;
const int N=5e5+5;
int n,m,ans;
LL a[N],sum;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	rep(i,1,n) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	int l=1;
	rep(r,1,n)
	{
		sum+=(r-l)*(a[r]-a[r-1]);
		while(sum>m) sum-=(a[r]-a[l]),l++;
		ans=max(ans,r-l+1);
	}
	printf("%d",ans);
	return 0;
}