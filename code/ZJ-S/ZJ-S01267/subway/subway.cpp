#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=510,M=5e5+10;
const ll INF=2e18;
ll c,n,m,d,q,w[M],dis[N][N]; 
struct node{
    int station;
    ll t;
};
vector<node>a[M];
vector<pair<int,ll>>ed[N];
void build(){
    for(int i=1;i<=m;i++){
        for(int j=0;j<(int)a[i].size();j++){
            for(int k=0;k<(int)a[i].size();k++){
                if(j!=k){
                    ed[a[i][j].station].push_back({a[i][k].station,a[i][k].t+a[i][j].t});
                }
            }
        }
    }
}
void dij(int u){
    memset(dis[u],0x4f,sizeof(dis[u]));
    dis[u][u]=0;
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>qq;
    qq.push({0,u});
    while(!qq.empty()){
        ll di=qq.top().first,v=qq.top().second;
        qq.pop();
        if(di>dis[u][v])continue;
        for(auto x:ed[v]){
            if(dis[u][x.first]>di+x.second)dis[u][x.first]=di+x.second,qq.push({dis[u][x.first],x.first});
        }
    }
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",w+i);
	}
	for(int i=1;i<=n;i++){
		ll k;
		scanf("%lld",&k);
		for(int j=1;j<=k;j++){
			ll A,T;
			scanf("%lld%lld",&A,&T);
			a[A].push_back({i,T});
		}
	}
    build();
    for(int i=1;i<=n;i++)
        dij(i);
    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
        ll ans=INF;
        for(auto aa:a[x]){
            for(auto bb:a[y]){
                ans=min(ans,w[x]+aa.t+dis[aa.station][bb.station]+bb.t+w[y]);
            }
        }
        printf("%lld\n",ans);
    }
} 