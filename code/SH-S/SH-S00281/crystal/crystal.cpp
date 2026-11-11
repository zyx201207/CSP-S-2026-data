#include <bits/stdc++.h>
using namespace std;
int64_t a[500010];
int64_t b[500010];
int64_t sum[500010];
int64_t n,m;
int64_t at;
int64_t ans=0;
priority_queue<int64_t,vector<int64_t>,greater<int64_t> > pq;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
//	printf("%d %d\n",n,m);
	if(n==1){
		printf("1");
		return 0;
	}
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;++i) b[i]=a[i]*i-sum[i];
	int ans=0;
	for(int i=1;i<=n;++i){
		int l=1,r=i;
		while(r-l>1){
			int mid=(l+r)>>1;
			if(a[i]*(mid)-sum[i]+sum[i-mid+1]<=m){
				l=mid;
			}else{
				r=mid;
			}
		}
		ans=max(ans,r);
	}
	printf("%d",ans);
	return 0;
}
