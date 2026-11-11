#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long x[2000010],d,ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	for(int test=1;test<=t;test++){
		scanf("%d%lld",&n,&d);
		ans=0;
		memset(x,0,sizeof(x));
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		for(int u=1;u<n;u++){
			for(int v=2;v<=n;v++){
				if(abs(x[v]-x[u])>d&&abs(x[v]-x[u])<2*d){
					ans++;
				}
			}
		}
		printf("ans=%lld\n",ans);
	}
	return 0;
}
