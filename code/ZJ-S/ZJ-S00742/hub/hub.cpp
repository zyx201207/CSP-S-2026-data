#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
#define ll long long 
#define N 15
using namespace std;//15pts
int n,k;
vector<int>G[N];
int ans=1e9;
bitset<N>vis,in;
vector<int>ok;
int dis[N];
inline void bfs(int s){
	for(int i=1;i<=n;i++){
		vis[i]=0;
	}
	queue<int>q;
	q.emplace(s);
	dis[s]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int v:G[u]){
			if(vis[v])continue;
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				q.emplace(v);
			}
		}
	}
}
inline void bfs1(int u){
	queue<int>q;
	q.emplace(u);
	while(!q.empty()){
		int u=q.front();q.pop();
		if(!in[u])continue;
		if(vis[u])continue;
		vis[u]=1;
		for(int v:G[u]){
			if(vis[v])continue;
			q.emplace(v);
		}
	}
}
inline bool isok(){
	for(int i=1;i<=n;i++){
		vis[i]=0;
	}
	int cnt=0;
	for(int i:ok){
		if(!vis[i]){
			bfs1(i);
			cnt++;
			if(cnt>2)return 1;
		}
	}
	return cnt>2;
}
inline void check(){
	if(isok())return;
	for(int i=1;i<=n;i++){
		dis[i]=1e9;
	}
	for(int u:ok){
		bfs(u);
	}
	int res=0;
	for(int i=1;i<=n;i++){
		res=max(res,dis[i]);
	}
	ans=min(res,ans);
}
void gt(int d,int nxt){
	if(d==k+1){
		check();
		return;
	}
	for(int i=nxt;i<=n;i++){
		in[i]=1;
		ok.eb(i);
		gt(d+1,i+1);
		in[i]=0;
		ok.pop_back();
	}
}
void solve(){
	ans=1e9;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		G[i].clear();
	}
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		G[x].eb(y);
		G[y].eb(x);
	}
	gt(1,1);
	printf("%d\n",ans);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int t;
	scanf("%d",&t);
	scanf("%d",&t);
	while(t--)solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
