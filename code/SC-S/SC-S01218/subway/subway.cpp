#include<bits/stdc++.h>
const long long N=505,M=7e4+5,K=5e5,inf=1e18+5;
long long c,n,m,D,Q,S,T,u,w,cnt,ans,k,W[K],dis[N][M],d[K];
struct node{long long v,w;};
struct Node{
	long long u,t;
	friend long long operator < (Node a,Node b){
		return a.t>b.t;
	}
};
std::vector<node> edge[K],a[K];
std::priority_queue<Node> q; 
void dijk(long long s,long long *dis){
	for(long long i=1;i<=cnt;i++)dis[i]=inf;
	dis[s]=0,q.push({s,0});
	while(!q.empty()){
		Node t=q.top();
		q.pop();
		if(t.t==dis[t.u]){
			for(node e:edge[t.u]){
				if(dis[e.v]>t.t+e.w){
					dis[e.v]=t.t+e.w;
					q.push({e.v,dis[e.v]});
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&D,&Q);
	cnt=n;
	for(long long i=1;i<=m;i++)scanf("%lld",&W[i]);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&k);
		for(long long j=1;j<=k;j++){
			scanf("%lld%lld",&u,&w);
			a[u].push_back({i,w});
			d[u]++;
		}
	}
	for(long long i=1;i<=m;i++){
		if(d[i]*d[i]*d[i]>n){
			cnt++;
			for(node e:a[i]){
				edge[cnt].push_back({e.v,e.w});
				edge[e.v].push_back({cnt,e.w});
				// printf("%d %d\n",cnt,e.v);
			}
		}
		else{
			for(node x:a[i]){
				for(node y:a[i]){
					if(x.v!=y.v){
						edge[x.v].push_back({y.v,x.w+y.w});
						edge[y.v].push_back({x.v,x.w+y.w});
						// printf("%d %d\n",x.v,y.v);
					}
				}
			}
		}
	}
	for(long long i=1;i<=n;i++){
		dijk(i,dis[i]);
	}
	while(Q--){
		scanf("%lld%lld",&S,&T);
		ans=inf;
		for(node x:a[S]){
			for(node y:a[T]){
				ans=std::min(ans,x.w+y.w+dis[x.v][y.v]+W[S]+W[T]);
				// printf("%lld %lld %lld %lld %lld\n",S,T,x.v,y.v,dis[x.v][y.v]);
			}
		}
		printf("%lld\n",ans);
	}
}