#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e6+5;
ll c,T,n,d,a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&T);
	while(T--){
		scanf("%lld%lld",&n,&d);
		bool fA=1,fB=1;
		for(int i=1;i<=n;i++) {
			scanf("%lld",&a[i]);
			if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2]) fA=0;
		}
		if(fA){
			ll l=a[2]-a[1],t=d/l,cnt=0;//t表示最多能飞越的岛屿数 
			for(int i=1;i<t&&i+t<=n;i++){
				ll s=i+t+1;//总跨越
				cnt+=n-s+1;
				//cout<<i<<' '<<cnt<<'\n';
			}
			printf("%lld\n",cnt);
		}
	}
	return 0;
} 
