#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr first
#define sc second
using namespace std;
const int M=5e5+5,N=505;
const ll inf=1e18;
int c,n,m,d,q;
int w[M];
ll dx[N][N];
vector<pair<int,int> >e[M];
void solve(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) dx[i][j]=inf;
		dx[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		if(e[i].empty()) continue;
		for(auto&u:e[i]){
			for(auto&v:e[i]) dx[u.fr][v.fr]=min(dx[u.fr][v.fr],(ll)u.sc+v.sc);
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) dx[i][j]=min(dx[i][j],dx[i][k]+dx[k][j]);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int u,tx;
			cin>>u>>tx;
			e[u].pb({i,tx});
		}
	}
	solve();
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<i<<" "<<j<<":"<<dx[i][j]<<"\n";
		}
	}*/
	//fc subway7.out subway7.ans
	while(q--){
		int x,y;
		cin>>x>>y;
		ll ans=inf;
		for(auto&ux:e[x]){
			for(auto&uy:e[y]){
				ans=min(ans,dx[ux.fr][uy.fr]+ux.sc+uy.sc);
				//cout<<ux.fr<<" "<<uy.fr<<" "<<dx[ux.fr][uy.fr]<<" "<<ux.sc<<" "<<uy.sc<<"\n";
			}
		}
		ans+=(w[x]+w[y]);
		cout<<ans<<"\n";
	}
	return 0;
	//15:58
	/*
	Oh,I think my solution will be TLE, the O(md^2+n^3+qd^2) isn't a right solution.
	Maybe I can get 68~76 pts? Or...
	*/
}
