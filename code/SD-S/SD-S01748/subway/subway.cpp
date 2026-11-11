#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=5e5+5;
const int INF=1e18;
struct node{
	int to,val;
};
int c,n,m,d,q,w[M],ans=0;
int k,a[M],t[M],x,y,dis[M];
bool vis[M];
vector<node> g[M];
vector<node> stt[M];
void dij(int s){
	for(int i=1;i<=n;i++){
		dis[i]=INF;
		vis[i]=0;
	}
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	dis[s]=0;
	q.push({0,s});
	while(!q.empty()){
		int sx=q.top().first;
		int nw=q.top().second;
		q.pop();
		if(vis[nw]||dis[nw]!=sx)continue;
		for(int i=0;i<g[nw].size();i++){
			int to=g[nw][i].to,val=g[nw][i].val;
			if(dis[nw]+val<dis[to]){
				dis[to]=dis[nw]+val;
				q.push({dis[to],to});
			}
		}	
	}
}signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
			for(int h=0;h<stt[a[j]].size();h++){
				int to=stt[a[j]][h].to;
				int val=stt[a[j]][h].val;
				g[to].push_back({i,val+t[j]});
				g[i].push_back({to,val+t[j]});
			}stt[a[j]].push_back({i,t[j]});
		}
	}while(q--){
		cin>>x>>y;
		ans=INF;
		for(int i=0;i<stt[x].size();i++){
			dij(stt[x][i].to);
			for(int j=0;j<stt[y].size();j++){
				ans=min(ans,dis[stt[y][j].to]+stt[x][i].val+stt[y][j].val);
			}
		}ans+=w[x]+w[y];
		cout<<ans<<"\n";
	}
	return 0;
}
