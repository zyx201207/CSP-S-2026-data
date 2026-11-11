#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M=5e5+5;
int n,m,ans,a[M],sm[M];
inline void OIer_WiFi(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%lld",a+i);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i)
		sm[i]=sm[i-1]+a[i];
	for(int i=1;i<=n;++i){
		int l=1,r=i,res=-1;
		while(l<=r){
			int mid=(l+r)>>1,len=i-mid+1;
			if(a[i]*len-(sm[i]-sm[mid-1])>m)l=mid+1;
			else r=mid-1,res=len;
		} ans=max(ans,res);
	}
	printf("%lld",ans);
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	OIer_WiFi(); return 0;
}
// 14:38 AC