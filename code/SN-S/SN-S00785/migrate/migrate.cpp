//SN-S00785
#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
long long x[1005],dis[1005][1005],ans=0,vis[505][505][505],vis1[505][505];
struct edge{
	int to,w;
};
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		memset(dis,0,sizeof(dis));
		memset(vis,0,sizeof(vis));
		memset(vis1,0,sizeof(vis1));
		ans=0;
		vector<edge> e[1005];
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				dis[i][j]=1e9;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[i]-x[j]<=d){
					e[i].push_back({j,x[j]-x[i]});
					dis[i][j]=min(dis[i][j],(long long)x[j]-x[i]);
				}
			}
		}
		for(int i=1;i<=n;i++){
			dis[i][i]=0;
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(dis[i][j]==dis[i][k]+dis[k][j] && i!=j && k!=i && k!=j && vis[i][k][j]==0){
						vis1[i][j]++;
						if(vis1[i][j]==2){
							ans++;
						}
					}
					dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
					vis[i][k][j]=1;
				}
			}
		}
		cout<<ans<<endl;
	} 
	return 0;
}
