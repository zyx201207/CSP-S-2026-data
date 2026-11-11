#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=305;
int c,t,n,dp[N][N][N],ans;
ll x[N],d;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		int n,d;
		scanf("%d%d",&n,&d);ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					dp[i][j][k]=0;
				}
			}
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&x[i]);
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]<=d){
					dp[i][j][1]=1;
				}
			}
		}
		for(int i=1;i<=n-3;i++){
			for(int j=i+2;j<=n;j++){
				
				for(int k=2;k<=j-i;k++){
					for(int mid=i+1;mid<j;mid++){
						if(x[j]-x[mid]<=d){
							dp[i][j][k]+=dp[i][mid][k-1];
						}
						
					}
				}
				for(int k=1;k<=j-i;k++){
					if(dp[i][j][k]){
						if(dp[i][j][k]==2) ans++;
						break;
					}
				}
			}
					
		}
		printf("%d\n",ans);
	}
	return 0;
}
