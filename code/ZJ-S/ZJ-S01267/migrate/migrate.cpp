#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2000010;
const ll INF=2e16;
int c,t,n;
short dp[5010][5010];
ll d,x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--){
        scanf("%d%lld",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%lld",x+i);
        }
        if(c==11||c==12){
        	ll dif=x[2]-x[1];
        	if(d<2*dif){
        		printf("0\n");
        		continue;
			}
        	if(1ll*n+1-2*(d/dif)>=0)printf("%lld\n",1ll*n+1-2*(d/dif));
        	else printf("0\n");
		}else
        	printf("0\n");
    }
} 