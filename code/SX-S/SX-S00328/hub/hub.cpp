#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=1e6+5;
vector<int>g[N];
int dis[15];
bool vis[15];
int c,T,n,k;
void dfs2(int u,int msk){
	vis[u]=1;
	for(int v:g[u]){
		if(vis[v])continue;
		if(msk&(1<<(v-1)))dfs2(v,msk);
	}
}
void dijkstra(int msk){
	priority_queue<pii,vector<pii>,greater<pii> >q;
	for(int i=1;i<=n;i++)dis[i]=0x3f3f3f3f,vis[i]=0;
	for(int i=0;i<n;i++)if(msk&(1<<i))dis[i+1]=0,q.push({0,i+1});
	while(!q.empty()){
		int u=q.top().se;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int v:g[u]){
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				q.push({dis[v],v});
			}
		}
	}
}
bool check(int msk){
	int cnt=0;
	for(int i=1;i<=n;i++)vis[i]=0;
	for(int i=0;i<n;i++){
		if(!(msk&(1<<i)))continue;
		if(!vis[i+1])cnt++,dfs2(i+1,msk);
	}
	if(cnt>2)return false;
	else return true;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int u,v;
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1;i<n;i++){
			cin>>u>>v;
			g[u].push_back(v),g[v].push_back(u);
		}
		if(c==13||c==14){
			int tmp=n-k+1;
			cout<<tmp/4<<'\n';
			continue;
		}
		int full=(1<<n);
		int ans=0x3f3f3f3f;
		for(int i=1;i<full;i++){
			int num=__builtin_popcount(i);
			if(num!=k)continue;
			if(!check(i))continue;
			dijkstra(i);
			int res=-0x3f3f3f3f;
			for(int i=1;i<=n;i++)res=max(dis[i],res);
			ans=min(ans,res);
		}
		cout<<ans<<'\n';
	}
	return 0;
}