#include<bits/stdc++.h>
using namespace std;
struct edge{
	long long x,y;
}e[1000010];
long long c,t,n,k,fa[1000010],vis[1000010],sum[1000010],ans = 1e18;
long long dis[1000010];
vector<long long> edges[1000010];
queue<long long> q;
inline long long getf(long long x){
	return x==fa[x]?fa[x]:fa[x] = getf(fa[x]);
}
inline void bfs(){
	for(int i = 1;i<=n;i++) dis[i] = 1e18;
	for(int i = 1;i<=n;i++) if(vis[i]){
		q.push(i),dis[i] = 0;
	}
	long long res = 0;
	while(!q.empty()){
		long long x = q.front();q.pop();
		res = max(res,dis[x]);
		for(auto y : edges[x]) if(dis[y]==1e18){
			dis[y] = dis[x]+1;
			q.push(y);
		}
	}
	ans = min(ans,res);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld %lld",&c,&t);
	while(t--){
		ans = 1e18;
		scanf("%lld %lld",&n,&k);
		for(int i = 1;i<=n;i++) edges[i].clear();
		for(int i = 1;i<n;i++){
			long long x,y;
			scanf("%lld %lld",&x,&y);
			e[i].x = x,e[i].y = y;
			edges[x].push_back(y);
			edges[y].push_back(x);
		}
		for(int s = 0;s<(1<<n);s++){
			for(int i = 1;i<=n;i++) vis[i] = 0,fa[i] = i,sum[i] = 0;
			long long cnt = 0;
			for(int i = 0;i<n;i++){
				if((s>>i)&1) vis[i+1] = 1,cnt++;
			}
			if(cnt!=k) continue;
			for(int i = 1;i<n;i++){
				if(!vis[e[i].x]||!vis[e[i].y]) continue;
				long long fu = getf(e[i].x),fv = getf(e[i].y);
				fa[fu] = fv;
			}
			long long num = 0;
			for(int i = 1;i<=n;i++){
				if(vis[i]){
					fa[i] = getf(fa[i]),sum[fa[i]]++;
					if(sum[fa[i]]==1) num++;
				}
			}
			if(num<=2){
				bfs();
			}			
		}
		printf("%lld\n",ans);
	}
	return 0;
}
