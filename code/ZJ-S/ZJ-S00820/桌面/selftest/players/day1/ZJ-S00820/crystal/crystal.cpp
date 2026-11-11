#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans=1;
int a[500005];
int s[500005];
inline bool check(int l,int r){
	// cerr<<l<<" "<<r<<" "<<(s[r]-s[l-1]-a[r]*(r-l+1)<=m)<<endl;
	return s[r]-s[l-1]-a[r]*(r-l+1)<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	int mx=a[n];
	for(int i=1;i<=n;i++){
		a[i]=mx-a[i];
		s[i]=s[i-1]+a[i];
	}
	for(int R=n;R>=1;R--){
		int l=1,r=R;
		while(l<=r){
			int mid=(l+r)/2;
			if(check(mid,R)){
				ans=ans<(R-mid+1)?(R-mid+1):ans;
				r=mid-1;
			}
			else{
				l=mid+1;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}