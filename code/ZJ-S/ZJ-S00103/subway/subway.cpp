#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
const ll N=550;
const ll K=5e5+50;
ll c,n,m,d,q,w[K],k[N],a,t,ans,dis[N][N];
vector<pair<ll,ll> >b[K];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a>>t;
			b[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=1e15;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(auto j:b[i]){
			for(auto l:b[i]){
				dis[j.fi][l.fi]=min(dis[j.fi][l.fi],j.se+l.se);
			}
		}
	}
	for(int l=1;l<=n;l++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][l]+dis[l][j]);
			}
		}
	}
	ll x,y;
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		ans=1e15;
		for(auto u:b[x]){
			for(auto v:b[y]){
				ans=min(ans,w[x]+u.se+dis[u.fi][v.fi]+v.se+w[y]);
			}
		}
		printf("%lld\n",ans);
	}
}
