#include<bits/stdc++.h>
#define int long long
using namespace std;

/*
100pts?
*/

const int N=5e5+10;
int n,m,a[N],sum[N];

int find(int l,int r){
	int now=r;
	while(l<r){
		int mid=(l+r)>>1;
		if(m>=sum[now]-1LL*(a[now]-a[mid])*(mid-1)-sum[mid]) r=mid;
		else l=mid+1;
	}
	return l;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+1LL*(i-1)*(a[i]-a[i-1]);
	
	int ans=1;
	for(int i=1;i<=n;i++){
		int l=find(1,i);
		ans=max(ans,i-l+1);
	}
	printf("%lld\n",ans);
	return 0;
}