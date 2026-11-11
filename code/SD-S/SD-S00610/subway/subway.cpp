#include<bits/stdc++.h>
using namespace std;
const int N=5E2+5;
const int M=1E4+5;
int w[M];
unordered_map<int,int> mp[N];
int dis[M][M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,p;
	cin>>c>>n>>m>>d>>p;
	memset(dis,0x3f3f,sizeof(dis));
	for (int i=1;i<=m;i++){
		cin>>w[i];
	}
	for (int i=1;i<=n;i++){
		int k;
		cin>>k;
		for (int j=1;j<=k;j++){
			int a,ti;
			cin>>a>>ti;
			mp[i][a]=ti;
		}
	}
	for (int u=1;u<=m;u++){
		for (int v=1;v<=m;v++){
		for (int i=1;i<=n;i++){
				for (int j=1;j<=n;j++){
					for (int k=1;k<=m;k++){
						if (mp[i].count(u)&&mp[i].count(k)&&mp[j].count(k)&&mp[j].count(v)){
							dis[u][v]=min(dis[u][v],mp[i][u]+mp[i][k]+mp[j][k]+mp[j][v]);
						}
					}
				}
				if (mp[i].count(u)&&mp[i].count(v)){
					dis[u][v]=min(dis[u][v],mp[i][u]+mp[i][v]);
				}
			}
		}
	}
	while (p--){
		int x,y;
		cin>>x>>y;
		int ans=INT_MAX;
		for (int i=1;i<=m;i++){
			ans=min(ans,dis[x][i]+dis[i][y]);
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
