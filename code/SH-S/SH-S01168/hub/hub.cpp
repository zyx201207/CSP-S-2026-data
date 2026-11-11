#include<bits/stdc++.h>
using namespace std;
const int N = 500010;
int c,t;
int n,k;
vector<int> e[N];

int u[N],v[N];
bool vis[N],inbfs[N];
int r;
int dis[N];

void bfs(){
	queue<int> q;
	for(int i = 1;i <= n;i++) inbfs[i] = dis[i] = 0;
	for(int i = 1;i <= n;i++){
		if(vis[i]){
			q.push(i);
			inbfs[i] = 1;
		}
	}
	int radius = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		radius = max(radius,dis[u]);
		for(int i = 0;i < e[u].size();i++){
			int v = e[u][i];
			if(inbfs[v]==0){
				dis[v] = dis[u]+1;
				inbfs[v] = 1;
				q.push(v);
			}
		}
	}
	r = min(r,radius);
}

void dfs(int x,int cnt){
	if(x>n){
		int L = k;
		for(int i = 1;i < n;i++){
			if(vis[u[i]]&&vis[v[i]]) L--;
		}
		if(L<=2) bfs();
		return;
	}
	if(cnt<k){
		vis[x] = 1;
		dfs(x+1,cnt+1);
	}
	if(cnt+n-x>=k){
		vis[x] = 0;
		dfs(x+1,cnt);
	}
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i = 1;i < n;i++){
			cin>>u[i]>>v[i];
			e[u[i]].push_back(v[i]);
			e[v[i]].push_back(u[i]);
		}
		r = n;
		dfs(1,0);
		for(int i = 1;i <= n;i++){
			vector<int> e1;
			swap(e[i],e1);
		}
		cout<<r<<'\n';
	} 
}
