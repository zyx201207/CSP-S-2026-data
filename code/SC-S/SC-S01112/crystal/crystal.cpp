#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500050],ans;
int s[500050];
bool check(int mid,int i){
	if(s[mid]-s[i-1]+m>=(mid-i+1)*a[mid]){
		return 1;
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
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int l=i,r=n;
		while(l<r-1){
			int mid=(l+r)/2;
//			printf("%d %d %d",l,mid,r);
			if(check(mid,i)){
				l=mid;
			}else{
				r=mid-1;
			}
		}
		ans=max(ans,l-i+1);
	}
	printf("%lld",ans);
}