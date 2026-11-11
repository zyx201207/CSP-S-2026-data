#include<bits/stdc++.h>
using namespace std;
const int N=505,M=1e5+5;
int n,m;
int w[M],k[N];
int a[N][M],t[N][M];
int g[N][N],dist[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	int c,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x,tim;
			cin>>x>>tim;
			a[i][x]=1;
			t[i][x]=tim;
		} 
	}
	for(int l=1;l<=n;l++){
		for(int i=1;i<=m;i++){
			for(int j=i+1;j<=m;j++){
				if(a[l][i]&&a[l][j]){
					if(!g[i][j])g[i][j]=t[l][i]+t[l][j],g[j][i]=t[l][i]+t[l][j];
					else g[i][j]=min(t[l][i]+t[l][j],g[i][j]),g[j][i]=min(t[l][i]+t[l][j],g[i][j]);
				}
			} 
		}
	}
	memset(dist,0x3f,sizeof dist); 
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			if(g[i][j])dist[i][j]=g[i][j];
	for(int kk=1;kk<=m;kk++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
					dist[i][j]=min(dist[i][j],dist[i][kk]+dist[kk][j]);
			}
		}
	}
	while(q--){
		int x,y;cin>>x>>y;
		int ans=w[x]+w[y]+dist[x][y];
		cout<<ans<<endl;
	}
	return 0;
}
