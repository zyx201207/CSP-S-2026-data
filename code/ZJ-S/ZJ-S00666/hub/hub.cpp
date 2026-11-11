#include<bits/stdc++.h>
using namespace std;
int n,k;
int ans=0x3f3f3f3f,ans_=0;
short vis[1000005];
vector<int> e[1000005];
void dfs(int u);
bool check(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(vis[i]==1){
			cnt++;
			if(cnt==3) break;
			dfs(i);
		} 
	}
	return cnt<=2;
}
void dfs(int u){
	if(vis[u]==0 || vis[u]==2) return ;
	vis[u]=2;
	for(int i=0;i<e[u].size();i++){
		int v=e[u][i];
		if(v==0) continue;
		dfs(v);
	}
}
int dis[1000005];
queue<int> q;
void bfs(){
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(vis[u]==1) return ;
		vis[u]=1;
		for(int i=0;i<e[u].size();i++){
			int v=e[u][i];
			if(dis[u]+1<dis[v]){
				dis[v]=dis[u]+1;
				ans_=max(dis[v],ans_);
				q.push(v);
			}
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	int c,t;
	cin>>c>>t;
	while(t--){
		ans=0x3f3f3f3f;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		for(int i=0;i<(1<<n);i++){
			int j=i;
			int K=0,b=1;
			for(int i=1;i<=n;i++) vis[i]=0;
			while(j){
				if(j&1) {
					vis[b]=1;
					K++;
				}
				j>>=1;
				b++;
			}
			if(K!=k || !check()) continue;
			for(int i=1;i<=n;i++){
				dis[i]=0x3f3f3f3f;
				if(vis[i]){
					q.push(i);
					dis[i]=0;
				} 
			} 
			ans_=0;
	//		cout<<":";
			bfs();
			ans=min(ans_,ans);
		}
		cout<<ans<<"\n";
		for(int i=1;i<=n;i++){
			vector<int> c;
			e[i].swap(c);
		}
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/