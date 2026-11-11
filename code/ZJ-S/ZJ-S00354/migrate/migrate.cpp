#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t,n,a[5005];
ll d;
pair<int,int> dp[5005][5005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>t>>t;
	while(t--){
		cin>>n>>d;
		int sum = 0;
		for(int i = 1;i<=n;i++){
			cin>>a[i];
		}
		for(int i = 1;i<=n;i++){
			for(int j = i;j<=n;j++){
				dp[i][j] = {0,0};
			}
		}
		for(int i = 1;i<=n;i++){
			dp[i][i] = {0,1};
			for(int j = i+1;j<=n;j++){
				int min_n = INT_MAX;
				for(int k = j-1;k>=i;k--){
					if(a[j]-a[k]>d){
						break;
					}
					min_n = min(min_n,dp[i][k].first);
				}
				dp[i][j].first = min_n+1;
				for(int k = j-1;k>=i;k--){
					if(a[j]-a[k]>d){
						break;
					}
					if(dp[i][k].first==min_n){
						dp[i][j].second+=dp[i][k].second;
					}
				}
				if(dp[i][j].second==2) sum++;
			}
		}
		cout<<sum<<'\n';
	}
	return 0;
}
