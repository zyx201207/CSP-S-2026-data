#include<bits/stdc++.h>
using namespace std;
const int N=305;
int n;
long long d;
int c,T;
long long x[N];
int ans;
int dp[N][N];
int cnt[N][N];
bool vis[N][N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		ans=0;
		memset(cnt,0,sizeof(cnt));
		memset(dp,0x3f,sizeof(dp));
		memset(vis,0,sizeof(vis));
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			dp[i][i]=0;
			vis[i][i]=1;
			for(int j=i-1;j>=1;j--){
				if(x[i]-x[j]<=d){
					dp[i][j]=dp[j][i]=1;
					vis[i][j]=vis[j][i]=1;
					cnt[i][j]=cnt[j][i]=1;
				}else{
					break;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=i+1;k<j;k++){
					if(dp[i][j]>=dp[i][k]+dp[k][j]){
						if(dp[i][j]=dp[i][k]+dp[k][j]){
							cnt[i][j]+=(cnt[i][k]*cnt[k][j]);
							cnt[j][i]+=(cnt[i][k]*cnt[k][j]);
						}else{
							cnt[i][j]=cnt[j][i]=1;
						}
						dp[i][j]=dp[i][k]+dp[k][j];
						vis[i][j]=1;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(cnt[i][j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";	
	}
	return 0;
} 
