#include<bits/stdc++.h>
#define int long long
using namespace std;
const int NA=1e6+5;
vector<int> g[NA]; 
bool f[NA],vis[NA];
int dis[NA];
int n,k,ans;
void cov(int s){
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int t=q.front();
		q.pop();
		if(vis[t]) continue;
		vis[t]=1; 
		for(auto v:g[t]){
			if(f[v]==1&&vis[v]==0){
				q.push(v);
			}
		}
	}
}
void bfs(){
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	queue<int> q;
	for(int i=1;i<=n;i++){
		if(f[i]==1){
			q.push(i);
			dis[i]=0;
		}
	}
	while(!q.empty()){
		int t=q.front();
		q.pop();
		if(vis[t]) continue;
		vis[t]=1; 
		for(auto v:g[t]){
			if(dis[v]>dis[t]+1){
				dis[v]=dis[t]+1;
				q.push(v);
			}
		}
	}
}
void dfs(int step,int cnt){
	if(cnt>k) return ;
	if(step>n){
		int cur=0;
		memset(vis,0,sizeof vis);
		for(int i=1;i<=n;i++){
			if(f[i]==1&&vis[i]==0){
				cov(i);
				cur++;
			}
		}
		if(cur>2) return ;
		bfs();
		int maxn=0;
		for(int i=1;i<=n;i++) maxn=max(maxn,dis[i]);
		ans=min(ans,maxn);
		return ;
	}
	dfs(step+1,cnt);
	f[step]=1;
	dfs(step+1,cnt+1);
	f[step]=0;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0); 
	int c,t;
	cin>>c>>t;
	for(int q=1;q<=t;q++){
		cin>>n>>k;
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if(c==13||c==14){
			int m=(n-1)/2;
			if(k==n){
				cout<<"0\n";
			}
			else if(k>=m){
				cout<<"1\n";
			}
			else{
				cout<<"2\n";
			}
		}
		else{
			ans=1e18;
			dfs(1,0);
			cout<<ans<<"\n";
		}
	}
	return 0;
}
