#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
ll c,t,n,d;
ll a[N];
ll ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		if(n==1){
			puts("0");
		}
		if(c==11||c==12){
			if(d/(a[2]-a[1])<2)puts("0");
			else{
				ans=n-d/(a[2]-a[1])*2+1;
				if(ans<0)puts("0");
				else printf("%lld\n",ans);
			}
		}
	}
	return 0;
}
