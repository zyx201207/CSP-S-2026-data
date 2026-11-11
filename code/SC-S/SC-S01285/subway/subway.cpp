#include<bits/stdc++.h>
/*
pts 32 (+16) 
time 16:45
up_date 
- 17:34 build up "bfs" to improve my fenshu
- 17:52 a bug of "dist" be found
*/
using namespace std;
typedef long long ll;
typedef pair<int,int> pt;
const int N = 5e5 + 100 ;
struct node{
	ll to,w;
};
int a[N];
int nt;
vector<node> g[N];
int p[N],k[N];
ll dist[N];
ll T;
vector<int> eg[N];
int c,n,m,d,Q;
priority_queue<pt,vector<pt>,greater<pt> > q;
bool flag;
void bfs(int s,int t){
	queue<int> q;
	memset(dist,0x7f,sizeof(dist));
	dist[s]=0;
	q.push(s);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(auto it:g[u]){
			int v=it.to;
			if(dist[v]>dist[u]+1){
				dist[v]=dist[u]+1;
				q.push(v);
				if(v==t) return ;
			}
		}
	}
}
void dij(int s){
	memset(dist,0x7f,sizeof(dist));
	dist[s]=0;
	q.push({0,s});
	while(!q.empty()){
		auto it=q.top();q.pop();
		int u=it.second;
		if(dist[u]>it.first)	continue;
		for(auto it:g[u]){
			int v=it.to,w=it.w;
			if(dist[v]>dist[u]+w){
				dist[v]=dist[u]+w;
				q.push({dist[v],v});
				
			}
		}
	}
}
int main (){
//	freopen("subway6.in","r",stdin);
//	freopen("subway.ans","w",stdout);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	nt=m;
	for(int i=1,op;i<=n;i++){
		cin>>op;
		for(int j=1;j<=op;j++){
			cin>>p[j]>>k[j];
			if(T==0){
				T=k[j];
			}else{
				if(T!=k[j])	flag=0;
			}
			g[p[j]].push_back({i+m,k[j]});
			g[i+m].push_back({p[j],k[j]});
			//cout<<u<<"<->"<<nt<<"<->"<<nt-1<<"\n";
		}
	}
	if(flag){
		int x,y;
		//	cout<<T<<"\n";
		while(Q--){
			cin>>x>>y;
			bfs(x,y);
			cout<<dist[y]*T+a[x]+a[y]<<"\n";
		}
		return 0;
	}
	int x,y;
	while(Q--){
		cin>>x>>y;
		dij(x);
		cout<<dist[y]+a[x]+a[y]<<"\n";
	}
	return 0;
}
