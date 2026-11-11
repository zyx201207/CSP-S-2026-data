#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e2+5,M=5e5+5,KK=1e3+5;
int n,m,T,C,d,W[M],k[N],TT,viss[N];
struct NODE{int id,t;};
vector<NODE>e[N],g[M];
int dis[KK][KK],dis2[N][N];
bool bjj[M];
struct Pri{
	int z,id;
	bool operator < (const Pri& x)const {
		return z>x.z;
	}
};
priority_queue<Pri>q;
Pri xx;
int u,z;
void dijk(int now) {
	q.push({0ll,now}),dis[now][now]=0;
	while(q.size()) {
		xx=q.top();q.pop();
		u=xx.id,z=xx.z;
		if(z!=dis[now][u]) continue;
		// cout<<u<<' '<<z<<'\n';
		for(auto zz:g[u]) {
			for(auto dd:e[zz.id]) {
				if(dis[now][dd.id]>dis[now][u]+zz.t+dd.t) {
					
					dis[now][dd.id]=dis[now][u]+zz.t+dd.t;
					// cout<<now<<' '<<dd.id<<' '<<dis[now][dd.id]<<"from:"<<u<<'\n'; 
					q.push({dis[now][dd.id],dd.id});
				}
			}
		}
		// for(int i=1;i<=m;i++) cout<<dis[now][i]<<" \n"[i==m];
	}
	// for(int i=1;i<=m;i++) cout<<dis[now][i]<<" \n"[i==m];
	// cerr<<"__________\n";
}
void solve1(){
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=m;i++) {dijk(i);}
	while(T--){
		int u,v;
		cin>>u>>v;
		cout<<dis[u][v]+W[u]+W[v]<<'\n';
	}
}
void dijk3(int now){
	q.push({0ll,now});dis2[now][now]=0;
	memset(viss,0,sizeof viss);
	while(q.size()) {
		xx=q.top();q.pop();
		u=xx.id,z=xx.z;
		viss[u]=0;
//		 cout<<u<<' '<<z<<'\n';
		for(auto dd:e[u]){//dd
			// cout<<u<<' '<<dd.id<<' '<<now<<":\n";
			if(bjj[dd.id]==now) continue;
			bjj[dd.id]=now;
			for(auto ww:g[dd.id]){//k
				if(ww.id==u) continue; 
				// cout<<ww.id<<' '<<u<<' '<<dis2[now][ww.id]<<'\n';
				if(dis2[now][ww.id]>dis2[now][u]+ww.t+dd.t){
					dis2[now][ww.id]=dis2[now][u]+ww.t+dd.t;
					if(!viss[ww.id])q.push({dis2[now][ww.id],ww.id});
					viss[ww.id]=1;
				}
			}
		}
	}
	
}
void solve3(){
	memset(dis2,0x3f,sizeof dis2);
	for(int i=1;i<=n;i++) 
		dijk3(i);
	// for(int i=1;i<=n;i++)
	// 	for(int j=1;j<=n;j++) cout<<dis2[i][j]<<" \n"[j==n];
	while(T--){
		int u,v;
		cin>>u>>v;int anss=1e18;
		for(auto i:g[u])
			for(auto j:g[v]) 
				anss=min(anss,i.t+j.t+dis2[i.id][j.id]);
		cout<<W[u]+W[v]+anss<<'\n';
	}
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin.sync_with_stdio();
	cout.sync_with_stdio(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>C>>n>>m>>d>>T;
	for(int i=1;i<=m;i++) cin>>W[i];
	for(int i=1;i<=n;i++) {
		cin>>k[i];
		for(int j=1,z,t;j<=k[i];j++) {
			cin>>z>>t;TT=t;
			e[i].push_back({z,t});
			g[z].push_back({i,t});
		}
	}
	if(C<=11)solve1();
	else solve3();
	return 0;
}