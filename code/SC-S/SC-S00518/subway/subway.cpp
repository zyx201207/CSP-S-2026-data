#include<bits/stdc++.h>
#define int long long
using namespace std;
int w[500005],k[500005],a[505][505],t[505][505],vis[500005];
struct node{
	int zt,ti;
};
int c,n,m,d,q,mi=1e9;
void solve(){
	int x,y;
	cin>>x>>y;
	queue<node> qe; //站台，时间 
	qe.push({x,w[x]});
	while(qe.size()){
		int zt=qe.front().zt;
		int ti=qe.front().ti;
		qe.pop();
		if(zt==y){
			mi=min(mi,ti+w[y]);
//			return;
		}
		if(vis[zt]==1){
			continue;
		}
		vis[zt]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				if(a[i][j]==zt){
					for(int l=1;l<=k[i];l++){
						if(l!=j){
							qe.push({a[i][l],ti+t[i][j]+t[i][l]});
						}
					}
				}
			}
		}
	}
}
signed main(){
	ios_base :: sync_with_stdio(0);
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
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		solve();
		cout<<mi<<'\n';
		mi=1e9;
		memset(vis,0,sizeof(vis));
	}
	return 0;
}