#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N=500010;
const int M=510;
int c,n,m,d,q;
ll w[N],dis[M][M];
vector<pair<ll ,ll > > sub[N];
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i!=j) dis[i][j]=1e18;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,a,t;j<=k;j++){
			cin>>a>>t;
			sub[a].emplace_back(i,t);
		}
	}
	for(int i=1;i<=m;i++){
		for(const auto& x:sub[i]){
			for(const auto& y:sub[i]){
				if(x.first==y.first) continue;
				dis[x.first][y.first]=min(dis[x.first][y.first],x.second+y.second);
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
		int x,y;
		ll ans=1e18;
		cin>>x>>y;
		for(const auto& u:sub[x]){
			for(const auto& v:sub[y]){
				ans=min(ans,u.second+dis[u.first][v.first]+v.second);
			}
		}
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}
