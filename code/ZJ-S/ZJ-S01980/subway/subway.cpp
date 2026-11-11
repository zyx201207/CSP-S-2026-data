#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define ff first
#define ss second
const ll inf=1e18;
const int N=5e5+10,M=505;
ll dis[M][M],t0[N];
vector<pii>li[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(0);
	int cid,n,m,d,q;cin>>cid>>n>>m>>d>>q;//clock_t st=clock();
	for(int i=1;i<=m;i++) cin>>t0[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) dis[i][j]=inf;
	}
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=n;i++){
		int len;cin>>len;
		while(len--){
			int x,y;cin>>x>>y;
			li[x].push_back({y,i});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<(int)li[i].size();j++){
			for(int k=0;k<j;k++){
				int x=li[i][j].ss;ll xx=li[i][j].ff;
				int y=li[i][k].ss;ll yy=li[i][k].ff;
				dis[x][y]=min(dis[x][y],xx+yy),dis[y][x]=min(dis[y][x],xx+yy);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++) dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]); 
		}
	}
	while(q--){
		int a,b;cin>>a>>b;
		ll ans=inf;
		for(pii aa:li[a]){
			for(pii bb:li[b]) ans=min(ans,aa.ff+bb.ff+dis[aa.ss][bb.ss]);
		}
		ans+=t0[a]+t0[b];
		cout<<ans<<"\n";
	}
	//cerr<<1.0*(clock()-st)/CLOCKS_PER_SEC<<"\n";
	return 0;
}