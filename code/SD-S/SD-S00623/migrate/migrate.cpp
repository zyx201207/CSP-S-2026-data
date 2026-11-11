#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int c,t;
int n,d;
int a[2*1000000+5];
int G[5005][5005];
int g[5005][5005];
int cnt[5005][5005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}	
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				G[i][j]=g[i][j]=2147483647;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				else{
					if(a[j]-a[i]<=d){
						G[i][j]=1;
						g[i][j]=1;
					}
				}
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i!=k&&j!=k&&G[i][k]==1&&G[k][j]==1){
						if(g[i][k]+g[k][j]<g[i][j]){
							g[i][j]=g[i][k]+g[k][j];
							cnt[i][j]=1;
						}
						else if(g[i][k]+g[k][j]==g[i][j]){
							cnt[i][j]++;
						}
					}
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				else{
					if(cnt[i][j]==2){
						ans++;
					}
				}
			}
//			cout<<'\n'; 
		}
		cout<<ans<<'\n';
	}
	return 0;
}
