#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,M=5e5+5;
int c,n,m,d,q,w[M],dig[N][M],f[N][N];
struct ed{
	int cnt,ww;
};
vector<ed>g[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k,a,t;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			dig[i][a]=t;
			g[a].push_back((ed){i,t});
		}
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++)f[i][i]=0;
	for(int i=1;i<=m;i++){
		int siz=g[i].size();
		for(int j=0;j<siz-1;j++){
			for(int k=j+1;k<siz;k++){
				int x=g[i][j].cnt;
				int y=g[i][k].cnt;
				f[x][y]=min(f[x][y],g[i][j].ww+g[i][k].ww);
				f[y][x]=f[x][y];
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
		int x,y;
		cin>>x>>y;
		int ans=1e18;
		int sx=g[x].size();
		int sy=g[y].size();
		for(int i=0;i<sx;i++){
			for(int j=0;j<sy;j++){
				ans=min(ans,f[g[x][i].cnt][g[y][j].cnt]+w[x]+w[y]+dig[g[x][i].cnt][x]+dig[g[y][j].cnt][y]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
			
