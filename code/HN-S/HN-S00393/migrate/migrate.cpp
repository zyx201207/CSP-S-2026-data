#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e6+7;
const int MAXn=5e3+7;
const long long INF=1e18;
int n;
int c,t;
long long d;
long long x[MAXN];
long long dis[MAXn][MAXn];
long long cnt[MAXn][MAXn];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	//ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		long long ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cnt[i][j]=0;
				dis[i][j]=INF;
				if(x[j]-x[i]<=d){
					dis[i][j]=1;
				}				
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
					if(dis[i][j]==2){
						if(dis[i][j]==dis[i][k]+dis[k][j]){
							cnt[i][j]++;
						}	
					}					
				} 
			}			
		}		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(cnt[i][j]==2){
					ans++; 
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
