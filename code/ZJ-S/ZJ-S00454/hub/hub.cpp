#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=5e3+10;
int n,m,ans;
int dis[N];
bool ee[N][N];
vector<int> e[N];
struct bcj{
	int cnt=0,fa[N];
	void init(){
		for(int i=1;i<=n;i++) fa[i]=i;
		return;
	}
	int find(int x){
		return fa[x]==x?x:fa[x]=find(fa[x]);
	}
	void merge(int x,int y){
		x=find(x),y=find(y);
		if(x==y) return;
		fa[x]=y;
		cnt--;
		return;
	}
};
void bfs(int x){
	memset(dis,0,sizeof(dis));
	queue<int> q;
	q.push(x);
	dis[x]=1;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int& v:e[u]){
			if(dis[v]) continue;
			dis[v]=dis[u]+1;
			q.push(v);
		}
	}
	return;
}
vector<int> v;
bool check(){
	bcj node;
	node.init();
	for(int& x:v){
		for(int& y:v){
			if(ee[x][y]) node.merge(x,y);
		}
	}
	return node.cnt+v.size()<3;
}
void get_ans(){
	int mx=0;
	for(int i=1;i<=n;i++){
		int mn=2e9;
		bfs(i);
		for(int& x:v){
			mn=min(mn,dis[x]-1);
		}
		mx=max(mx,mn);
	}
	ans=min(ans,mx);
	return;
}
void dfs(int st,int cnt){
	if(cnt==m){
		if(check()) get_ans();
		return;
	}
	for(int i=st;i<=n;i++){
		v.push_back(i);
		dfs(i+1,cnt+1);
		v.pop_back();
	}
	return;
}
void solve(){
	ans=2e9;
	cin>>n>>m;
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
		ee[u][v]=true;
		ee[v][u]=true;
	}
	dfs(1,0);
	for(int i=1;i<=n;i++) e[i].clear(),memset(ee,false,sizeof(ee));
	cout<<ans<<'\n';
	return;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int _,__;
	cin>>__>>_;
	while(_--) solve();
	cout<<flush;
	fclose(stdin),fclose(stdout);
	return 0;
}
