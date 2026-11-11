#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q,w[500010];
ll val[510][510];
vector<ll> e[500010];
unordered_map<ll,ll> t[510];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
		for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
		for(int i=1;i<=n;i++){
			ll gs;
			scanf("%lld",&gs);
			for(int j=1;j<=gs;j++){
				ll a;
				scanf("%lld",&a);
				scanf("%lld",&t[i][a]);
				e[a].push_back(i);
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				val[i][j]=1e18;
			}
		}
		for(int i=1;i<=n;i++){
			val[i][i]=0;
		}
		for(int i=1;i<=m;i++){
			ll sz=e[i].size();
			for(int j=0;j<sz;j++){
				for(int k=j+1;k<sz;k++){
					val[e[i][j]][e[i][k]]=min(val[e[i][j]][e[i][k]],t[e[i][j]][i]+t[e[i][k]][i]);
					val[e[i][k]][e[i][j]]=min(val[e[i][k]][e[i][j]],t[e[i][k]][i]+t[e[i][j]][i]);
				}
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(val[i][k]!=1e18&&val[k][j]!=1e18){
						val[i][j]=min(val[i][j],val[i][k]+val[k][j]);
					}
				}
			}
		}
		while(q--){
			ll x,y,ans=1e18;
			scanf("%lld%lld",&x,&y);
			ll sz1=e[x].size();
			ll sz2=e[y].size();
			for(int i=0;i<sz1;i++){
				for(int j=0;j<sz2;j++){
					ans=min(ans,val[e[x][i]][e[y][j]]+w[x]+w[y]+t[e[x][i]][x]+t[e[y][j]][y]);
				}
			}
			printf("%lld\n",ans);
		}
	return 0;
}
