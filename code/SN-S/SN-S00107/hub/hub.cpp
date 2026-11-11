#include <bits/stdc++.h>

int c,test,n,k,st[10010],dist[10010];
std::vector<int>adj[1100];
bool vis[1100];
int full;

inline void dfs2(int x){
	vis[x]=true;
	for(auto y:adj[x]){
		if(vis[y]||st[y]==0)
			continue;
		dfs2(y);
	}
}

inline void bfs(int x){
	std::queue<int>q;
	q.push(x);
	dist[x]=1;
	while(!q.empty()){
		int p=q.front();
		q.pop();
		for(auto y:adj[p]){
			if(dist[y])
				continue;
			dist[y]=dist[p]+1;
			q.push(y);
		}
	}
}

inline void calc(){
	for(int i=1;i<=n;i++)
		vis[i]=false,dist[i]=0;
	int sum=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]&&st[i]==1){
			sum++;
			dfs2(i);
		}
	}
	if(sum!=2)
		return;
	int ans=0;
	for(int i=1;i<=n;i++){
		int min=INT_MAX;
		for(int j=1;j<=n;j++)
			vis[j]=false,dist[j]=0;
		bfs(i);
		//if(st[2]==1&&st[4]==1&&st[1]==0&&st[5]==0){
		//	std::cout<<"%%%"<<i<<"\n";
		//	for(int j=1;j<=n;j++)
		//		std::cout<<dist[j]<<" ";
		//	std::cout<<"\n";
		//}
		for(int j=1;j<=n;j++){
			if(st[j])
				min=std::min(min,dist[j]-1);
		}
		ans=std::max(ans,min);
	}
	full=std::min(full,ans);
	//if(ans==1){
	//	for(int i=1;i<=n;i++)
	//		std::cout<<st[i]<<" ";
	//	std::cout<<"\n";
	//}
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

inline void dfs(int x,int sum){
	if(x==n+1){
		if(sum==k)
			calc();
		return;
	}
	st[x]=0;
	dfs(x+1,sum);
	st[x]=1;
	dfs(x+1,sum+1);
}

inline void solve(){
	full=INT_MAX;
	std::cin>>n>>k;
	for(int i=1;i<=n;i++)
		adj[i].clear();
	for(int i=1;i<n;i++){
		int u,v;
		std::cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1,0);
	std::cout<<full<<"\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	std::cin>>c>>test;
	while(test--){
		solve();
	}
	return 0;
}
