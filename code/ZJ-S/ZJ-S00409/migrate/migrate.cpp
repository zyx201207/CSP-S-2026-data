#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5010;
vector<int>a;
int dp[N][N],dis[N][N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		a.clear();
		for(int i=1,x;i<=n;i++){
			cin>>x;
			a.push_back(x);
		}
		int ans=0;
		for(int i=1;i<n;i++){
			for(int j=0;j+i<n;j++){
				//dp[i][j+i]
				int ad=upper_bound(a.begin(),a.end(),a[j]+d)-a.begin()-1;
				if(ad==j){
					dp[j][j+i]=0;
					dis[j][j+i]=2e9;
					continue;
				}
				if(ad>=j+i){
					dis[j][j+i]=1;
					dp[j][j+i]=1;
					continue;
				}
				dis[j][j+i]=dis[ad][j+i]+1;
				if(dp[ad][j+i]==1){	
					if(ad-2>j&&dis[ad-2][j+i]+1==dis[j][j+i]){
						dp[j][j+i]=0;
					}else if(ad-1>j&&dis[ad-1][j+i]+1==dis[j][j+i]){
						dp[j][j+i]=2;
						ans++;
					}else{
						dp[j][j+i]=1;
					}
				}else if(dp[ad][j+i]==2){
					if(ad-1>j&&dis[ad-1][j+i]+1==dis[j][j+i]){
						dp[j][j+i]=0;
					}else{
						dp[j][j+i]=2;
						ans++;
					}
				}else{
					dp[j][j+i]=0;
				}
				//cout<<j<<" "<<j+i<<" "<<ad<<" "<<dp[j][j+i]<<"\n";
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}