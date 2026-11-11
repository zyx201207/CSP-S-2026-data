#include<bits/stdc++.h>
#define pii pair<int,int>
#define int long long
using namespace std;
const int N=5E5+5;
int c,n,m,d,q;
int w[N];
vector<pii>e[N];
int dis[505][505];
void tomin(int &x,int y){
	if(x>y)x=y;
}
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1; i<=m; i++)
		scanf("%lld",&w[i]);
	for(int i=1,k; i<=n; i++) {
		scanf("%lld",&k);
		for(int j=1,x,y; j<=k; j++) {
			scanf("%lld%lld",&x,&y);
			e[x].push_back({i,y});
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++)dis[i][i] =0;
	for(int i=1; i<=m; i++) {
		for(int j=0; j<e[i].size(); j++) {
			for(int k=0; k<e[i].size(); k++) {
				dis[e[i][j].first][e[i][k].first] = min(dis[e[i][j].first][e[i][k].first], e[i][j].second + e[i][k].second);
			}
		}
	}
	for(int k=1; k<=n; k++) {

		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				tomin(dis[i][j],dis[i][k] + dis[k][j]);
			}
		}
	}
	for(int i=1,x,y;i<=q;i++){
		scanf("%lld%lld",&x,&y);
		int ans= 1e18;
		for(pii j:e[x]){
			for(pii k:e[y]){
			//	cout<<dis[j.first][k.first] <<" "<< j.first <<" "<<k.first<<endl;
				ans=min(ans, dis[j.first][k.first] + j.second + k.second);
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}