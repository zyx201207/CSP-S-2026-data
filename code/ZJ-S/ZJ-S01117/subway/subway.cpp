#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,qp,xx,yy;
int w[500100],k[520],dis[520],rd[520][520];
bool vis[520];
vector<pair<int,int> >g[520],djt[500100];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
void dij(int st){
	memset(vis,0,sizeof vis);
	memset(dis,0x7f,sizeof dis);
	q.push({0,st});
	dis[st]=0;
	while(!q.empty()){
		int x=q.top().second;
		q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=0;i<g[x].size();i++){
			int nx=g[x][i].second;
			int cost=g[x][i].first;
			if(dis[nx]>dis[x]+cost){
				dis[nx]=dis[x]+cost;
				q.push({dis[nx],nx});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(rd,0x7f,sizeof rd);
	cin>>c>>n>>m>>d>>qp;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>xx>>yy;
			djt[xx].push_back({i,yy});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<djt[i].size();j++){
			for(int jj=j+1;jj<djt[i].size();jj++){
				int dt1=djt[i][j].first;
				int dt2=djt[i][jj].first;
				int cost=djt[i][j].second+djt[i][jj].second;
				g[dt1].push_back({cost,dt2});
				g[dt2].push_back({cost,dt1});
			}
		}
	}
	for(int i=1;i<=n;i++){
		dij(i);
		for(int j=1;j<=n;j++) rd[i][j]=dis[j];
	}
	for(int i=1;i<=qp;i++){
		cin>>xx>>yy;
		int minn=1e18;
		for(int j=0;j<djt[xx].size();j++){
			for(int jj=0;jj<djt[yy].size();jj++){
				int dt1=djt[xx][j].first;
				int dt2=djt[yy][jj].first;
				minn=min(minn,rd[dt1][dt2]+djt[xx][j].second+djt[yy][jj].second);
			}
		}
		cout<<minn+w[xx]+w[yy]<<"\n";
	}
}
