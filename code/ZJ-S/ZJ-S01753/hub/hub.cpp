#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int c,T,n,k;
vector<int> G[N];
bool vis[N],tmp[N];
void dfs1(int u){
	tmp[u]=0;
	for(int v:G[u]){
		if(tmp[v]){
			tmp[v]=0;
			dfs1(v);
		}
	}
}
int dis[N],ans;
void update(){
	for(int i=1;i<=n;i++) tmp[i]=vis[i];
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(tmp[i]){
			cnt++;
			dfs1(i);
			if(cnt>2) return;
		}
	}
	if(!cnt) return;
	queue<int> q;
	for(int i=1;i<=n;i++){
		dis[i]=n;
		if(vis[i]) q.push(i),dis[i]=0;
	}
	int res=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		res=max(res,dis[u]);
		for(int v:G[u]){
			if(dis[v]==n){
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
	}
	ans=min(ans,res);
}
void dfs(int x,int sum){
	if(sum>k) return;
	if(x>n){
		if(sum==k) update();
		return;
	}
	vis[x]=1;
	dfs(x+1,sum+1);
	vis[x]=0;
	dfs(x+1,sum);
}
void clear(){
	for(int i=1;i<=n;i++){
		G[i].clear();
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		clear();
		cin>>n>>k;
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		ans=n;
		dfs(1,0);
		cout<<ans<<'\n';
	}
	return 0;
}
