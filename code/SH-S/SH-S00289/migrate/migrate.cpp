#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d;
long long lct[2000005];
long long side[1005][1005];
long long dis[1005][1005];
int g[1005][1005],ans=0;
void F(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=side[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(abs(lct[k]-lct[i])<=d&&abs(lct[j]-lct[k])<=d&&i!=j&&i!=k&&j!=k){
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}
	}
	return;
}
void F2(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			g[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(dis[i][k]+dis[k][j]==dis[i][j]&&i!=k&&j!=k){
					g[i][j]++;
					//if(i==1&&j==4) cout<<dis[i][k]<<' '<<dis[k][j]<<endl;
				}
			}
		}
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>lct[i];
		if(c<=6){
			ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(lct[j]-lct[i]<=d) side[i][j]=side[j][i]=1;
					else side[i][j]=side[j][i]=0x3f3f3f3f;
				}
			}
			F();
			F2();
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(g[i][j]==2){
						ans++;
						//cout<<i<<" "<<j<<endl;
					}
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
