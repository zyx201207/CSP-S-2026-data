#include<bits/stdc++.h>
using namespace std;
#define int long long 
int c,t,n,d,x[2000005],dis[5005][5005],tmp[5005][5005],cnt[5005][5005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)cnt[i][j]=0;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)dis[i][j]=1e18;
		}
		for(int i=1;i<=n;i++)dis[i][i]=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++)dis[i][j]=1;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]<=d)dis[i][j]=1;
			}
		}
		for(int k=1;k<=n;k++){
			for(int u=1;u<=k;u++){
				for(int v=k;v<=n;v++){
					if(dis[u][v]==1e18||dis[u][k]==1e18||dis[k][v]==1e18)continue;
					if(dis[u][v]>dis[u][k]+dis[k][v])dis[u][v]=dis[u][k]+dis[k][v];
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)tmp[i][j]=1e18;
		}
		for(int i=1;i<=n;i++)tmp[i][i]=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++)tmp[i][j]=1;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]<=d)tmp[i][j]=1;
			}
		}
		for(int k=1;k<=n;k++){
			for(int u=1;u<=k;u++){
				for(int v=k;v<=n;v++){
					if(tmp[u][v]==1e18||tmp[u][k]==1e18||tmp[k][v]==1e18)continue;
					if(tmp[u][v]>tmp[u][k]+tmp[k][v])tmp[u][v]=tmp[u][k]+tmp[k][v];
					if(tmp[u][v]==dis[u][v])cnt[u][v]++;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(cnt[i][j]==2){
					//cout<<i<<" "<<j<<endl;
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
