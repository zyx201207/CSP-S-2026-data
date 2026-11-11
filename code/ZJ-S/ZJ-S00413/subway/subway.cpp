#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
typedef pair<int,int> pii;
const int N=5e5+114,M=522;
int c,n,m,d,q,w[N];
vector<pii> e[N];
int f[M][M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,a,t;j<=k;j++){
			cin>>a>>t;
			e[a].push_back({i,t});
		}
	}
	memset(f,0x1f,sizeof f);
	for(int i=1;i<=m;i++){
		for(pii p1:e[i]){
			int u=p1.fi,w1=p1.se;
			for(pii p2:e[i]){
				int v=p2.fi,w2=p2.se;
				int w=w1+w2;
				if(u==v) w=0;
				f[u][v]=f[v][u]=min(f[u][v],w);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
		}
	}
	while(q--){
		int x,y;cin>>x>>y;
		int ans=1e18;
		for(pii p1:e[x]){
			for(pii p2:e[y])
				ans=min(ans,p1.se+p2.se+f[p1.fi][p2.fi]);
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
/*
I'm Mingzhou13(681941), I love wxq in FH high school 4ever!
She's such a cute and charming girl.
*/
