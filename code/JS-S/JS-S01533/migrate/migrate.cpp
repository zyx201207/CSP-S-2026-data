#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t,n;
long long d;
long long x[N];
int far_to[N];
int far_from[N]; 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		if(x[n]-x[1]<=2*d){
			for(int i=1;i<=n;i++){
				far_to[i]=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
				far_from[i]=lower_bound(x+1,x+n+1,x[i]-d)-x;
			}
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=far_to[i]+1;j<=n;j++){
					//cout<<far_to[i]<<' '<<far_from[j]<<'\n';
					ans+=far_to[i]-far_from[j];
				}
			}
			printf("%d\n",ans);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
