#include <bits/stdc++.h>
using namespace std;
int cc,m,n,d,q;
long long dis[1010][1010];
int w[500010];
int a[500010],t[500010];
vector<int> aa[500010],tt[500010];
struct node{
	int to,val;
};
vector<node> vt[1010];
bool vis[1010];
vector<int> c[500010];
void solve1(){
	for(int i=1;i<=m;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
		}
		for(int j1=1;j1<=k;j1++){
			for(int j2=1;j2<=k;j2++){
				if(j1!=j2){
					vt[a[j1]].push_back({a[j2],t[j1]+t[j2]});
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=1e18;
		}
	}
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
		for(int j=1;j<=n;j++) vis[j]=0;
		priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > >pq;
		pq.push({0,i});
		while(!pq.empty()){
			int u=pq.top().second;
			pq.pop();
			if(vis[u]) continue;
			vis[u]=1;
			for(int j=0;j<vt[u].size();j++){
				int to=vt[u][j].to,val=vt[u][j].val;
				if(dis[i][to]>dis[i][u]+1ll*val){
					dis[i][to]=dis[i][u]+1ll*val;
					pq.push({dis[i][to],to});
				}
			}
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		cout<<dis[u][v]+1ll*w[u]+1ll*w[v]<<'\n';
	}
}
long long b[500010];
int T;
vector<pair<int,int> > ask[500010];
long long ans[500010];
bool bj[510];
void solve2(){
	for(int i=1;i<=m;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
			aa[i].push_back(a[j]);
			tt[i].push_back(t[j]);
			T=t[j];
			c[a[j]].push_back(i); 
		}
	}
//	cout<<T<<'\n';
	for(int i=1;i<=q;i++){
		int u,v;
		cin>>u>>v;
		if(u>v) swap(u,v);
		ask[u].push_back({v,i});
	}
	for(int _=1;_<=n;_++){
		if(ask[_].size()){
			for(int i=1;i<=n;i++) b[i]=1e18;
			b[_]=0;
			queue<int> q;
			q.push(_);
			memset(bj,0,sizeof(bj));
			while(!q.empty()){
				int u=q.front();
				q.pop();
				for(int i=0;i<c[u].size();i++){
					if(!bj[c[u][i]]){
						for(int j=0;j<aa[c[u][i]].size();j++){
							if(b[aa[c[u][i]][j]]==1e18){
								b[aa[c[u][i]][j]]=b[u]+1;
								q.push(aa[c[u][i]][j]);
							}
						}
						bj[c[u][i]]=1;
					}
				}
			}
			for(int j=0;j<ask[_].size();j++){
//				cout<<b[ask[i][j].first]*2ll*T<<'\n';
				ans[ask[_][j].second]=b[ask[_][j].first]*2ll*T+w[_]+w[ask[_][j].first];
			}
		}
	}
	for(int i=1;i<=q;i++) cout<<ans[i]<<'\n';
}
struct node2{
	bool p;
	int t;
}jl[500010][3];
void solve3(){
	for(int i=1;i<=m;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
			jl[a[j]][i].p=1;
			jl[a[j]][i].t=t[j];
		}
	}
	int mi=2e9;
	for(int i=1;i<=n;i++){
		if(jl[i][1].p&&jl[i][2].p) mi=min(mi,jl[i][1].t+jl[i][2].t);
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		long long ans=1e18;
		for(int i=1;i<=m;i++){
			if(jl[u][i].p&&jl[v][i].p) ans=min(ans,1ll*jl[u][i].t+1ll*jl[v][i].t);
		}
		if(m==2){
			if(jl[u][1].p&&jl[v][2].p) ans=min(ans,1ll*jl[u][1].t+1ll*jl[v][2].t+1ll*mi);
			if(jl[u][2].p&&jl[v][1].p) ans=min(ans,1ll*jl[u][2].t+1ll*jl[v][1].t+1ll*mi);			
		}
		cout<<ans+1ll*w[u]+1ll*w[v]<<'\n';
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	cin>>cc>>m>>n>>d>>q;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	if(cc<=11){
		solve1();
	}else if(cc<=19){
		solve2();
	}else solve3();
	return 0;
}

