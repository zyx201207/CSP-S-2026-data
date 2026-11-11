#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=6e5+5;

int n,m,a[N],c[N];

bool check(int d){
	for(int p=1;p<=n-d+1;p++){
		int q=p+d-1;
		int x=c[q]-c[p-1]-(a[q]-a[p-1])*(p-1);
		if(x<=m) return 1;
	}
	return 0;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(i!=1) c[i]=c[i-1]+(i-1)*(a[i]-a[i-1]);
	}
	int l=1,r=n,ans=1;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)) l=mid+1,ans=mid;
		else r=mid-1;
	}
	printf("%lld",ans);

	return 0;
}

