#include<bits/stdc++.h>
using namespace std;
#define int long long  
int n,m;
const int N=500005;
int a[N],sum[N];
int ans=0;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
//		sum[i]=sum[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) {
		sum[i]=sum[i-1] +a[i];
	}
	int j=1;
	for(int i=1;i<=n;i++) {
		while(j<i &&  a[i]*(i-j+1) -(sum[i]-sum[j-1]) >m) {
			j++;
		}
		ans=max(ans,i-j+1);
	}
	// if j==i
	printf("%lld",ans);
	return 0;
}
