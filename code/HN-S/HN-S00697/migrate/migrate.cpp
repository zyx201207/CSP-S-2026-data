#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e3+3;
const ll INF = 1e18;
ll n,m;
ll a[N];
int dp[N][N];
int c,t;
ll maxd[N];
int vis[N][N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c>>t;
	while(t--){
		int n;
		ll d;
		cin>>n>>d;
		if(n<=5000){
			memset(dp,0x3f3f,sizeof(dp));
			memset(vis,0,sizeof(vis));
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			//cout<<"\n";
			for(int i=1;i<=n;i++){
				ll cnt=i+1;
				while(a[cnt]-a[i]<=d){
					if(cnt>n) break;
					//cout<<cnt<<" "<<i<<" "<<a[cnt]-a[i]<<"\n";
					maxd[i]=cnt;
					dp[i][cnt]=1;
					//cout<<i<<" "<<cnt<<"\n";
					cnt++;
				}
			}
//			for(int i=1;i<=n;i++){
//				cout<<maxd[i]<<" ";
//			}
		//	cout<<"\n";
			for(int i=1;i<=n;i++){
				if(maxd[i]==0) continue;
				for(int j=maxd[i];j<=n;j++){
					for(int k=i+1;k<j;k++){
						if(dp[i][k]+dp[k][j]<dp[i][j]) {
							vis[i][j]=1;
							dp[i][j]=dp[i][k]+dp[k+1][j];
						//	cout<<i<<" "<<j<<" "<<dp[i][j]<<"\n"; 
						}
						else if(dp[i][k]+dp[k][j]==dp[i][j]) {
							vis[i][j]++;
							//cout<<i<<" "<<j<<" "<<vis[i][j]<<" \n";
						}
					}
				}
			}
			//cout<<dp[2][5]<<"\n";
			ll ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++){
					//cout<<i<<" "<<j<<" "<<dp[i][j]<<"\n";
					if(vis[i][j]==2) {
						//cout<<i<<" "<<j<<" "<<vis[i][j]<<"\n";
						//cout<<1;
						ans++;
					}
				}
			}
			cout<<ans<<"\n";
		}
		else cout<<0<<"\n";
	}
	return 0;
}
