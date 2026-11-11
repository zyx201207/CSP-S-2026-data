#include<bits/stdc++.h>
using namespace std;
long long sta[500005][22][2],c,n,m,d,q,w[500005];//w:地铁口到站厅   sta为第i个站厅连接的线路编号及时间 
long long dis[505][505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	cin>>c>>n>>m>>d>>q; 
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
//		cin>>w[i];
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		long long a,t;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			sta[a][++sta[a][0][0]][0]=i;
			sta[a][sta[a][0][0]][1]=t;
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j){
				dis[i][j]=1000000000000ll;
			}
		}
	}
	
	for(int i=1;i<=m;i++){
		for(int p=1;p<=sta[i][0][0];p++){
			for(int q=p+1;q<=sta[i][0][0];q++){
				int u=sta[i][p][0],v=sta[i][q][0];
				dis[u][v]=dis[v][u]=min(dis[u][v],sta[i][p][1]+sta[i][q][1]);
			}
		}
	}
	
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dis[i][k]+dis[k][j]<dis[i][j]){
					dis[i][j]=dis[i][k]+dis[k][j];
				}
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dis[i][j]<<" ";
//		}
//		cout<<'\n';
//	}

	while(q--){
		int st,en;
		cin>>st>>en;
		long long ans=10000000000000ll;
		for(int i=1;i<=sta[st][0][0];i++){
			for(int j=1;j<=sta[en][0][0];j++){
				ans=min(ans,w[st]+w[en]+sta[st][i][1]+sta[en][j][1]+dis[sta[st][i][0]][sta[en][j][0]]);
			}
		}
		printf("%lld\n",ans);
//		cout<<ans<<'\n';
	}
	return 0;
}
/*0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
