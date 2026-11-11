#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,ans;
long long a[N],sum[N],m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i,mid=(l+r)>>1;
		while(l<r){
			if((i-mid)*a[i]-(sum[i-1]-sum[mid-1])<=m)r=mid;
			else l=mid+1;
			mid=(l+r)>>1;
		}
		//printf("%d\n",r);
		ans=max(ans,i-r+1);
	}
	printf("%d",ans);
	return 0;
}
