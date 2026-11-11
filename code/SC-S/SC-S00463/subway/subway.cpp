#include<bits/stdc++.h>
using namespace std;
const int N=550;
const int M=5e5+10;
const int INF=1e9;
typedef pair<int,int> pii;
int c,n,m,d,q;

int w[M];



struct node{
	int num;
	int id;
	int t;
}node[M];

struct edge{
	int ev;
	int et;
};

int cnt=0;

vector<edge> g[M];

priority_queue<pii> heap;

int dis[M];
int vis[M];

int dij(int s,int end){
	
	for(int i=1;i<=cnt;i++){
		dis[i]=INF;
	}
	
	memset(vis,0,sizeof(vis));

	dis[s]=w[node[s].num]+node[s].t;
	
	heap.push({-dis[s],s});
	
	while(heap.size()){
		
		int v=heap.top().second;
		heap.pop();
		
		if(vis[v]) continue;
		
		vis[v]=1;
		
		for(int i=0;i<g[v].size();i++){
			int to=g[v][i].ev;
			int ww=g[v][i].et;
			if(dis[to]>dis[v]+ww){
				dis[to]=dis[v]+ww;
				heap.push({-dis[to],to});
			}
		}
		
	}
	
	int mins=INF;
	for(int i=1;i<=cnt;i++){
		if(node[i].num==end){
			mins=min(mins,dis[i]+w[end]+node[i].t);
		}
	}
	
	return mins;
	
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	
	for(int i=1;i<=n;i++){
		
		int k=0;
		cin>>k;
		
		
		for(int j=1;j<=k;j++){
			cnt++;
			cin>>node[cnt].num>>node[cnt].t;
		
			node[cnt].id=i;
			if(j!=k){
				g[cnt].push_back({cnt+1,0});
				g[cnt+1].push_back({cnt,0});
			}
		}
		
	}
	
	for(int i=1;i<=cnt;i++){
		for(int j=i;j<=cnt;j++){
			if(node[i].num==node[j].num&&node[i].id!=node[j].id){
				int tot=node[i].t+node[j].t;
				g[i].push_back({j,tot});
				g[j].push_back({i,tot});
			}
		}
	}
	
	
	while(q--){
		
		int ans=INF,l=0,r=0;
		
		cin>>l>>r;
		
		for(int i=1;i<=cnt;i++){
			if(node[i].num==l){
				ans=min(ans,dij(i,r));
			}
		}
		
		cout<<ans<<endl;
		
	}
	
	return 0;
}