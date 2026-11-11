#include <bits/stdc++.h>
using namespace std;
#define int long long
int C,T,n,d,a[101000],ans,s,c; 
bool f1=true;
void solve(){
	scanf("%lld%lld",&n,&d);
	c=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(i==2){
			c=a[2]-a[1];
		}
		if(i!=1&&a[i]-a[i-1]!=c){
			f1=false;
		}
	}

	sort(a+1,a+n+1);
	if(f1){
		s=d/(a[2]-a[1]);
		ans=0;
		int j=s;
		for(int i=s+1;i<=n;i++){
			if((i%j)==0){
				ans+=n-i+1;
			}	
		}
		printf("%lld\n",ans);
	}
	return ;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&C,&T);
	while(T--){
		solve();
	}	
	return 0;
} 
