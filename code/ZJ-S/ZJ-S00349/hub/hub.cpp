#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t;
int n;
int k;
bool vis[N];
vector<int>g[N];
vector<int>h[N];
int dis[N];
bool col[N];
int ans;
void ds(int x){
	col[x]=1;
	for(int y:h[x]){
		if(col[y]) continue;
		col[y]=1;
		ds(y);
	}
}
void check(){
	for(int i=1;i<=n;i++){
		h[i].clear();
		if(!vis[i]) continue;
		for(int j:g[i]){
			if(!vis[j]) continue;
			h[i].push_back(j);
		}
	}
//	if(vis[3]&&vis[4]&&vis[10]){
//		cout<<"OKOKK\n";
//		for(int i=1;i<=n;i++){
//			for(int j:h[i]){
//				cout<<i<<" "<<j<<"\n";
//			}
//		}
//	}
	memset(col,0,sizeof col);
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]) continue;
		if(col[i]) continue;
		cnt++;
		ds(i);
		if(cnt>2) return;
	}
	if(cnt>2) return;
//	cout<<"OK!";
	memset(dis,0x3f,sizeof dis);
	queue<int>q;
	while(!q.empty()) q.pop();
	for(int i=1;i<=n;i++){
		if(vis[i]){
			q.push(i);
			dis[i]=0;
		}
	}
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int y:g[x]){
			if(dis[y]>dis[x]+1){
				dis[y]=dis[x]+1;
				q.push(y);
			}
		}
	}
	int now=0;
	for(int i=1;i<=n;i++) now=max(now,dis[i]);
//	if(now<ans){
//		cout<<now<<"\n";
//		for(int i=1;i<=n;i++){
//			cout<<vis[i]<<" ";
//		}
//		cout<<"\n";
//	}
	ans=min(ans,now);
}
void dfs(int st,int now){
	if(now>k) return;
	if(st>n){
		if(now!=k) return;
		check();
		return;
	}
	vis[st]=0;
	dfs(st+1,now);
	vis[st]=1;
	dfs(st+1,now+1);
	vis[st]=0;
}
void work(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	ans=INT_MAX;
	dfs(1,0);
	cout<<ans<<"\n";
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
		cin>>c>>t;
	while(t--) work();
	return 0;
}