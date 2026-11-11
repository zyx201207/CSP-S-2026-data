#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

const int N=2026;
int c,T;
int x,y;
int w[N],k;
int n,m,d,Q;
int f[N][N];

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	memset(f,0x3f3f3f3f,sizeof(f));
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;int u=i+m;
		for(int j=1;j<=k;j++){
			int v,w;
			cin>>v>>w;
			f[u][v]=f[v][u]=w;			
		}
	}
	
	for(int i=1;i<=n+m;i++)f[i][i]=0;
	for(int k=1;k<=n+m;k++)
		for(int i=1;i<=n+m;i++)
			for(int j=1;j<=n+m;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(Q--){
		int x,y;
		cin>>x>>y;
		cout<<f[x][y]+w[x]+w[y]<<'\n';
	}
	
	return 0;
}
