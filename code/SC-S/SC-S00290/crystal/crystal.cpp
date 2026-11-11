#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N],m;
long long cha[N],ans,sum[N];
int n;
long long cnt[N];
bool cheak(long long x){
	long long k;
	for(int i=1;i<=n-x+1;i++){
		if(cha[x+i-2]+sum[i-x+1]-(i-1)*a[i+1]<=m){
			return true;
		}
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		cha[i]=a[i+1]-a[i];
		cha[i]=cha[i-1]+cha[i]*i;
	}
	long long l=0,r=n;
	while(l<=r){
		long long mid=(l+r)>>1;
		if(cheak(mid)) l=mid+1,ans=mid;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}