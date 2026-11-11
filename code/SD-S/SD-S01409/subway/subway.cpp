#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const ll N=510;
const ll M=5e5+10;
ll c,n,m,d,q,w[M],k[N],op,len[N*N*2],ans[N];
ll f[N][N],head[N],nt[N*N*2],to[N*N*2],vis[N];
vector<pair<ll,ll>>vt[M];
struct sqy{
	ll id,step;
	bool operator<(const sqy & other)const{
		return step>other.step;
	} 
};
void add(ll x,ll y,ll l){
	op++;
	to[op]=y;
	nt[op]=head[x];
	head[x]=op;
	len[op]=l;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(ll i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(ll i=1;i<=n;i++){
		scanf("%lld",&k[i]);
		for(ll j=1;j<=k[i];j++){
			ll a,t;
			scanf("%lld%lld",&a,&t);
			vt[a].push_back(make_pair(i,t));
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			f[i][j]=2e18;
		}
	}
	for(ll i=1;i<=m;i++){
		for(ll j=0;j<vt[i].size();j++){
			for(ll l=j+1;l<vt[i].size();l++){
				ll u=vt[i][j].first,v=vt[i][l].first;
				f[u][v]=min(f[u][v],vt[i][j].second+vt[i][l].second);
				f[v][u]=f[u][v];
			}
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=i+1;j<=n;j++){
			if(f[i][j]==2e18)continue;
			add(i,j,f[i][j]);
			add(j,i,f[i][j]);
		}
	}
	while(q--){
		ll x,y;
		scanf("%lld%lld",&x,&y);
		for(ll i=0;i<vt[y].size();i++){
			vis[vt[y][i].first]=vt[y][i].second;
		}
		for(ll i=1;i<=n;i++)ans[i]=2e18;
		priority_queue<sqy>q;
		for(ll i=0;i<vt[x].size();i++){
			ans[vt[x][i].first]=w[x]+vt[x][i].second;
			q.push((sqy){vt[x][i].first,ans[vt[x][i].first]});
		}
		ll res=2e18;
		while(!q.empty()){
			sqy g=q.top();q.pop();
			if(ans[g.id]<g.step)continue;
			if(vis[g.id]){
				res=min(res,ans[g.id]+w[y]+vis[g.id]);
				break;
			}
			for(ll i=head[g.id];i;i=nt[i]){
				ll v=to[i],l=len[i];
				if(ans[v]>ans[g.id]+l){
					ans[v]=ans[g.id]+l;
					q.push((sqy){v,ans[v]});
				}
			}
		}
		for(ll i=0;i<vt[y].size();i++){
			vis[vt[y][i].first]=0;
		}		
		printf("%lld\n",res);
	}
	return 0;
} 
