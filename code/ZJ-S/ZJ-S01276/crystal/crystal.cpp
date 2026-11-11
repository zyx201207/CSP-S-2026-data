#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,ans,a[N],sum[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i,cnt=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if(abs(a[i]*(i-mid+1)-(sum[i]-sum[mid-1]))<=m)r=mid-1,cnt=mid;
			else l=mid+1;
		}
		ans=max(ans,i-cnt+1);
	}
	printf("%lld",ans);
	return 0;
}
/*
5 5
1 2 4 8 9
*/
