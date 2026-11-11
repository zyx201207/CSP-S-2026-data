#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
int c,n,m,d,q,jv[509][509],w[500009];
vector<pair<int,int> > u[500009];
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int z;cin>>z;
		while(z--){
			int x,y;cin>>x>>y;u[x].push_back(make_pair(i,y));
		}
	}
	memset(jv,0x3f,sizeof jv);
	for(int i=1;i<=n;i++) jv[i][i]=0;
	for(int i=1;i<=m;i++){
		for(pair<int,int> x:u[i]){
			for(pair<int,int> y:u[i]){
				if(x==y) continue;
				jv[x.fi][y.fi]=jv[y.fi][x.fi]=min(jv[x.fi][y.fi],x.se+y.se);
			}
		}
	}
	
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(jv[i][j]>jv[i][k]+jv[k][j]) jv[i][j]=jv[i][k]+jv[k][j];
	while(q--){
		int x,y;cin>>x>>y;
		int ans=1e15;
		for(pair<int,int> xx:u[x]){
			for(pair<int,int> yy:u[y]){
				ans=min(ans,jv[xx.fi][yy.fi]+xx.se+yy.se+w[x]+w[y]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}