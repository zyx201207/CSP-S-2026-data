#include<bits/stdc++.h>
using namespace std;
long long n,m,lst[500005],sum[500005],ans;
bool check(long long l,long long r){
	return lst[r]*(r-l+1)-(sum[r]-sum[l-1])<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&lst[i]);
	}
	sort(lst+1,lst+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+lst[i];
	for(int i=1;i<=n;i++){
		long long l=1,r=i;
		while(l<=r){
			long long mid=(l+r)/2;
			if(check(mid,i))r=mid-1,ans=max(ans,i-mid+1);
			else l=mid+1;
		}
	}
	printf("%lld",ans);
} 
