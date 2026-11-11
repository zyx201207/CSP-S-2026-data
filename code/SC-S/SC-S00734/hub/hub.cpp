#include<bits/stdc++.h>
using namespace std;
const int N = 25;

int n,k,fa[N]; 
vector<int> graph[N];
bool slt[N];
int dist[N][N];

int ans=1e9;

int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}

bool chk(){
	for(int i=1;i<=n;i++) fa[i]=i;
	
	int tot=k;
	for(int i=1;i<=n;i++){
		if(!slt[i]) continue;
		for(auto j : graph[i]){
			if(!slt[j]) continue;
			
			int fax=find(i),fay=find(j);
			if(fax==fay) continue;
			
			tot--;
			fa[fax]=fay;
			
		}
	}
	
	if(tot > 2) return false;
	else return true;
} 

int calc(){
	int mx=0;
	
	for(int i=1;i<=n;i++){
		if(slt[i]) continue;
		
		int p=1e9;
		for(int j=1;j<=n;j++){
			if(!slt[j]) continue;
			
			p=min(p,dist[i][j]);
		}
		
		mx=max(mx,p);
	}
	
	return mx;
}

void dfs(int idx,int need){
	if(idx == n+1){
		if(!need && chk()){
			ans=min(ans,calc());
		} 
		return ;
	}
	if(need == 0) return ;
	
	dfs(idx+1,need);
	
	slt[idx]=true;
	dfs(idx+1,need-1);
	slt[idx]=false;
} 

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout); 
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int c,T;
	cin>>c>>T;
	while(T --){
		cin>>n>>k;
		for(int i=1;i<=n;i++) graph[i].clear();
		
		memset(dist,0x3f,sizeof dist);
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			graph[u].push_back(v);
			graph[v].push_back(u);
			dist[u][v]=dist[v][u]=1;
		}
		
		for(int p=1;p<=n;p++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					dist[i][j]=min(dist[i][p]+dist[p][j],dist[i][j]);
				}
			}
		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				cout<<dist[i][j]<<' ';
//			}
//			cout<<'\n';
//		}
		
		ans=1e9;
		dfs(1,k);
		
		cout<<ans<<'\n';
	}
	
	return 0;
}

/*
上午那个是我 
S 好难，遗憾离场 
可不可以把s弄简单一点，暴力好打一点 

input:
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


这个only 15pts，依旧“小小的暴力” 
不想写LCA，写个floyd吧... 
这个暴利是啥dfs+floyd/lca+并查集吗 
*/ 