#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
long long n,m,a[500010],g[500010];
long long findp(long long x){
	int l=1,r=x-1;
	while(l<r){
		int mid=(l+r)/2;
		if(a[x]*(x-mid)-(g[x-1]-g[mid-1])<=m) r=mid;
		else l=mid+1;
	}
	if(r==x-1&&a[x]-a[x-1]>m) return 0;
	return x-r+1;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long minn=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		minn=min(minn,a[i]);
	}
	for(int i=1;i<=n;i++){
		a[i]-=minn;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		g[i]=g[i-1]+a[i];
	}
	int ans=1;
	for(int i=n;i>=2;i--){
		ans=max(ans,findp(i));
	}
	cout<<ans;
	return 0;
}

