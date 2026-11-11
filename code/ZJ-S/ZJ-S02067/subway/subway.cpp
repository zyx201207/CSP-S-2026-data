#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct edge{
	int to;
	ll w;
	const bool operator<(const edge &o) const{
		return w<o.w;
	}
};
vector<edge> g[500010];

int w[500010];

ll d[510][510];

//id of point[x]=x+n
int main(){
	
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,dd,q;cin>>c>>n>>m>>dd>>q;
	int i,j,k;
	for(i=1;i<=m;i++) cin>>w[i];
	for(i=1;i<=n;i++){
		int k;cin>>k;
		for(j=1;j<=k;j++){
			int a;ll t;cin>>a>>t;
			g[a].push_back({i,t});
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(i!=j) d[i][j]=1e15;
		}
	}
	for(i=1;i<=m;i++){
		for(edge e1:g[i]){
			for(edge e2:g[i]){
				d[e1.to][e2.to]=min(e1.w+e2.w,d[e1.to][e2.to]);
			}
		}
	}
	for(k=1;k<=n;k++){
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				d[i][j]=min(d[i][k]+d[j][k],d[i][j]);
			}
		}
	}
	while(q--){
		int x,y;cin>>x>>y;
		ll ans=LONG_LONG_MAX;
		for(edge ex:g[x]){
			for(edge ey:g[y]){
				ans=min(ex.w+ey.w+d[ex.to][ey.to]+w[x]+w[y],ans);
				//printf("ex .to=%d .w=%lld\ney .to=%d .w=%lld\ndis=%lld\n",ex.to,ex.w,ey.to,ey.w,d[ex.to][ey.to]);
			}
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}
