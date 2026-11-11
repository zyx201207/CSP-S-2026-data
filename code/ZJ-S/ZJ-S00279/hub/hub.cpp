#include<bits/stdc++.h>
using namespace std;
int const N=1e3+5;
int c,t,n,k;
long long ans;
bool vis[N];
set<int>tmp;
vector<int> G[N],g[N];
long long dist[N];
queue<int> que;
map<string,bool> mp;
void dfs(int u){
	vis[u]=true;
	for(auto v:g[u]){
		if(vis[v] || find(G[u].begin(),G[u].end(),v)==G[u].end()) continue;
		dfs(v);
	}
}
string getid(set<int> st){
	string s=""; 
	for(int i:st) s=s+to_string(i)+",";
	return s;
}
void build(int id,int cnt,set<int> st){
	if(mp.count(getid(st))) return;
	if(st.size()) mp[getid(st)]=true;
	if(cnt==k){
		int Scnt=0;
		for(int i=1;i<=n;i++) G[i].clear(),vis[i]=false;
		for(int u:st){
			for(int v:st){
				if(u==v) continue;
				G[u].push_back(v);
				G[v].push_back(u);
			}
		}
		for(int i=1;i<=n;i++){
			if(G[i].size()){
				if(!vis[i]) dfs(i),Scnt++;
			}
		}
		if(Scnt>2) return;
		for(int i=1;i<=n;i++) dist[i]=0x3f3f3f3f3f3f3f3f;
		for(int i:st) que.push(i),dist[i]=0;
		while(que.size()){
			int u=que.front();que.pop();
			for(auto v:g[u]){
				if(dist[v]>dist[u]+1){
					dist[v]=dist[u]+1;
					que.push(v);
				}
			}
		}
		long long maxn=0;
		for(int i=1;i<=n;i++) maxn=max(maxn,dist[i]);
		ans=min(ans,maxn);
		return;
	}
	if(id==n+1) return;
	for(int i=1;i<=n;i++){
		if(st.count(i)) continue;
		st.insert(i);
		build(id+1,cnt+1,st);
		st.erase(i);
	}
	build(id+1,cnt,st);
}
void solve(){
	cin>>n>>k;ans=1e9;mp.clear();
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	build(1,0,tmp);
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
