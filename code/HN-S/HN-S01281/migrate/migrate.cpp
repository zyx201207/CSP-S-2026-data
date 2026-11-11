#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5005;

int n,d;
int a[MAXN];
int dp[MAXN][MAXN],dp2[MAXN][MAXN];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	
	int c,t;
	cin>>c>>t;
	while(t--){
		if(c == 11 || c == 12){
			cin>>n>>d;
			for(int i=0;i<n;i++){
				cin>>a[i];
			}
			int p = a[1] - a[0];
			if(p * 2 <= d){
				cout<<n-2<<"\n";
			}
			else cout<<0<<"\n";
		}
		int ans = 0;
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>a[i];
			if(i > 0 && a[i] - a[i-1] <= d){
				dp[i-1][i] = 1;
			}
		}
		for(int i=0;i<n;i++){
			for(int j=i+2;j<n;j++){
				dp[i][j] = INT_MAX;
				for(int k=i+1;k<j;k++){
					if(a[k] - a[i] <= d && a[j] - a[k] <= d){
						dp[i][j] = min(dp[i][k] + dp[k][j],dp[i][j]);
					}
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=i+2;j<n;j++){
				for(int k=i+1;k<j;k++){
					if(dp[i][k] + dp[k][j] == dp[i][j]){
						dp2[i][j]++;
					}
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(dp2[i][j] == 2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
