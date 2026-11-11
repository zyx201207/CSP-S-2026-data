#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],s[500005];
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
	int maxnp=0,p=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i,ans=0;
		while(l<r){
			int mid=(l+r)/2;
			int res=a[i]*(i-mid+1)-(s[i]-s[mid-1]);
			if(res<=m){
				ans=mid,r=mid-1;
			}
			else{
				l=mid+1;
			}
		}
		maxnp=max(maxnp,(i-ans+1));
	}
	printf("%lld",maxnp);
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/