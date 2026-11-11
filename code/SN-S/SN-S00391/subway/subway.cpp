#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,D,q;
vector<pair<int,int> > vc[500005];
int w[500005];
int d[505][505];
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>D>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;cin>>a>>t;
			vc[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i!=j) d[i][j]=1e16;
	for(int i=1;i<=m;i++){
		for(auto j:vc[i]){
			int x=j.first,xt=j.second;
			for(auto k:vc[i]){
				int y=k.first,yt=k.second;
				if(x==y) continue;
				d[x][y]=d[y][x]=min(d[x][y],xt+yt);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
		}
	}
	while(q--){
		int x,y;cin>>x>>y;
		int ans=1e16;
		for(auto xx:vc[x]){
			int i=xx.first,ti=xx.second;
			for(auto yy:vc[y]){
				int j=yy.first,tj=yy.second;
				ans=min(ans,d[i][j]+ti+tj);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
