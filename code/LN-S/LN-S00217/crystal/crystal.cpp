#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=500010;
int n,m,a[N],s[N],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		if(a[i]==a[i+1]) continue;
		int l=1,r=i,mid,res=l;
		while(l<=r){
			mid=l+r>>1;
			if(a[i]*(i-mid+1)-s[i]+s[mid-1]<=m) res=mid,r=mid-1;
			else l=mid+1; 
		}
		ans=max(ans,i-res+1);
	}
	printf("%lld",ans);
	return 0;
}
