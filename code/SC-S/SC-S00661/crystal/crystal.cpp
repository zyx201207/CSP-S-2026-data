#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+7;
int n,m,a[N],t[N],ans;

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i) t[i]=t[i-1]+a[i];
	for(int i=1;i<=n;++i){
		int l=1,r=i;
		while(l<=r){
			int mid=l+r>>1;
			if(a[i]*mid-(t[i]-t[i-mid])<=m) l=mid+1;
			else r=mid-1;
		}
		ans=max(ans,r);
	}
	printf("%lld",ans);
	return 0;
}
