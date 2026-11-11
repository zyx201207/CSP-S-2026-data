#include<bits/stdc++.h>
#define ll long long
#define pir pair<ll,ll>
using namespace std;
const ll N=505,M=2e4+5;
struct edge{
	ll v,w;
};
ll dis[N][M],vis[N][M];
struct node{
	ll id;//编号 
	ll fl;//地铁号 
	ll p;//当前地铁所在位置 
	bool operator>(const node &other)const{
		return dis[fl][id]>dis[other.fl][other.id];
	}
};
ll c,n,m,d,q;
ll a[N][M],t[N][M],w[M],len[N];
vector<pir> in[N];//连接的站台和位置 
void bfs(ll s,ll e){
	priority_queue<node,vector<node>,greater<node> > q;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=len[i];j++){
			dis[i][j]=vis[i][j]=0;
			if(a[i][j]==s){
				q.push({s,i,j});
				vis[i][j]=1;
				dis[i][j]=w[s]+t[i][j];
			}
		}
	}
	while(q.size()){
		ll u=q.top().id,k=q.top().fl,p=q.top().p;//编号，地铁号，位置 
		//printf("%lld %lld %lld %d\n",u,k,p,dis[k][p]);
		q.pop();
		for(ll i=0;i<in[u].size();i++){
			ll fl=in[u][i].first,np=in[u][i].second;
			if(fl==k||vis[fl][np]) continue;
			vis[fl][np]=1;
			dis[fl][np]=dis[k][p]+t[fl][np];
			q.push({u,fl,np});
			//printf("%lld %lld %lld %lld",u,fl,np,dis[fl][np]);
		}
		for(ll i=p+1;i<=len[k];i++){
			if(vis[k][i]||i>len[k]) continue;
			vis[k][i]=1;
			dis[k][i]=dis[k][p]+t[k][i];
			q.push({a[k][i],k,i});
			//printf("%lld %lld %lld %lld\n",a[k][v],k,v,dis[k][v]);
		}
		for(ll i=p-1;i>0;i--){
			if(vis[k][i]||i<1) continue;
			vis[k][i]=1;
			dis[k][i]=dis[k][p]+t[k][i];
			q.push({a[k][i],k,i});
		}
	}
	ll ans=0x3f3f3f3f3f3f3f3f;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=len[i];j++){
			printf("%d ",dis[i][j]);
		}
		puts("");
	}
	for(int i=0;i<in[e].size();i++){
		ans=min(ans,dis[in[e][i].first][in[e][i].second]);
	}
	ans+=w[e];
	printf("%lld\n",ans);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);
	for(ll i=1;i<=m;i++) scanf("%lld",w+i);
	ll sum=0;
	for(ll i=1;i<=n;i++){
		scanf("%lld",len+i);
		for(ll j=1;j<=len[i];j++){
			scanf("%lld %lld",&a[i][j],&t[i][j]);
			in[a[i][j]].push_back({i,j});
		}
	}
	while(q--){
		ll x,y;
		scanf("%lld %lld",&x,&y);
		bfs(x,y);
	}
	return 0;
}
