#include<bits/stdc++.h>
using namespace std;
const int N=2e6+1;
int ccc;
int n,t;
long long x[N],d,dx,dy,ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d",&ccc);
	scanf("%d",&t);
	if(ccc==11||ccc==12){
		while(t--){
			scanf("%d%lld",&n,&d);
			for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
			dx=x[2]-x[1],dy=x[1];
			if(dx>d){
				printf("0\n");
				continue;
			}
		    long long mma=d/dx;
			ans=(n-mma+1)(mma-1)-(mma*(mma-1)/2);
			printf("%lld\n",ans);
		}
	}
	return 0;
}
