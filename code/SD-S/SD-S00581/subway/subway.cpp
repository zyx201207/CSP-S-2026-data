#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int N = 500+1, M = 1e5+1;

//第i站 -> i
//第i站出入口-> 1e5+i
//第j条线路-> 2e5+j 

vector<pair<int,int>> graph [2*M+N]; // v,w

bool inqueue[2*M+N];
long long dist[2*M+N];

int c,n,m,d,q;
queue<long long> que;
long long res(int u,int tar){
	memset(inqueue,false,sizeof(inqueue));
	memset(dist,0x3f3f3f3f,sizeof(dist));
	while(!que.empty()){
		que.pop();
	}
	dist[int(u+1e5)] = 0;
	inqueue[int(u+1e5)] = true;
	que.push(u+1e5);
	while(!que.empty()){
		int f = que.front();
		que.pop();
		inqueue[f] = false;
		for(auto pr: graph[f]){
			int v = pr.first;
			long long w = pr.second;
			if(inqueue[v]) continue;
			
			if(dist[v] > dist[f] + w){
				//cout <<f << ' ' << v << endl;
				que.push(v);
				inqueue[v] = false;
				dist[v] = dist[f] + w;
			}
		}
	}
	
	return dist[int(tar+1e5)];
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		int w;
		scanf("%d",&w);
		graph[int(i+1e5)].push_back({i,w});
		graph[i].push_back({i+1e5,w});
	}
	
	for(int i=1;i<=n;i++){ //线路 
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int v,w;
			scanf("%d%d",&v,&w);
			graph[v].push_back({i+2e5,w});
			graph[int(i+2e5)].push_back({v,w});
		}
	}
	
	for(int i=1;i<=q;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		long long ans = res(u,v);
		printf("%lld\n",ans);
	}
	
	return 0;
}

