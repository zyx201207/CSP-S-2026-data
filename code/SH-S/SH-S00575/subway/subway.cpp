#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=509,M=500009,D=20,Q=100009;
int C,n,m,d,q,w[M];
vector<pair<int,int>> lins[N],stns[M];
pair<int,int> qry[Q];
int&chkmin(int&l,int r){return l=min(l,r);}
/*namespace sol1{
	vector<pair<int,int>> es[N+M];//1~m:stations;m+1~m+n:lines
	int dis[N+M],vis[N+M];
	priority_queue<pair<int,int>> pq;
	void dijkstra(int x,int tg){//O(q(k+n)) 60pts?
		fill(dis+1,dis+n+m+1,2e18);
		fill(vis+1,vis+n+m+1,0);
		while(!pq.empty())pq.pop();
		dis[x]=0;
		pq.push({0,x});
		while(!pq.empty()&&!vis[tg]){
			int u=pq.top().second;
			pq.pop();
			if(vis[u]) continue;
			vis[u]=1;
			for(auto eg:es[u]){
				if(dis[u]+eg.second<dis[eg.first]){
					dis[eg.first]=dis[u]+eg.second;
					pq.push({-dis[eg.first],eg.first});
				}
			}
		}
	}
	void solve(){
		for(int i=1;i<=n;i++){
			for(auto eg:lins[i]){
				es[i+m].push_back(eg);
				es[eg.first].push_back({i+m,eg.second});
			}
		}
		for(int i=1;i<=q;i++){
			if(qry[i].first==qry[i].second){
				cout<<0<<'\n';
				continue;
			}
			dijkstra(qry[i].first,qry[i].second);
			cout<<dis[qry[i].second]+w[qry[i].first]+w[qry[i].second]<<'\n';
		}
	}
}*/
namespace sol2{
	int esl[N][N],ans;
	void solve(){
		memset(esl,0x3f,sizeof(esl));
		for(int i=1;i<=n;i++) esl[i][i]=0;
		for(int i=1;i<=m;i++){
			for(auto egu:stns[i]){
				for(auto egv:stns[i]){
					int u=egu.first,v=egv.first;
					chkmin(esl[u][v],egu.second+egv.second);
				}
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					chkmin(esl[i][j],esl[i][k]+esl[k][j]);
				}
			}
		}
		for(int i=1;i<=q;i++){
			int uu=qry[i].first,vv=qry[i].second;
			if(uu==vv){
				cout<<0<<'\n';
				continue;
			}
			ans=2e18;
			for(auto u:stns[uu]){
				for(auto v:stns[vv]){
					chkmin(ans,u.second+v.second+esl[u.first][v.first]);
				}
			}
			cout<<ans+w[uu]+w[vv]<<'\n';
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,v,w;j<=k;j++){
			cin>>v>>w;
			lins[i].push_back({v,w});
			stns[v].push_back({i,w});
		}
	}
	for(int i=1;i<=q;i++) cin>>qry[i].first>>qry[i].second;
	sol2::solve();
	return 0;
}
