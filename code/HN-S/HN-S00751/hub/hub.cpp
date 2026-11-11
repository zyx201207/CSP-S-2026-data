#include<bits/stdc++.h>
using namespace std;
const int maxn=5005;

int c,T,n,k,u,v,dist[maxn][maxn],ans=1e9,cnt;
vector<int> g[maxn];
bool vis[maxn],vis2[maxn];

void bfs(int x){
	queue<int> q;
	for(int i=1;i<=n;i++){
		dist[x][i]=1e9;
	}
	dist[x][x]=0;
	q.push(x);
	while(!q.empty()){
		u=q.front();
		q.pop();
		for(int v:g[u]){
			if(dist[x][v]>dist[x][u]+1){
				dist[x][v]=dist[x][u]+1;
				q.push(v);
			}
		}
	}
}

void ck(int u){
	vis2[u]=1;
	for(int v:g[u]){
		if(!vis2[v]&&vis[v]){
			ck(v);
		}
	}
}

void calc(){
	int res=0,mins;
	for(int i=1;i<=n;i++){
		vis2[i]=0;
	}
	cnt=0;
	for(int i=1;i<=n;i++){
		if(!vis2[i]&&vis[i]){
			ck(i);
			cnt++;
		}
	}
	if(cnt>2){
		return;
	}
	for(int i=1;i<=n;i++){
		mins=1e9;
		for(int j=1;j<=n;j++){
			if(vis[j]){
				mins=min(mins,dist[i][j]);
			}
		}
		res=max(res,mins);
	}
	ans=min(ans,res);
}

void dfs(int step,int val){
	if(step>n+1){
		return;
	}
	if(val==k){
		calc();
		return;
	}
	vis[step]=1;
	dfs(step+1,val+1);
	vis[step]=0;
	dfs(step+1,val);
}

void work(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		g[i].clear();
	}
	ans=1e9;
	for(int i=1;i<n;i++){
		cin>>u>>v;
		g[u].push_back(v); 
		g[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		bfs(i);
	}
	dfs(1,0);
	cout<<ans<<'\n';
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		work();
	}
	return 0;
}
/*
jun jun a
jun jun a
jun jun a
*/

