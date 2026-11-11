#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
const int N=5e5+5,M=505;
int f[M][M],c,n,m,d,q,w[N];
vector<pair<int,int> > vec[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	memset(f,0x3f,sizeof f);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;cin>>k;f[i][i]=0;
		for(int j=1;j<=k;j++){
			int a,t;cin>>a>>t;
			vec[a].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++){
		for(auto j:vec[i]){
			for(auto k:vec[i]){
				f[j.fi][k.fi]=min(f[j.fi][k.fi],k.se+j.se);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--){
		int x,y;cin>>x>>y;int ans=1e18;
		for(auto j:vec[x]){
			for(auto k:vec[y]){
				ans=min(ans,j.se+k.se+f[j.fi][k.fi]);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}

