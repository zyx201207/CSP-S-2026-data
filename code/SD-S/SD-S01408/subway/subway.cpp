#include<bits/stdc++.h>
#define ll int
#define LL long long
const ll N=5e5+100;
using namespace std;
ll C,n,m,D,Q;
LL w[N],d[505][505];
struct qwe{
	ll v;
	LL c;
};
vector<qwe>q[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&C,&n,&m,&D,&Q);
	for(ll i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(ll i=1;i<=n;i++){
		ll k;
		scanf("%d",&k);
		for(ll j=1;j<=k;j++){
			ll x,t;
			scanf("%d%d",&x,&t);
			q[x].push_back({i,t});
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=i+1;j<=n;j++){
			d[i][j]=d[j][i]=1e18;
		}
	}
	for(ll i=1;i<=m;i++){
		for(ll j=0;j<q[i].size();j++){
			ll a=q[i][j].v;
			LL c1=q[i][j].c;
			for(ll k=j+1;k<q[i].size();k++){
				ll b=q[i][k].v;
				LL c2=q[i][k].c;
				d[a][b]=min(d[a][b],c1+c2);
				d[b][a]=d[a][b];
			}
		}
	}
	for(ll k=1;k<=n;k++){
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
				d[j][i]=d[i][j];
			}
		}
	}
	while(Q--){
		ll a,b;
		scanf("%d%d",&a,&b);
		LL ans=1e18;
		for(ll i=0;i<q[a].size();i++){
			ll x=q[a][i].v;
			LL c1=q[a][i].c;
			for(ll j=0;j<q[b].size();j++){
				ll y=q[b][j].v;
				LL c2=q[b][j].c;
				ans=min(ans,d[x][y]+c1+c2);
			}
		}
		ans=ans+w[a]+w[b];
		printf("%lld\n",ans);
	}
	return 0;
} 
