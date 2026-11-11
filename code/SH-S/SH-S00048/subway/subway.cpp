#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[500005],dis[505][505],k[505];
vector<pair<int,int> > G[500005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=0x3f3f3f3f3f3f3f3f;
			if(i==j) dis[i][i]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	for(int i=1;i<=n;i++){
		cin >> k[i];
		for(int j=1;j<=k[i];j++){
			int a,t;
			cin >> a >> t;
			G[a].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++){
		for(auto u : G[i]){
			for(auto v : G[i]){
				if(u.first==v.first) continue;
				dis[u.first][v.first]=min(dis[u.first][v.first],u.second+v.second);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int x,y,minn=0x3f3f3f3f3f3f3f3f;
		cin >> x >> y;
		for(auto u:G[x]){
			for(auto v:G[y]){
				minn=min(minn,dis[u.first][v.first]+u.second+v.second);
			}
		}
		cout << minn+w[x]+w[y] << endl;
	}
	return 0;
} 
