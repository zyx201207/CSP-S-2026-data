#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e3+9,M=5e5+9;
int dp[N][N];
int cnt[N][N];
int n,m;
int a[M];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int cctv;
	cin>>cctv;
	int T;
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(n>5e3){
			cout<<0<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]=1e9;
				cnt[i][j]=0;
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			dp[i][i]=0;
			cnt[i][i]=1;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int sum=0;
				for(int k=j-1;k>=i;k--){
					sum+=a[k+1]-a[k];
					if(sum>m)break;
					if(dp[i][j]>1+dp[i][k]){
						dp[i][j]=dp[i][k]+1;
						cnt[i][j]=cnt[i][k];
					}else if(dp[i][j]==1+dp[i][k]){
						cnt[i][j]+=cnt[i][k];
					}
				}
//				cout<<i<<' '<<j<<' '<<dp[i][j]<<' '<<cnt[i][j]<<'\n';
				if(cnt[i][j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
