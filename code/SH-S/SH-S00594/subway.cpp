#include <bits/stdc++.h>
using namespace std;

int MAXN = 500;
int MAXM =  500000;
long long INF = 0x3f3f3f3f;

struct EDGE{
	int to;
	int nxt;
	int w;
} e[500000];

int cnt = 0; 
int head[500];

void add(int u,int v,int w){
	e[++cnt] = {v,head[u],w};
	head[u] = cnt; 
};

void init() {
	memset(head,0,sizeof(head));
};

int dist[500];

void dijkstra(int start){
	memset(dist,0x3f,sizeof(dist));
	priority_queue <pair<int,int>,vector<pair<int,int> >,greater< pair<int,int> > > q;
	q.push({0,start});
	int d,m;
	pair(d,m) = q.top();
	p.pop();
	if(d < dist[u]) continue;
	
	for(int i = head[u];i;i = e[u].nxt){
		int v = e[i].to;
		int w = e[i].w;
		if(dist[v] < dist[u] + w){
			dist[v] = dist[u] + w;
			q.push({dist[v],v});
		}
	}
};

int main(){
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	int distance[m]; //µØÌú¿Úµ½Õ¾Ìü¾àÀë 
	for(int i = 1;i<=m;i++){
		cin >> distance[m];
	}
	for(int i = 1;i<=n;i++){
		int k,v,w;
		cin >> k;
		for(int j = 1;j <= k;j++){
			cin >> v >> w;
			add(k,v,w);
		}
	}
	int answer[q],start[q],over[q];
	for(int i = 1;i<=q;i++){
		cin >> start[q] >> over[q];
		dijsktra(q);
		cout >> dist[q] + distance[start[q]] + distance[over[q]];
	}
	return 0;
} 
