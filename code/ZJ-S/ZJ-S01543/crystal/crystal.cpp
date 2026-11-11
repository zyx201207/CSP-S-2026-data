#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500050],s[500050],ans,l,r,mid,an;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=a[i]+s[i-1];
		l=1,r=i;
		while(l<=r){
			mid=(l+r)>>1;
			if(mid*a[i]-s[i]+s[i-mid]<=m) an=mid,l=mid+1;
			else r=mid-1;
		}
		ans=max(an,ans);
	}
	printf("%lld",ans);
	return 0;
}