#include<bits/stdc++.h>
#define ll long long
#define maxn 507
#define maxx 500007
using namespace std;
int c,n,m,d,q,s[maxn];
int x,sp,tp;
ll y,w[maxx],dis[maxn][maxn];
vector<pair<int,ll> > p[maxn],p1[maxx];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=1e16;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>s[i];
		for(int j=1;j<=s[i];j++){
			cin>>x>>y;
			p[i].push_back({x,y});
			p1[x].push_back({i,y});
		}
	}
	for(int i=1;i<=n;i++){
		for(auto vis:p[i]){
			for(auto vit:p1[vis.first]){
				int v=vit.first;
				ll l=vis.second+vit.second;
				dis[i][v]=min(dis[i][v],l);
				dis[v][i]=min(dis[v][i],l);
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
	for(int i=1;i<=q;i++){
		cin>>sp>>tp;
		ll ans=1e16;
		for(auto u:p1[sp]){
			for(auto v:p1[tp]){
				ans=min(ans,dis[u.first][v.first]+u.second+v.second+w[sp]+w[tp]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}