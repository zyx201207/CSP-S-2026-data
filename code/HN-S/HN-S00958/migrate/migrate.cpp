#include<bits/stdc++.h>
using namespace std;
int const N = 2e5+7;
int c,t;
struct node{
	int v,w;
	bool operator <(const node&a) const{
		return w>a.w;
	}
};
vector<node> g[N];
int dis[N],vis[N],cnt[N],n,d,a[N];
void dijkstra(int st){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	memset(cnt,0,sizeof(cnt));
	dis[st] = 0;cnt[st] = 1;
	priority_queue<node> q;
	while(q.size()){
		int u = q.top().v;q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(node i:g[u]){
			int v = i.v,w = i.w;
			if(dis[v]==dis[u]+w){
				cnt[v] += cnt[u];
			}
			if(dis[v]>dis[u]+w){
				cnt[v] = cnt[u];
				dis[v] = dis[u]+w;
				q.push({v,dis[v]});
			}
		}
	}
	return;
}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			if(abs(a[i]-a[j])>d) continue;
			g[i].push_back({j,abs(a[i]-a[j])});
			g[j].push_back({i,abs(a[i]-a[j])});
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		dijkstra(i);
		for(int j=1;j<=n;j++){
			if(cnt[j]==2) ans++;
		}
	}
	cout<<ans<<'\n';
} 
int main(){
	freopen("migrate1.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}

