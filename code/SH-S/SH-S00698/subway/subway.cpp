#include<bits/stdc++.h>
#define PII pair<int,int>
#define fi first
#define se second
#define int long long
using namespace std;
const int maxn=503,maxm=5e5+3;
vector<PII> ln[maxn+maxm];
int dis[maxn][maxn],len[maxm],w[maxm];
PII which[maxm][23];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,-1,sizeof(dis));
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int tmp,lw;
			cin>>tmp>>lw;
			which[tmp][++len[tmp]]={i,lw};
			ln[i].push_back({n+tmp,lw});
			ln[n+tmp].push_back({i,lw});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<ln[i].size();j++){
			PII p=ln[i][j];
			for(int k=0;k<ln[p.fi].size();k++){
				PII p2=ln[p.fi][k];
				if(dis[i][p2.fi]==-1 || p.se+p2.se<dis[i][p2.fi]){
					dis[i][p2.fi]=p.se+p2.se;
				}
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dis[i][k]==-1 || dis[k][j]==-1)continue;
				if(dis[i][j]==-1)dis[i][j]=dis[i][k]+dis[k][j];
				else dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int x,y,ans=4e18;
		cin>>x>>y;
		for(int i=1;i<=len[x];i++){
			for(int j=1;j<=len[y];j++){
				if(dis[which[x][i].fi][which[y][j].fi]==-1)continue;
				ans=min(ans,dis[which[x][i].fi][which[y][j].fi]+w[x]+w[y]+which[x][i].se+which[y][j].se);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
