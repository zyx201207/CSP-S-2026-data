#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,a[2000005];
struct node{
	int sum,ci;
}dp[5005][5005];
void solve(){
	int f=1,ff=0,ans=0;
	memset(dp,0,sizeof(dp));
	memset(a,0,sizeof(a));
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ff=a[2]-a[1];
	for(int i=3;i<n;i++){
		if(a[i]-a[i-1]!=ff){
			f=0;
			break;
		}
	}
	if(f){
		if(d<ff){
			cout<<0<<endl;
			return;
		}
		if(d-(3*ff%d)>=ff&&d-(3*ff%d)<2*ff){
			cout<<n-3<<endl;
		}else{
			cout<<0<<endl;
		}
	}else{
		for(int i=2;i<=n;i++){
			if(a[i]-a[i-1]<=d){
				dp[i-1][i].sum=1;
				dp[i-1][i].ci=1;
			}else{
				dp[i-1][i].sum=1e18;
				dp[i-1][i].ci=0;
			}
		}
		for(int len=2;len<=n;len++){
			for(int i=1;i+len-1<=n;i++){
				int j=i+len-1;
				dp[i][j].sum=1e18;
				if(a[j]-a[i]<=d){
					dp[i][j].sum=1;
					dp[i][j].ci=1;
				}else{
					for(int mid=i+1;mid<j;mid++){
						if(dp[i][mid].sum!=1e18&&dp[mid][j].sum!=1e18){
							if(dp[i][j].sum>dp[i][mid].sum+dp[mid][j].sum){
								dp[i][j].sum=dp[i][mid].sum+dp[mid][j].sum;
								dp[i][j].ci=dp[i][mid].ci*dp[mid][j].ci;
							}else if(dp[i][j].sum==dp[i][mid].sum+dp[mid][j].sum){
								dp[i][j].ci+=dp[i][mid].ci*dp[mid][j].ci;
							}
						}
					}
				}
				
			}
		}
		for(int i=1;i<=n-3;i++){
			for(int j=i+3;j<=n;j++){
				if(dp[i][j].ci==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
