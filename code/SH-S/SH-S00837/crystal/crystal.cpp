#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500009],l,r,ans=1,cnt;
signed main(void){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	l=1,r=2;
	for(;r<=n;r++){
		cnt+=(a[r]-a[r-1])*(r-l);
		while(cnt>m&&l<r){
			l++,cnt-=a[r]-a[l];
		}ans=max(ans,r-l+1);
	}printf("%lld\n",ans);
	return 0;
} // I love little lovely miyachn, OvO
