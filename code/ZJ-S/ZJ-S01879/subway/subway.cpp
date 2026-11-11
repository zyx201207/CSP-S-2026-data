#include<bits/stdc++.h>
using namespace std;
#define int long long
#define M 500005
#define N 505
#define pii pair<int,int>
#define x first
#define t second
int c,n,m,d,q;
int dis[N][N],w[M];
vector<pii>f[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}for(int i=1;i<=n;++i){
		int k;cin>>k;dis[i][i]=0;
		for(int j=1;j<=k;++j){
			int e,z;cin>>e>>z;
			f[e].push_back({i,z});
		}
	}for(int i=1;i<=m;++i){
		for(const auto &u:f[i]){
			for(const auto &v:f[i]){
				dis[v.x][u.x]=dis[u.x][v.x]=min(dis[u.x][v.x],u.t+v.t);
			}
		}
	}for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(dis[i][j]>dis[i][k]+dis[k][j]){
					dis[i][j]=dis[i][k]+dis[k][j];
				}
			}
		}
	}while(q--){
		int l,r,ans=1e18;
		cin>>l>>r;
		for(const auto &i:f[l]){
			for(const auto &j:f[r]){
				ans=min(ans,dis[i.x][j.x]+i.t+j.t);
			}
		}cout<<ans+w[l]+w[r]<<'\n';
	}
	return 0;
}
