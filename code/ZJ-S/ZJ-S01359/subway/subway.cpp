#include<bits/stdc++.h>
using namespace std;
#define int long long 
int c,n,m,d,q;
const int nn=5e5+5,mm=505;
int w[nn];
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
vector<pii> e[nn];
int dis[mm][mm];
const int inf=1e18;
void chkmn(int &u,int v){
	u=min(u,v);
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=0;i<mm;i++){
		for(int j=0;j<mm;j++){
			if(i!=j) dis[i][j]=inf;
			else dis[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		while(k--){
			int a,t;
			cin>>a>>t;
			e[a].pb({t,i});
		}
	}
	for(int i=1;i<=m;i++){
		for(pii o:e[i]){
			for(pii p:e[i]){
				chkmn(dis[o.se][p.se],o.fi+p.fi);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int res=inf;
		for(pii o:e[x]){
			for(pii p:e[y]){
				res=min(res,dis[o.se][p.se]+o.fi+p.fi);
			}
		}
		res+=w[x]+w[y];
		cout<<res<<"\n";
	}
	return 0;
}