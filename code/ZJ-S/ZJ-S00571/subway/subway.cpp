#include <bits/stdc++.h>
#define endl '\n'
#define LAB
//#define DEBUG
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pa = pair<int,int>;
using pli = pair<ll,int>;
const int N = 5e2+10, M = 5e5+10;

int CASE;
int c,n,m,d,q;
ll w[M];
int k[N];
vector<pli> G[M+N],GA[M+N];

bool spA=1,spB=1;
ll spB_t;

void solveA();
ll dijkstra(int x,int y);
ll dijkstraA(int x,int y);

int main() {
	#ifdef LAB
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);	
	#endif
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	
	cin>>CASE;
//	cerr<<"Now CASE-"<<CASE<<endl;
	
	cin>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++) 
		cin>>w[i];
	
	for(int i=1;i<=n;i++) {
		cin>>k[i];
		
		if(k[i]>2) spA=0;
		
		for(int j=1;j<=k[i];j++) {
			int u; ll t;
			cin>>u>>t;
			
			if(!spB_t) spB_t=t;
			else if(spB_t!=t) spB=0;
			
			G[m+i].push_back({t,u});
			G[u].push_back({t,m+i});
			#ifdef DEBUG
			cerr<<m+i<<"<->"<<u<<':'<<w[u]+t<<endl;
			#endif
		}
	}
	
	
	if(spA) {
		solveA();
	}
	
	
	// O[(m+n)log(m+n) * q] 
	// Expected: 32 pts
	else for(int i=1;i<=q;i++) {
		int x,y;
		cin>>x>>y;
		cout<<dijkstra(x,y)+w[x]+w[y]<<endl;
	}
	
	return 0;
}

void solveA() {
	for(int i=m+1;i<=m+n;i++) {
		auto u=G[i][0],v=G[i][1];
		GA[u.second].push_back({u.first+v.first,v.second});
		GA[v.second].push_back({u.first+v.first,u.second});
	} for(int i=1;i<=q;i++) {
		int x,y;
		cin>>x>>y;
		cout<<dijkstraA(x,y)+w[x]+w[y]<<endl;
	}
}

ll dijkstraA(int x,int y) {	
	vector<bool> vis(n+m+10,0);
	vector<ll> dis(n+m+10,0x3f3f3f3f3f3f3f3f);
	priority_queue<pli,vector<pli>,less<pli> > pq;
	pq.push({0,x});
	vis[x]=1,dis[x]=0;
	while(!pq.empty()) {
		auto now=pq.top();
		pq.pop();
		int nu=now.second;
		for(auto v:GA[nu]) {
			int nv=v.second;
			ll nw=v.first;
			if(vis[nv]) continue; 
			if(dis[nv]>dis[nu]+nw) {
				#ifdef DEBUG
				cerr<<nv<<' '<<nu<<' '<<dis[nu]<<' '<<nw<<endl;
				#endif
				dis[nv]=dis[nu]+nw;
				pq.push({dis[nv],nv});
				if(nv==y) return dis[y];
			}
		}
	} 
	
	#ifdef DEBUG
	for(int i=1;i<=n+m;i++) {
		cerr<<dis[i]<<' ';
	} cout<<endl;
	#endif
	
	return dis[y];
}

ll dijkstra(int x,int y) {	
	vector<bool> vis(n+m+10,0);
	vector<ll> dis(n+m+10,0x3f3f3f3f3f3f3f3f);
	priority_queue<pli,vector<pli>,less<pli> > pq;
	pq.push({0,x});
	vis[x]=1,dis[x]=0;
	while(!pq.empty()) {
		auto now=pq.top();
		pq.pop();
		int nu=now.second;
		for(auto v:G[nu]) {
			int nv=v.second;
			ll nw=v.first;
			if(vis[nv]) continue; 
			if(dis[nv]>dis[nu]+nw) {
				#ifdef DEBUG
				cerr<<nv<<' '<<nu<<' '<<dis[nu]<<' '<<nw<<endl;
				#endif
				dis[nv]=dis[nu]+nw;
				pq.push({dis[nv],nv});
				if(nv==y) return dis[y];
			}
		}
	} 
	
	#ifdef DEBUG
	for(int i=1;i<=n+m;i++) {
		cerr<<dis[i]<<' ';
	} cout<<endl;
	#endif
	
	return dis[y];
}

