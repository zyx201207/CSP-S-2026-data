#include<bits/stdc++.h>
using namespace std;
long long n,d,a[5005];
long long dp[5005][5005],cnt[5005][5005];
long long ans=0;
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	memset(dp,0x3f3f3f,sizeof dp);
	for(int i=1;i<=n;++i){
		dp[i][i]=0;
	}
	for(int len=1;len<=n;++len){
		for(int i=1;i+len-1<=n;++i){
			int j=i+len-1;
			if(a[j]-a[i]<=d){
				dp[i][j]=1;
				continue;
			}
			int num=1;
			for(int k=i;k<=j;++k){
				if(dp[i][k]+dp[k][j]==dp[i][j]){
					num++;
				}else{
					if(dp[i][k]+dp[k][j]<dp[i][j]){
						dp[i][j]=dp[i][k]+dp[k][j];
						num=1;
					}
				}
			}
			if(num==2)++ans;
		}
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c;
	cin>>c;
	int T;
	cin>>T;
	while(T--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;++i){
			cin>>a[i];
		}
		memset(dp,0x3f3f3f,sizeof dp);
		for(int i=1;i<=n;++i){
			dp[i][i]=0;
		}
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				if(a[j]-a[i]<=d){
					dp[i][j]=1;
				}
			}
		}
		for(int len=2;len<=n;++len){
			for(int i=1;i+len-1<=n;++i){
				int j=i+len-1;
				int num=1;
				for(int k=i+1;k<j;++k){
					if(dp[i][k]+dp[k][j]==dp[i][j]){
						num+=cnt[i][k]*cnt[k][j];
					}else{
						if(dp[i][k]+dp[k][j]<dp[i][j]){
							dp[i][j]=dp[i][k]+dp[k][j];
							num=cnt[i][k]*cnt[k][j];
						}
					}
				}
				if(num==2)++ans;
				cnt[i][j]=num;
			}
		}
		cout<<ans<<'\n';
	}
}