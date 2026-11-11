#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pr pair<int,int>
#define vi vector<int>
#define vp vector<pr>
#define pb push_back
#define fi first
#define se second
#define N 500010
#define M 510
#define inf ((long long)(1e18))
int c,n,m,d,q,w[N],dis[M][M],k,a,len,x,y,ans,tt;
vp g[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		while(k--){
			cin>>a>>len;
			g[a].pb({len,i});
		}
	}
	memset(dis,0x3f3f3f,sizeof(dis));
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<=(long long)(g[i].size()-1);j++){
			for(int k=j+1;k<=(long long)(g[i].size()-1);k++){
				int p1=g[i][j].se,p2=g[i][k].se,len=g[i][j].fi+g[i][k].fi;
				dis[p1][p2]=min(dis[p1][p2],len);
				dis[p2][p1]=min(dis[p2][p1],len);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
			}
		}
	}
	while(q--){
		ans=inf;
		cin>>x>>y;
		for(int i=0;i<=(long long)(g[x].size()-1);i++){
			for(int j=0;j<=(long long)(g[y].size()-1);j++){
				ans=min(ans,dis[g[x][i].se][g[y][j].se]+g[x][i].fi+g[y][j].fi);tt++;
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}