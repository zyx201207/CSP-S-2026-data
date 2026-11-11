#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5,M=505;
int C,n,m,d,q,W[N];
vector<int> v[N],w[N];
int g[M][M];
void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(i==k) continue;
			for(int j=1;j<=n;j++){
				if(j==k||j==i) continue;
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>W[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;cin>>x>>y;
			v[x].push_back(i),w[x].push_back(y);
		}
	}
	memset(g,0x3f,sizeof g);
	for(int i=1;i<=m;i++){
		for(int j=0;j<v[i].size();j++){
			for(int k=0;k<j;k++){
				int x=v[i][j],y=v[i][k];
				g[x][y]=g[y][x]=min(g[x][y],w[i][j]+w[i][k]);
			}
		}
	}
	for(int i=1;i<=n;i++) g[i][i]=0;
	floyd();
	while(q--){
		int x,y;cin>>x>>y;
		int z=2e18;
		for(int j=0;j<v[x].size();j++){
			for(int k=0;k<v[y].size();k++){
				int x1=v[x][j],x2=v[y][k];
				z=min(z,g[x1][x2]+w[x][j]+w[y][k]);
				if(z==0) break;
			}
			if(z==0) break;
		}
		cout<<W[x]+W[y]+z<<'\n';
	}
	return 0;
}