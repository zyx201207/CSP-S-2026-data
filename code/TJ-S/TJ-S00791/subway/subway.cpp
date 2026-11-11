#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[514514],k[505],maxx;
int dis[21015][505];
vector<int> t[505],a[505];
vector<pair<int,int> > g[21145][505],sg[514514];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}for(int i=1;i<=n;i++){
		cin>>k[i];
		t[i].resize(k[i]+10);a[i].resize(k[i]+10);
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			sg[a[i][j]].push_back({i,t[i][j]});
			
		}for(int j=1;j<=k[i];j++){
			for(int jj=1;jj<=k[i];jj++)g[a[i][j]][i].push_back({a[i][jj],t[i][jj]});
		}
	}
	while(q--){
		int b,e;
		cin>>b>>e;
		memset(dis,0x3f3f,sizeof(dis));
		queue<pair<int,int> > que;
		for(int i=0;i<sg[b].size();i++){
			que.push({b,sg[b][i].first});
			dis[b][sg[b][i].first]=sg[b][i].second;
		}
		while(!que.empty()){
			int u=que.front().first,l=que.front().second;
			que.pop();
			for(int i=0;i<g[u][l].size();i++){
				int v=g[u][l][i].first,ti=g[u][l][i].second;
				if(dis[u][l]+ti<=dis[v][l]){
					dis[v][l]=dis[u][l]+ti;
					que.push({v,l});
				}
			}for(int i=0;i<sg[u].size();i++){
				if(dis[u][l]+sg[u][i].second<=dis[u][sg[u][i].first]){
					dis[u][sg[u][i].first]=dis[u][l]+sg[u][i].second;
					que.push({u,sg[u][i].first});
				}
			}
		}int minn=LLONG_MAX;
		for(int i=1;i<=n;i++){
			minn=min(minn,dis[e][i]);	
		}cout<<w[b]+w[e]+minn<<endl;
	}
	return 0;
}
