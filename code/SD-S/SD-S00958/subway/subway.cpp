#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
int c,n,m,d,q;
int a[501000];
int b[510];
vector<pii> sta[501000];
vector<pii> sub[510];
int dis[510][510];
int upd(int u,int v,int w){
	dis[u][v]=min(dis[u][v],w);
	dis[v][u]=min(dis[v][u],w);
}
signed main(){
//	system("fc subway.out subway7.ans");return 0;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
		for(int j=1;j<=b[i];j++){
			int v,t;
			cin>>v>>t;
			sub[i].push_back({v,t});
			sta[v].push_back({i,t});
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++){
		upd(i,i,0);
		for(pii j:sub[i]){
			for(pii k:sta[j.fi]){
				upd(i,k.fi,j.se+k.se);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<k;i++){
			for(int j=1;j<k;j++){
				upd(i,k,dis[i][j]+dis[j][k]);
			}
		}
		for(int i=1;i<k;i++){
			for(int j=1;j<k;j++){
				upd(i,j,dis[i][k]+dis[k][j]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<i<<' '<<j<<' '<<dis[i][j]<<"\n";
//		}
//	}
	while(q--){
		int s,t;
		cin>>s>>t;
		int ans=0x3f3f3f3f3f3f3f3f;
		for(pii i:sta[s]){
			for(pii j:sta[t]){
				ans=min(ans,dis[i.fi][j.fi]+i.se+j.se);
			}
		}
		cout<<ans+a[s]+a[t]<<'\n';
	}
	return 0;
}

