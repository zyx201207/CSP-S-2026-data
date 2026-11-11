#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pa;
#define M 500614
#define N 514 
const ll inf=2893606913523066920;
ll a[M];
vector<int> id[N];//过了那座地铁站序列 
vector<ll> t[N];
struct edge {//链式 
	int nxt,to;
	ll val;
}e[2*M];
int hd[M+N];
int nE=0;
void addedge(int u,int v,ll w) {
	e[++nE]=(edge){hd[u],v,w};
	hd[u]=nE;
} 
ll dist[1502][1502];//极限
ll dist2[50502]; 
bool vis[50502];
queue<int> q;
priority_queue<pa,vector<pa>,greater<pa> > q2;//使得最小靠前 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int cid,n,m,D,Q;
	cin>>cid>>n>>m>>D>>Q;
	for(int i=1;i<=m;i++) {//与路径选择无关变量 
		cin>>a[i];
	}
	int nu=-1;
	bool issame=true;
	for(int i=1;i<=n;i++) {
		int ki;
		cin>>ki;
		for(int j=1;j<=ki;j++) {
			id[i].push_back(0);
			t[i].push_back(0); 
			cin>>id[i][j-1]>>t[i][j-1];
			if(nu==-1||nu==t[i][j-1]) nu=t[i][j-1];
			else issame=false;
		}
	}
	
	//建边：站连线
	for(int i=1;i<=n;i++) {
		for(int j=0;j<id[i].size();j++) {
			addedge(i+m,id[i][j],t[i][j]);
			addedge(id[i][j],i+m,t[i][j]);
		}
	}
	
	if(issame) {//边权相同，特殊性质，广搜就行 
		while(Q--) {
			int x,y;
			cin>>x>>y;
			q.push(x);
			for(int i=1;i<=n+m;i++) {
				dist2[i]=inf;
				vis[i]=false;
			}
			dist2[x]=0;
			vis[x]=true;
			while(not(q.empty())) {
				int u=q.front();
				q.pop();
				for(int i=hd[u];i!=0;i=e[i].nxt) {
					int v=e[i].to;
					ll w=e[i].val;
					if(dist2[u]+w<dist2[v]) {
						dist2[v]=dist2[u]+w;
						if(not(vis[v])) {
							vis[v]=true;
							q.push(v); 
						}
					} 
				} 
			}
			cout<<dist2[y]+a[x]+a[y]<<"\n";
		}
		return 0;
	} 
	//其他情况 dijkstra堆优化 
	for(int i=1;i<=m+n;i++) {
		for(int j=1;j<=m+n;j++) {
			dist[i][j]=inf;
		}
	}
	for(int x=1;x<=m;x++) {
		q2.push(make_pair(0,x));
		dist[x][x]=0;
		while(not(q2.empty())) {
			int u=q2.top().second;
			ll va=q2.top().first;
			q2.pop();
			if(va>dist[x][u]) continue;
			for(int i=hd[u];i!=0;i=e[i].nxt) {
				int v=e[i].to;
				ll w=e[i].val;
				if(dist[x][u]+w<dist[x][v]) {
					dist[x][v]=dist[x][u]+w;
					q2.push(make_pair(dist[x][v],v));
				} 
			} 
		}
	}
	while(Q--) {
		int x,y;
		cin>>x>>y;
		cout<<a[x]+dist[x][y]+a[y]<<"\n";
	}
	return 0;
} 
