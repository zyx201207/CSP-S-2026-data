#include<bits/stdc++.h>
using namespace std;
#define int long long

int islands[2000005];

int dp[5005][5005],cnt[5005][5005],canleft[5005],canright[5005];

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>islands[i];
		if(c<=10){
			memset(dp,0,sizeof(dp));
			memset(cnt,0,sizeof(cnt));
			memset(canleft,0,sizeof(canleft));
			memset(canright,0,sizeof(canright));
			int ans=0;
			for(int i=1;i<n;i++){
				if(islands[i+1]-islands[i]<=d)dp[i][i+1]=1;
				else{
					dp[i][i+1]=-1;
				}
//				cout<<dp[i][i+1]<<" ";
				cout<<cnt[i][i+1]<<" ";
			}
			cout<<endl;
			for(int k=2;k<n;k++){
				for(int i=1;i+k<=n;i++){
					int j=i+k;
					dp[i][j]=-1;
					if(islands[j]-islands[i]<=d){
						dp[i][j]=1;
					}else{
						for(int m=i+1;m<i+k;m++){
							if(dp[i][m]==-1 || dp[m][j]==-1){
								continue;
							}
							if(dp[i][j]>dp[i][m]+dp[m][j] || dp[i][j]==-1){
								dp[i][j]=dp[i][m]+dp[m][j];
								cnt[i][j]=1;
							}else if(dp[i][j]==dp[i][m]+dp[m][j]){
								cnt[i][j]++;
								if(cnt[i][j]==2)ans++;
								if(cnt[i][j]==3)ans--;
							}
						}
					}
//					cout<<dp[i][j]<<" ";
					cout<<cnt[i][i+1]<<" ";
//					cout<<ans<<" ";
				}
				cout<<endl;
			}
			cout<<ans<<endl;
		}else if(c==11 || c==12){
			if(n<4){
				cout<<0<<endl;
				continue;
			}
			if(islands[3]-islands[1]<=d && islands[4]-islands[1]>d){
				cout<<n-3<<endl;
			}else{
				cout<<0<<endl;
			}
		}else{
			
		}
	}
	return 0;
}
