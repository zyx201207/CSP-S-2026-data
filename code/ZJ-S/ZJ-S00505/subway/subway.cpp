#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k;
long long dis[1001000],w;
int vis[1001000];
struct edge{
	int v;
	long long w;
	bool operator <(edge y)const{
		return w>y.w;
	}
};
vector<edge>a[1001000];
long long dijkstra(int x,int y){
	priority_queue<edge>q;
	for(int i=1;i<=m+m+n;i++){
		dis[i]=(1ll<<60);
		vis[i]=0;
	}
	q.push(edge{m+x,0});
	dis[m+x]=0;
	while(!q.empty()){
		int ui=q.top().v;
		q.pop();
		if(vis[ui])continue;
		vis[ui]=1;
		for(int i=0;i<a[ui].size();i++){
			int vi=a[ui][i].v;
			long long wi=a[ui][i].w;
			if(dis[ui]+wi<dis[vi]){
				dis[vi]=dis[ui]+wi;
			}
			q.push(edge{vi,dis[vi]});
		}
	}
	return dis[m+y];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w);
		a[m+i].push_back(edge{i,w});
		a[i].push_back(edge{m+i,w});
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		int ai;
		long long ti;
		for(int j=1;j<=k;j++){
			scanf("%d%lld",&ai,&ti);
			a[m+m+i].push_back(edge{ai,ti});
			a[ai].push_back(edge{m+m+i,ti});
		}
	}
	int x,y;
	long long ans;
	for(int i=1;i<=q;i++){
		scanf("%d%d",&x,&y);
		ans=dijkstra(x,y);
		printf("%lld\n",ans);
	}
	return 0;
}
