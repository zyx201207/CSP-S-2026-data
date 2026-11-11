#include<bits/stdc++.h>
#define N 500005
#define int long long
#define pi pair<int,int>
using namespace std;
int c,n,m,d,q,w[N],dis[505][505];
vector<pi>g[N],df[N],qwq[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)cin>>w[i];
	for(int i=1;i<=n;++i){
		int k;cin>>k;
		for(int j=1;j<=k;++j){
			int x,t;cin>>x>>t;
			g[i].push_back({x,t});
			qwq[x].push_back({i,t});
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;++i)dis[i][i]=0;
	for(int i=1;i<=n;++i){
		for(pi c:g[i]){
			for(pi tmp:df[c.first]){
				dis[tmp.second][i]=min(dis[tmp.second][i],tmp.first+c.second);
			}
			df[c.first].push_back({c.second,i});
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)dis[i][j]=min(dis[i][j],dis[j][i]);
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int x,y;cin>>x>>y;
		int ans=4e18;
		for(pi i:qwq[x]){
			for(pi j:qwq[y]){
				ans=min(ans,dis[i.first][j.first]+i.second+j.second);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
