#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int c,T,n,d,a[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&T);
	while(T--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		//if(c==11||c==12){
			if(n==1||n==2||n==3){
				printf("0\n");
				continue;
			}
			int ans=0;
			int x=a[2]-a[1];
			for(int i=4;i<=n;i++){
				int val=n-i+1;
				if((i-1)*x<=d||i%2==1) continue;
				if((i/2)*x<=d){
					ans+=val;
				}
			}
			printf("%lld\n",ans);
		//}
	}
	return ~(-1);
}
//238