//SN-S00493
//程思阳
//西安市铁一中学 
#include <bits/stdc++.h>
#define int long long
#define pi pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=5e5+5,M=505,inf=1e18;
int ty,n,m,d,q,w[N],f[M][M];
vector<pair<int,int>> e[N];
inline void mn(int &x,int y){(x>y)&&(x=y);}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>ty>>m>>n>>d>>q;
	for(int i=1;i<=n;i++) cin>>w[i];
	for(int i=1,k;i<=m;i++){
		cin>>k;
		for(int j=1,a,t;j<=k;j++){
			cin>>a>>t;
			e[a].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++) for(int j=1;j<=m;j++) f[i][j]=(i!=j)*inf;
	for(int i=1;i<=n;i++){
		for(pi u:e[i]) for(pi v:e[i]){
			mn(f[u.fi][v.fi],u.se+v.se);
		}
	}
	for(int k=1;k<=m;k++) for(int i=1;i<=m;i++) for(int j=1;j<=m;j++) mn(f[i][j],f[i][k]+f[k][j]);
	for(int i=1,u,v;i<=q;i++){
		cin>>u>>v;
		int re=inf;
		for(pi uu:e[u]) for(pi vv:e[v]){
			mn(re,uu.se+vv.se+f[uu.fi][vv.fi]);
		}
		cout<<re+w[u]+w[v]<<endl;
	}
}
