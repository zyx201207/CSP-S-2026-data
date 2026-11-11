#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500050],p[500050];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)p[i]=p[i-1]+a[i];
	int ans=1;
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(r>l){
			int mid=(l+r)/2;
			int k=(i-mid+1)*a[i]-p[i]+p[mid-1];
			if(k>m)l=mid+1;
			else r=mid;
		}
		ans=max(ans,i-l+1);
		//printf("ans[%lld]=%lld\n",i,i-l+1);
	}
	printf("%lld",ans);
}
