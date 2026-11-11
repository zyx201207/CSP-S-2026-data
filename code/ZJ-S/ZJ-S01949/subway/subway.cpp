#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1;
typedef long long ll;
const ll Max=1e18+5;
ll flyd[600][600];
ll df[N][21];//这个点连接的地铁站线 
ll wf[N][21];// 这个点连接的地铁站线时间 
ll num[N];//站厅到出口 
int main(){ 
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ll c,n,m,d1,q;
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d1,&q);
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			flyd[i][j]=Max;
		}flyd[i][i]=0;
	}
	for(int i=1;i<=m;i++) scanf("%lld",&num[i]);
	for(int i=1;i<=n;i++){
		ll c1;
		scanf("%lld",&c1);
		for(int j=1;j<=c1;j++){
			ll d;
			scanf("%lld",&d);
			df[d][++df[d][0]]=i;
			ll y=df[d][0];
			scanf("%lld",&wf[d][y]);
			for(int k=1;k<y;k++){
				ll x=df[d][k];
				flyd[x][i]=flyd[i][x]=min(flyd[x][i],wf[d][y]+wf[d][k]);
			}
		}
	}	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				flyd[k][j]=flyd[j][k]=min(flyd[j][k],flyd[k][i]+flyd[i][j]);
			}
		}
	}
	while(q--){
		ll l,r;
		scanf("%lld%lld",&l,&r);
		ll ans=Max;
		for(int i=1;i<=df[l][0];i++){
			for(int j=1;j<=df[r][0];j++){
				ans=min(ans,flyd[df[l][i]][df[r][j]]+num[l]+num[r]+wf[l][i]+wf[r][j]);
			}
		}printf("%lld\n",ans);
	}
	return 0;
}


