#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,d,a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d %d",&c,&t);
	while(t--){
		scanf("%lld %lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		if(11<=c&&c<=12){//ÌØÊâÐÔÖÊA 
			ll distance=abs(a[2]-a[1]);
			if(distance>d){
				printf("0\n");
				continue;
			}
			ll cnt=d/distance,ans=0;
			if(cnt+1>n){
				n-=2;
				ans=(n+1)*n/2;
			}else{
				for(int i=3;i<=cnt;i++){
					ans+=n/i+1;
				}
			}
			printf("%lld\n",ans);
		}else if(13<=c&&c<=14){
			
		}else if(15<=c&&c<=18){
			
		}
	}
	return 0;
}
