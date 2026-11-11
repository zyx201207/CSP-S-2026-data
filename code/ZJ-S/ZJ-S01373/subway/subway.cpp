#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
int dis[404][404];
struct E{
	int v,w;
	bool operator<(const E& other)const{
		return w>other.w;
	}
};

vector<E> g[404];
int w[404],a[404][404],t[404][404];
void dj(int start){
	vector<int> vis(m+1,0);
	priority_queue<E> q;
	q.push({start,0});
	dis[start][start]=0;
	while(q.size()){
		E t=q.top();
		q.pop();
		if(vis[t.v])continue;
		vis[t.v]=1;
		for(int j=0;j<g[t.v].size();++j){
			E i=g[t.v][j];
			if(vis[i.v])continue;
			if(dis[start][t.v]+i.w<dis[start][i.v]){
				dis[start][i.v]=dis[start][t.v]+i.w;
				q.push({i.v,dis[start][i.v]});
			}
		}
	}
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(c<=8){
		for(int i=1;i<=m;++i)cin>>w[i];
		memset(dis,0x3f,sizeof(dis));
		for(int i=1;i<=n;++i){
			int k;
			cin>>k;
			for(int j=1;j<=k;++j){
				cin>>a[i][j]>>t[i][j];
			}
			for(int j=1;j<=k;++j){
				for(int kk=1;kk<=k;++kk){
					if(j==kk){
						dis[a[i][j]][a[i][kk]]=0;
						continue;
					}
					dis[a[i][j]][a[i][kk]]=min(dis[a[i][j]][a[i][kk]],t[i][j]+t[i][kk]);
				}
			}
		}
		for(int i=1;i<=m;++i){
			for(int j=1;j<=m;++j){
				if(i==j||dis[i][j]==0x3f3f3f3f3f3f3f3f)continue;
				g[i].push_back({j,dis[i][j]});
				g[j].push_back({i,dis[i][j]});
			}
		}
		memset(dis,0x3f,sizeof(dis));
		for(int i=1;i<=m;++i){
			dj(i);
		}
		while(q--){
			int x,y;
			cin>>x>>y;
			cout<<dis[x][y]+w[x]+w[y]<<'\n';
		}
		return 0;
	}
	return 0;
}
