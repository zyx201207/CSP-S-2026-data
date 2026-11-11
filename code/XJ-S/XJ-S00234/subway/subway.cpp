#include <bits/stdc++.h>
using namespace std;
const int maxn=510;
const int maxm=500010;
const int inf=0x3f3f3f3f;
long long W_in[maxm];
struct node{
	int v;
	long long w;
};
vector<node> G[maxn+maxm];
vector<node> Gn[maxn];
//vector<node> emp;
vector<node> Gls[maxn];
long long  dis[maxn];
vector<int> st_c[maxm];
void insert(vector<node> Gm[],int u,int v,long long w){
	Gm[u].push_back(node{v,w});
}
void nostation(int n,int s,int c,int wc){
	for (int i=0;i<G[n+s].size();i++){
		int v = G[n+s][i].v,w = G[n+s][i].w;
		insert(Gn,c,v,w+wc);
		insert(Gn,v,c,w+wc);
	}
}
void dijkstra(int s){
	memset(dis,inf,sizeof(dis));
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
	dis[s]=0;
	pq.push(make_pair(dis[s],s));
	while(!pq.empty()){
		pair<int,int> p=pq.top();
		pq.pop();
		int d=p.first,u=p.second;
		if (dis[u] > d)continue;
		for (int i=0;i<G[u].size();i++){
			int v=G[u][i].v;int w=G[u][i].w;
			if (dis[v] > dis[u]+w){
				dis[v]=dis[u]+w;
				//cout << v << " "<<dis[v] << " "<<w;
				pq.push(make_pair(dis[v],v));
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,m,n,d,q;
	cin >> c >> n >> m >> d >> q;
	for (int i=1;i<=m;i++) cin >> W_in[i];
	long long k,a,t;
	for (int i=1;i<=n;i++){
		cin >>k;
		for (int j=0;j<k;j++){
			cin >> a >> t;
			insert(G,i,n+a,t);
			insert(G,n+a,i,t);
			st_c[a].push_back(i);
		}
	}

	int x,y;
	for (int i=0;i<q;i++){
		cin >>x>>y;
		dijkstra(n+x);
		cout <<(long long)(W_in[x]+W_in[y]+dis[n+y]) << endl;
//		Gn[n+1]=emp;
//		Gn[n+2]=emp;
	}
	return 0;
}
