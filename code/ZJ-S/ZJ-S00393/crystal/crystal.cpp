#include<bits/stdc++.h>
using namespace std;
const int N=5e5+50;
typedef long long ll;
ll a[N],sum[N];
int n;
ll m;
int bound(int l,int r,int R,ll k){
	while(l<r){
		int mid=(l+r)>>1;
		if(k*(R-mid+1)-(sum[R]-sum[mid-1])>m)l=mid+1;
		else r=mid;
	}
	return l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		sum[i]=sum[i-1]+a[i];
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		ans=max(i-bound(1,i,i,a[i])+1,ans);
	}
	printf("%d\n",ans);
	return 0;
}

