#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
// #define int ll
namespace leo{
	constexpr int N=500005,M=505;;
	int c,n,m,d,q;
	ll w[N],f[M][M];
	vector<pair<int,ll> >ls[N];
	void solve(){
		cin>>c>>n>>m>>d>>q;
		for(int i=1;i<=m;i++)cin>>w[i];
		for(int i=1,k;i<=n;i++){
			cin>>k;int x;ll y;
			for(int j=1;j<=k;j++){
				cin>>x>>y;
				ls[x].push_back({i,y});
			}
		}
		memset(f,0x3f,sizeof(f));
		for(int i=1;i<=m;i++){
			int k=(int)ls[i].size();
			for(int x=0;x<k;x++){
				int xi=ls[i][x].first,yi;ll xw=ls[i][x].second,yw;
				for(int y=x+1;y<k;y++){
					yi=ls[i][y].first,yw=ls[i][y].second;
					if(xw+yw<f[xi][yi]){
						f[xi][yi]=f[yi][xi]=xw+yw;
					}
				}
			}
		}
		for(int i=1;i<=n;i++)f[i][i]=0;
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
		while(q--){
			int x,y;cin>>x>>y;
			ll ans=0x3f3f3f3f3f3f3f3f;
			for(pair<int,ll>p1:ls[x])
				for(pair<int,ll>p2:ls[y])
					ans=min(ans,p1.second+p2.second+f[p1.first][p2.first]);
			cout<<ans+w[x]+w[y]<<'\n';
		}
	}
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	leo::solve();
}
