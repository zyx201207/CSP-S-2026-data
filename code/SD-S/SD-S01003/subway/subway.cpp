#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
int b[500100];
int f[1010][1010];
int c,n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n+m;i++)f[i][i]=0;
	for(int i=1;i<=m;i++)cin>>b[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		while(k--){
			int v,w;
			cin>>v>>w;
			f[m+i][v]=w;
			f[v][m+i]=w;
		}
	}
	for(int k=1;k<=n+m;k++){
		for(int i=1;i<=n+m;i++){
			for(int j=1;j<=n+m;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		cout<<b[u]+f[u][v]+b[v]<<'\n';
	}
	return 0;
}
