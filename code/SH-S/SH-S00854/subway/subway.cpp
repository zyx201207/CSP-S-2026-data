#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,M=500050;
int c,n,m,q,d[M][22],f[N][N],w[M];
unordered_map<int,int>t[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>n>>m>>q>>q;
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++)f[i][i]=0;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){int k;cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;cin>>x>>y;
			t[i][x]=y;d[x][++d[x][0]]=i;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=d[i][0];j++){
			for(int k=1;k<=d[i][0];k++){
				int u=d[i][j],v=d[i][k];
				f[u][v]=min(f[u][v],t[u][i]+t[v][i]);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j||i==k||j==k)continue;
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--){int s=f[0][0];
		int x,y;cin>>x>>y;
		for(int j=1;j<=d[x][0];j++){
			for(int k=1;k<=d[y][0];k++){
				int u=d[x][j],v=d[y][k];
				s=min(s,f[u][v]+t[u][x]+t[v][y]);
			}
		}cout<<s+w[x]+w[y]<<'\n';
	}
	return 0;
} 
