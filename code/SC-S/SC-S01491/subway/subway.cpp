#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pil=pair<int,ll>;
const int N=505,M=5e5+5;
int c,n,m,d,q,w[M],k[N],cnt[M];
ll ans;
struct node{ int a; ll t; };
struct lineInfo{ int e; ll t; };
vector<node> line[N];
vector<lineInfo> station[M];
ll sameLine(int x,int y){
	ll cost=1e18; bool f=0;
	for(auto i:station[x]){
		for(auto j:station[y]){
			if(i.e==j.e){
				f=1;
				cost=min(cost,i.t+j.t);
			}
		}
	}
	if(f) return cost;
	return 0;
}
int transPoint[M],p;
vector<pil> transGraph[M];
vector<pil> temp[M];
int sz[M];
ll dist[M];
bool vis[M];
void connect(int x,int y){
	ll sL=sameLine(x,y);
	if(sL){
		transGraph[x].push_back({y,sL});
		transGraph[y].push_back({x,sL});
	}
}
vector<pil> edge[M];
inline int read(){
	int x=0,f=1; char c=getchar();
	if(c>='0'&&c<='9') x=x*10+c-'0';
	else if(c=='-') f=-1;
	return x*f;
}
void solveA(){
	for(int i=1;i<=n;i++){
		cin>>k[i];
		int a1,a2,t1,t2;
		if(k[i]==1){
			a1=read(); a2=read();
			continue;
		}
		a1=read(); t1=read(); a2=read(); t2=read();
		edge[a1].push_back({a2,t1+t2});
		edge[a2].push_back({a1,t1+t2}); 
	}
	while(q--){
		int x,y;
		x=read(); y=read();
		ans=w[x]+w[y];
		memset(dist,0x3f,sizeof(dist));
		memset(vis,0,sizeof(vis));
		priority_queue<pil,vector<pil>,greater<pil>> q;
		dist[x]=0; q.push({0,x});
		while(q.size()){
			int u=q.top().second; q.pop();
			vis[u]=1;
			for(auto e:edge[u]){
				int v=e.first;
				ll w=e.second;
				if(dist[v]>dist[u]+w){
					dist[v]=dist[u]+w;
					if(!vis[v]){
						q.push({dist[v],v});
					}
				}
			} 
		}
		cout<<ans+dist[y]<<'\n';
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	if(7<=c&&c<=11){
		solveA();
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int a,t; cin>>a>>t;
			line[i].push_back({a,t});
			station[a].push_back({i,t});
			cnt[a]++;
			if(cnt[a]==2){
				transPoint[++p]=a;
			}
		}
	}
	for(int i=1;i<=p;i++){
		for(int j=i+1;j<=p;j++){
			int x=transPoint[i],y=transPoint[j];
			connect(x,y);
		}
		sz[i]=transGraph[i].size();
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ans=w[x]+w[y];
		ll sL=sameLine(x,y);
		if(sL){
			cout<<ans+sL<<'\n';
			continue;
		}
		int tot=0;
		if(cnt[x]==1){
			int lx=station[x][0].e;
			for(int i=0;i<line[lx].size();i++){
				int a=line[lx][i].a;
				if(cnt[a]>1){
					temp[++tot]=transGraph[a];
					connect(a,x);
				}
			}
		}
		if(cnt[y]==1){
			int ly=station[y][0].e;
			for(int i=0;i<line[ly].size();i++){
				int a=line[ly][i].a;
				if(cnt[a]>1){
					temp[++tot]=transGraph[a];
					connect(a,y);
				}
			}
		}
		priority_queue<pil,vector<pil>,greater<pil>> pq;
		memset(dist,0x3f,sizeof(dist));
		memset(vis,0,sizeof(vis));
		dist[x]=0; pq.push({0,x});
		while(pq.size()){
			int u=pq.top().second; pq.pop();
			vis[u]=1;
			for(auto e:transGraph[u]){
				int v=e.first;
				ll wt=e.second;
				if(dist[v]>dist[u]+wt){
					dist[v]=dist[u]+wt;
					if(!vis[v]){
						pq.push({dist[v],v});
					}
				}
			}
		}
		cout<<ans+dist[y]<<'\n';
		tot=0;
		if(cnt[x]==1){
			int lx=station[x][0].e;
			for(int i=0;i<line[lx].size();i++){
				int a=line[lx][i].a;
				if(cnt[a]>1){
					transGraph[a]=temp[++tot];
				}
			}
		}
		if(cnt[y]==1){
			int ly=station[y][0].e;
			for(int i=0;i<line[ly].size();i++){
				int a=line[ly][i].a;
				if(cnt[a]>1){
					transGraph[a]=temp[++tot];
				}
			}
		}
	}
	return 0;
}