#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+5;
long long a[N],c[N];
int x,t,n;
long long d;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>x>>t;
	while(t--){
		cin>>n>>d;
		long long ans=0;
		vector<vector<long long> > cnt(n+1,vector<long long>(n+1,0));
		for(int i=1;i<=n;i++){
			cin>>a[i];
			c[i] = a[i]-a[i-1];
		}
		for(int x=1;x<=n;x++){
			vector<long long> dp(n+1,1e18+5);
			dp[x] = 0;
			for(int i=x;i<=n;i++){
				long long y=0;
				for(int j=i+1;y+c[j]<=d && j<=n;j++){
					y+=c[j];
					if(dp[j] == dp[i]+1){
						cnt[x][j]++;
					}
					else{
						dp[j] = min(dp[j],dp[i]+1);
						if(dp[j] == dp[i]+1){
							cnt[x][j]=1;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(cnt[i][j] == 2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
