#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
int c,T,n,d;
int x[N],dist[N],dp[N][N],vis[N][N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]<=d){
					vis[i][j]=1;
					continue;
				}
				for(int k=i+1;k<j;k++){
					if(vis[i][k]&&vis[k][j]) dp[i][j]++;
				}
				if(dp[i][j]==2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
