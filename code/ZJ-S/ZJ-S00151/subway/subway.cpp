#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,w[500005];
vector<pair<int ,int > >vec[500005];
int fl[505][505],mp[505][505],k[505];
signed main() {
	ios::sync_with_stdio(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1; i<=m; i++)scanf("%lld",&w[i]);
	for(int i=1; i<=n; i++) {
		scanf("%lld",&k[i]);
		for(int j=1; j<=k[i]; j++) {
			int v,w;
			scanf("%lld%lld",&v,&w);
			vec[v].push_back({i,w});
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++)mp[i][j]=1145141919810;
		mp[i][i]=0;
	}
	for(int i=1; i<=m; i++) {
		for(int j=0; j<vec[i].size(); j++) {
			for(int k=j+1; k<vec[i].size(); k++) {
				int u=vec[i][j].first,w1=vec[i][j].second,v=vec[i][k].first,w2=vec[i][k].second;
				mp[u][v]=min(mp[u][v],w1+w2);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			mp[i][j]=min(mp[i][j],mp[j][i]);
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			for(int k=1; k<=n; k++) {
				if(mp[i][k]+mp[j][k]<mp[i][j])mp[i][j]=mp[i][k]+mp[j][k];
			}
		}
	}
	for(int i=1; i<=q; i++) {
		int u,v,ans=1145141919810;
		scanf("%lld%lld",&u,&v);
		for(int j=0; j<vec[u].size(); j++) {
			for(int k=0; k<vec[v].size(); k++) {
				ans=min(ans,vec[u][j].second+vec[v][k].second+mp[vec[u][j].first][vec[v][k].first]);
			}
		}
		printf("%lld\n",ans+w[u]+w[v]);
	}
	return 0;
}
