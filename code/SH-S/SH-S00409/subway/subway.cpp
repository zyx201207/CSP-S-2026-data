#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
#define mkp make_pair 
using namespace std;
int Test,n,m,d,q,xx,yy,b,c;
const int N=5e2,M=5e5,inf=1e17;
int a[M+10],k[N+10];
vector<pii> mp[M+10];
int Dis[N+10][N+10];
signed main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>Test>>n>>m>>d>>q;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			if(i!=j) Dis[i][j]=inf;
		}
	}
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++) {
		cin>>k[i];
		for(int j=1;j<=k[i];j++) {
			cin>>b>>c;
			mp[b].push_back(mkp(i,c));
		}
	} for(int i=1;i<=m;i++) {
		for(int j1=0;j1<mp[i].size();j1++) {
			for(int j2=0;j2<mp[i].size();j2++) {
				int dis=mp[i][j1].se+mp[i][j2].se,x=mp[i][j1].fi,y=mp[i][j2].fi;
				Dis[x][y]=min(Dis[x][y],dis);
				Dis[y][x]=min(Dis[y][x],dis);
			}
		}
	} for(int kk=1;kk<=n;kk++) {
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) {
				Dis[i][j]=min(Dis[i][kk]+Dis[kk][j],Dis[i][j]);
			}
		}
	}while(q--) {
		cin>>xx>>yy; int ans=inf;
		for(int j1=0;j1<mp[xx].size();j1++) {
			for(int j2=0;j2<mp[yy].size();j2++) {
				int dis=mp[xx][j1].se+mp[yy][j2].se,x=mp[xx][j1].fi,y=mp[yy][j2].fi;
				ans=min(ans,dis+Dis[x][y]);
			}
		} cout<<ans+a[xx]+a[yy]<<'\n';
	}
	return 0;
} 
