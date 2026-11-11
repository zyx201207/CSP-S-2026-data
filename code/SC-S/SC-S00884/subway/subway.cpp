#include<iostream>
#include<algorithm>
using namespace std;
long long dis[505][505];
int c,n,m,d,q,w[500005][21],t[501][500005],cnt[500005],k[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i][0];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=1e18;
		}
		for(int j=1;j<=m;j++){
			t[i][j]=1e9+1;
		}
		
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x;
			cin>>x;
			cin>>t[i][x];
			w[x][++cnt[x]]=i;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=cnt[i];j++){
			for(int u=1;u<=cnt[i];u++){
				if(w[i][j]==w[i][u]){
					dis[w[i][j]][w[i][u]]=0;
				}
				dis[w[i][j]][w[i][u]]=min(1ll*(t[w[i][j]][i]+t[w[i][u]][i]),dis[w[i][j]][w[i][u]]);
			}
		}
	}
	int f=1;
	while(f){
		f=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					if(dis[i][k]+dis[k][j]<dis[i][j]){
						f=1;
						dis[i][j]=dis[i][k]+dis[k][j];
					}
				}
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		long long ans=1e18;
		for(int i=1;i<=cnt[x];i++){
			for(int j=1;j<=cnt[y];j++){
				ans=min(ans,t[w[x][i]][x]+t[w[y][j]][y]+dis[w[x][i]][w[y][j]]);
			}
		}
		cout<<ans+w[x][0]+w[y][0]<<endl;
	}
	return 0;
}