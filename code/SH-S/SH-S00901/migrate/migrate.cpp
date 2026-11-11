#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=5010;
int n,c,t,d;
int x[MAXN];
int dis[MAXN][MAXN];
int cnt[MAXN][MAXN];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		memset(dis,-1,sizeof(dis));
		memset(cnt,0,sizeof(cnt));
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]<=d) dis[i][j]=1;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=i+1;k<j;k++){
					if(dis[i][j]==dis[i][k]+dis[k][j]){
						cnt[i][j]++;
					}
					if((dis[i][j]>dis[i][k]+dis[k][j]||dis[i][j]==-1)&&x[k]-x[i]<=d&&x[j]-x[k]<=d){
						dis[i][j]=dis[i][k]+dis[k][j];
						cnt[i][j]=0;
					}
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(dis[i][j]==1) cnt[i][j]--;
				if(cnt[i][j]==1) {
					ans++; 
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
