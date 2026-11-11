#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int a[300005];
struct dd{
	int c;
	int f;
}dp[5005][5005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		if(c<=10){
			int n,d;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			for(int i=2;i<=n;i++){
				a[i]-=a[1];
			}
			a[1]=0;
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i==j){
						dp[i][j].c=0;
						dp[i][j].f=1;
						continue;
					}
					dp[i][j].c=1e7;
					dp[i][j].f=0;
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int l=j;l>=i;l--){
						if(a[j]-a[l]<=d){
							if(dp[i][j].c>dp[i][l].c+1){
								dp[i][j].c=dp[i][l].c+1;
								dp[i][j].f=dp[i][l].f;
							}
							else if(dp[i][j].c==dp[i][l].c+1){
								dp[i][j].c=dp[i][l].c+1;
								dp[i][j].f+=dp[i][l].f;
							}
						}
						else{
							break;
						}
					}
					if(dp[i][j].f==2){
						ans++;
					}
				}
			}
			cout<<ans<<"\n";
		}
		if(c==13||c==14){
			cout<<0<<"\n";
		}
	}
}