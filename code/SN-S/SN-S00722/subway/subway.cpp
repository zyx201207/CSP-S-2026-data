#include<bits/stdc++.h>
using namespace std;

const int N=505,K=5e5+5;
long long w[K];
//vector<vector<pair<int,int> > > site;

int c,n,m,d,q;

struct edge{
	int v;
	long long w;
	int nxt;
};
vector<edge> edges(1);//线抽象点+地铁站 
int h[K+N],cnt;

void add(int u,int v,long long w){
	edges.push_back({v,w,h[u]});
	h[u]=edges.size()-1;
}

vector<long long> dist(K+N);
//vector<bool> vis(K+N);

void djstl(int u){
	fill(dist.begin(),dist.end(),LONG_MAX);
//	fill(vis.begin(),vis.end(),0);
	dist[u]=0;
	queue<int> q;
	q.push(u);
//	for(int i=1;i<=n+m;i++){
//		for(int j=h[i];j;j=edges[j].nxt){
//			if(dist[i]+edges[j].w<dist[edges[j].v]){
//				printf("updata:%d\n",edges[j].v);
//				dist[edges[j].v]=dist[i]+edges[j].w;
//			}
//		}
//	}
	while(!q.empty()){
		int i=q.front();
		q.pop();
		for(int j=h[i];j;j=edges[j].nxt){
			if(dist[i]+edges[j].w<dist[edges[j].v]){
//				printf("updata:%d\n",edges[j].v);
				dist[edges[j].v]=dist[i]+edges[j].w;
				q.push(edges[j].v);
			}
		}
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(false);
	
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
//	site.resize(m+1);//每个站台链接哪些线 
//	edges.resrver(m+1);
	for(int i=1;i<=n;i++){
		int k;
		cin >> k;
		for(int j=1;j<=k;j++){
			int a;long long t;
			cin >> a >> t;
			add(i+m,a,t);
			add(a,i+m,t);
		}
	}
	
//	for(int i=1;i<=m+n;i++){
//		for(int j=h[i];j;j=edges[j].nxt){
//			cout << edges[j].v << ' ';
//		}
//		cout << "\n";
//	}

	while(q--){
		int x,y;
		cin >> x >> y;
//		purior_queue<int>;
		djstl(x);
		cout << dist[y]+w[x]+w[y] << "\n";
	}
	
	return 0;
} 
