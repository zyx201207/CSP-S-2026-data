#include<bits/stdc++.h>
#define int long long
using namespace std;

constexpr int z=500009;
int n,m,a[z],ans,d[z],p[z],rst;

bool check(int l,int r){
	return (p[r]-p[l-1]-(r-l+1)*d[r])<=m;
}

void solve(){
	for(int i=1;i<=n;i++){
		int l=1,r=rst=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid,i))
				rst=mid,r=mid-1;
			else
				l=mid+1;
		}
		ans=max(i-rst+1,ans);
//		printf("i=%lld rst=%lld gi=%lld ans=%lld\n",i,rst,i-rst+1,ans);
	}
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		d[i]=a[n]-a[i],
		p[i]=d[i]+p[i-1];
//	for(int i=1;i<=n;i++)
//		printf("%lld ",p[i]);
	solve();
	printf("%lld",ans);
}
