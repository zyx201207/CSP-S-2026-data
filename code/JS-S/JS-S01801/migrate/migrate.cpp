#include<bits/stdc++.h>
#define int long long
using namespace std;

constexpr int z=200009;
int n,m,a[z],ans,gigi,t,h,d[309][309],c[309][309];

void solve(){
	for(int l=1;l<=n;l++)
		for(int s=1;s+l-1<=n;s++){
			if(a[s+l-1]-a[s]<=h){
				d[s][s+l-1]=c[s][s+l-1]=1;
//				printf("%lld -%lld ++\n",s,s+l-1);
			}
			for(int k=s+1;k<s+l-1;k++){
				int ds=d[s][k]+d[k][s+l-1];
//				printf("ds %lld ^ %lld ^%lld=%lld\n",s,k,s+l-1,+ds);
				if(ds<d[s][s+l-1])
					d[s][s+l-1]=ds,
					c[s][s+l-1]=0;
				if(ds<=d[s][s+l-1]){
					c[s][s+l-1]+=c[s][k]*c[k][s+l-1];
//				printf("add %lld ^ %lld ^%lld=%lld TO %lld",
//				s,k,s+l-1,c[s][k]*c[k][s+l-1],c[s][s+l-1]);
				}
			}
			if(c[s][s+l-1]==2)
				++ans/**,printf("#######%lld-%lld##########",s,s+l-1)*/;
	//		printf("%lld to%lld:%lld %lld\n",
	//		s,s+l-1,c[s][s+l-1],d[s][s+l-1]);
		}
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&gigi,&t);
	while(t--){
		ans=0;
		memset(d,0x3f,sizeof d);
		memset(c,0,sizeof c);
		scanf("%lld%lld",&n,&h);
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		solve();
		printf("%lld\n",ans);
	}
}
