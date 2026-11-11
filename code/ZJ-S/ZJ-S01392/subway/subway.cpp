#include<bits/stdc++.h>
using namespace std;
const int N=500005;
typedef long long ll;
ll c,n,m,d,q,idx,pos,a,t,x,y,k;
ll w[N*2],di[1005],vis[N*2];
ll head[N*2],nxt[N*2],len[N*2],to[N*2];
struct node{
	ll id;
	ll dist;
	bool operator < ( const node &op ) const {
		return dist>op.dist;
	}
};
priority_queue<node> pq;
void add(ll x,ll y,ll z){
	to[++idx]=y;
	len[idx]=z;
	nxt[idx]=head[x];
	head[x]=idx;
}
void dijkstra(ll s,ll mu){
	for(int i=1;i<=n+m;i++){
		di[i]=100000000000;
	}
	for(int i=1;i<=n+m;i++){
		vis[i]=0;
	}
	pq.push({s,0});
	di[s]=0;
	while(pq.size()){
		node cur=pq.top();
		pq.pop();
		if(vis[cur.id]) continue;
		vis[cur.id]=1;
		if(cur.dist>di[cur.id]) continue;
		for(int i=head[cur.id];i;i=nxt[i]){
			ll u=cur.id,v=to[i];
			if(di[v]>di[u]+len[i]){
				di[v]=di[u]+len[i];
				pq.push({v,di[v]});
			}
		}
	}
	ll ans=di[mu]+w[mu]+w[s];
	printf("%lld\n",ans);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&k);
		pos=i+m;
		for(int j=1;j<=k;j++){
			scanf("%lld%lld",&a,&t);
			add(pos,a,t);
			add(a,pos,t);
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%lld%lld",&x,&y);
		dijkstra(x,y);
	}
	return 0;
}