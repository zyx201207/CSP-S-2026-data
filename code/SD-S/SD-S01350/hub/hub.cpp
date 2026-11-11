#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int INF=0x3f3f3f3f;
vector<int> edge[N];
int n,k,CASE;
bool vis[N];
bool dfn[N];
int d[N];
void init(){
	for(int i=1;i<=n;i++){
		vis[i]=0;
		d[i]=0;
		edge[i].clear();
	}
}
int bfs(int s){
	queue<int> q;
	q.push(s);
	for(int i=0;i<=n;i++){
		d[i]=0;
	}
	d[s]=1;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int y:edge[x]){
			if(d[y]){
				continue;
			}
			d[y]=d[x]+1;
			if(vis[y]){
				return d[y]-1;
			}
			q.push(y);
		}
	} 
	return INF;
}
void dfs(int x,int fa){
	dfn[x]=1;
	for(int y:edge[x]){
		if(y==fa||!vis[y]){
			continue;
		}
		dfs(y,x);
	}
}
int check(){
	for(int i=0;i<=n;i++){
		dfn[i]=0;
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(!dfn[i]&&vis[i]){
			cnt++;
			dfs(i,0);
		}
	}
	if(cnt>2){
		return INF;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(vis[i]){
			continue;
		}
		ans=max(ans,bfs(i));
	}
	return ans;
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	int ans=INF;
	for(int i=0;i<(1<<n);i++){
		int cnt=0;
		for(int j=0;j<=n;j++){
			vis[j]=0;
		}
		for(int j=1;j<=n;j++){
			if(i&(1<<(j-1))){
				vis[j]=1;
				cnt++;
			}
		}
		if(cnt!=k){
			continue;
		}
		ans=min(ans,check());
	}
	cout<<ans<<'\n';
	init();
}
int fun(int x,int y){
	vis[x]=vis[y]=1;
	int ans=0;
	for(int i=1;i<=n;i++){
		d[i]=0;
	}
	d[x]=d[y]=1;
	queue<int> q;
	q.push(x);
	q.push(y);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int v:edge[u]){
			if(d[v]){
				continue;
			}
			d[v]=d[u]+1;
			ans=max(ans,d[u]);
			q.push(v);
		}
	}
	return ans;
}
void solveb(){
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	int ans=INF;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j){
				continue;
			}
			ans=min(ans,fun(i,j));
		}
	}
	cout<<ans<<'\n';
	init();
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int T;
	cin>>CASE>>T;
	while(T--){
		if(CASE<=3){
			solve();
		} 
		else if(CASE==7||CASE==11||CASE==12){
			solveb();
		}
	}
	return 0;
}
