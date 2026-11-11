#include <iostream>
#include <algorithm>

using ll=long long;

constexpr int N=500010;

int n;
ll m;
ll a[N];

ll sum[N];
int ans;

int bs(int s){
	int l=1,r=s;
	int ans=-1;
	
	while(l<=r){
		int mid=(l+r)/2;
		if(a[s]*(s-mid+1)-(sum[s]-sum[mid-1])<=m){
			ans=mid;
			r=mid-1;
		}else l=mid+1;
	}
	
	return ans;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	scanf("%d%lld",&n,&m);
	
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	std::sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	
	for(int i=1;i<=n;i++){
		int p=bs(i);
		ans=std::max(ans,i-p+1);
	}
	
	printf("%d\n",ans);
	
	return 0;
}
/*
5 5
1 2 4 8 9
*/

/*
5 8
-3 -1 2 2 7
*/
