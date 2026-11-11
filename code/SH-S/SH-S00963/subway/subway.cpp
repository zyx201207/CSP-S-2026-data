#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
typedef long long ll;
const ll INF=0x3f3f3f3f3f3f3f3f;

int c,n,m,d,q;
ll w[N];
vector<pair<int,ll>> t[N];
vector<ll> g[N];
ll dis[505][505];

ll get(int i,int j){
	for(auto it:t[i]){
		if(it.first==j) return it.second;
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		int k;
		scanf("%lld",&k);
		for(int j=1;j<=k;j++){
			int a,tm;
			scanf("%lld%lld",&a,&tm);
			g[a].push_back(i);
			t[a].push_back({i,tm}); 
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<g[i].size();j++){
			for(int k=j+1;k<g[i].size();k++){
				int u=g[i][j],v=g[i][k];
				dis[v][u]=dis[u][v]=min(dis[u][v],get(i,u)+get(i,v));
			}
		}
	}
	
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
			}
		}
	}
	while(q--){
		int x,y;
		scanf("%lld%lld",&x,&y);
		ll ans=INF;
		for(auto u:g[x]){
			for(auto v:g[y]){
				ans=min(ans,dis[u][v]+get(x,u)+get(y,v)); 
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

