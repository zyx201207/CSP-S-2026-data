#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],sum[N],ans;
bool check(int x){
	for(int i=1;i+x-1<=n;i++){
		if(a[i+x-1]*x-sum[i+x-1]+sum[i-1]<=m){
			return 1;
		}
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++)
		sum[i]=sum[i-1]+a[i];
	int l=1,r=n;
	while(l<=r){
		int mid=((l+r)>>1);
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else
			r=mid-1;
	}
	printf("%lld",ans);
	return 0;
}