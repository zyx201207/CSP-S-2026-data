#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,k,n,ans;
int f[1000010];
bool vis[1000010],vis2[1000010];
vector<int> g[1000010];
struct node{
	int x,y;
}e[1000010];
struct node2{
	int d,id;
	bool operator<(const node2&a)const{
		return d<a.d;
	}
};
priority_queue<node2> q;
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
void merge(int u,int v){
	u=find(u);
	v=find(v);
	if(u!=v) f[v]=u;
}
void dfs(int p){
	if(p==n+1){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(vis[i]) cnt++;
		}
		if(cnt!=k) return ;
		for(int i=1;i<=n;i++) f[i]=i,vis2[i]=0;
		for(int i=1;i<n;i++){
			if(vis[e[i].x]&&vis[e[i].y]){
				merge(e[i].x,e[i].y);
			}
		}
		cnt=0;
		for(int i=1;i<=n;i++){
			if(vis[i]&&f[i]==i) cnt++;
		}
		if(cnt>2) return ;
		for(int i=1;i<=n;i++){
			if(vis[i]) q.push({0,i});
			vis2[i]=0;
		}
		int s=0;
		while(!q.empty()){
			int id=q.top().id,d=q.top().d;
			q.pop();
			if(vis2[id]) continue;
			vis2[id]=1;
			s=max(s,-1*d);
			for(int i=0;i<g[id].size();i++){
				int y=g[id][i];
				if(vis2[y]) continue;
				q.push({d-1,y});
			}
		}
		ans=min(ans,s);
		return ;
	}
	dfs(p+1);
	vis[p]=1;
	dfs(p+1);
	vis[p]=0;
}
signed main(){
	std::ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>e[i].x>>e[i].y;
			g[e[i].x].push_back(e[i].y);
			g[e[i].y].push_back(e[i].x);
		}
		ans=1e18;
		dfs(1);
		cout<<ans<<"\n";
		for(int i=1;i<=n;i++){
			vis[i]=0;
			g[i].clear();
		}
	}
	return 0;
}
