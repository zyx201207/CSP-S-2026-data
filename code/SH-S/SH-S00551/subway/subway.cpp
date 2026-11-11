#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,Q,w[500005],ans,dis[500005],vis[500005];
int a[500005],t[500005],a2[500005],t2[500005],cnt[500005],minn=0x3f3f3f3f3f3f3f3f;
struct node{
	int v,w;
	bool operator<(const node &x)const{
		return w>x.w;
	}
};
vector<node> g[500005];
void dijkstra(int u){
	priority_queue<node> q;
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	q.push({u,0});
	vis[u]=1,dis[u]=0;
	while(!q.empty()){
		node now=q.top();
		q.pop();
		for(int i=0;i<g[now.v].size();i++){
			int j=g[now.v][i].v;
			if(vis[j]) continue;
			if(dis[j]>dis[now.v]+g[now.v][i].w){
				dis[j]=dis[now.v]+g[now.v][i].w;
				vis[j]=1;
				q.push({j,dis[j]});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&Q);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	if(c>=20&&c<=21){
		if(n==1){
			int k;
			scanf("%lld",&k);
			for(int j=1;j<=k;j++){
				scanf("%lld%lld",&a[j],&t[j]);
				dis[a[j]]=t[j];
			}
			while(Q--){
				int x,y;
				scanf("%lld%lld",&x,&y);
				ans=w[x]+w[y]+dis[x]+dis[y];
				printf("%lld\n",ans);
			}		
		}else{
			int k;
			scanf("%lld",&k);
			for(int j=1;j<=k;j++){
				scanf("%lld%lld",&a[j],&t[j]);
				cnt[a[j]]++,dis[a[j]]=t[j];
			}
			scanf("%lld",&k);
			for(int j=1;j<=k;j++){
				scanf("%lld%lld",&a2[j],&t2[j]);
				cnt[a2[j]]+=2,vis[a2[j]]=t2[j];
			}
			for(int i=1;i<=m;i++){
				if(cnt[i]==3){
					minn=min(minn,dis[i]+vis[i]);
				}
			}
			while(Q--){
				int x,y;
				scanf("%lld%lld",&x,&y);
				if(cnt[x]==3){
					if(cnt[y]==3){
						ans=min(dis[x]+dis[y],vis[x]+vis[y])+w[x]+w[y];
					}else if(cnt[y]==2){
						ans=vis[x]+vis[y]+w[x]+w[y];
					}else{
						ans=dis[x]+dis[y]+w[x]+w[y];
					}
				}else if(cnt[y]==3){
					if(cnt[x]==1){
						ans=dis[x]+dis[y]+w[x]+w[y];
					}else{
						ans=vis[x]+vis[y]+w[x]+w[y];
					}
				}else if(cnt[x]==cnt[y]&&cnt[x]==1){
					ans=w[x]+w[y]+dis[x]+dis[y];
				}else if(cnt[x]==cnt[y]&&cnt[x]==2){
					ans=w[x]+w[y]+vis[x]+vis[y];
				}else if(cnt[x]==1&&cnt[y]==2){
					ans=w[x]+w[y]+dis[x]+vis[y]+minn;
				}else{
					ans=w[x]+w[y]+vis[x]+dis[y]+minn;
				}
				printf("%lld\n",ans);
			}
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%lld",&k);
		for(int j=1;j<=k;j++){
			scanf("%lld%lld",&a[j],&t[j]);
			for(int len=1;len<j;len++){
				g[a[len]].push_back({a[j],t[len]+t[j]});
				g[a[j]].push_back({a[len],t[len]+t[j]});
			}
		}
	}
	while(Q--){
		int x,y;
		scanf("%lld%lld",&x,&y);
		dijkstra(x);
		ans=dis[y]+w[x]+w[y];
		printf("%lld\n",ans);
	}
	return 0;
}
