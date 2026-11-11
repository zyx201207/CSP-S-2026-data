#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll c,T,dp[5005][5005],a[5005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--){
		ll n,d,t=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i>1){
				if(a[i]-a[i-1]<=d){
					dp[i-1][i]=1;
					dp[i][i-1]=1; 
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j-i>=1&&j+i<=n){
					dp[j-i][j+i]+=dp[j-i][j]*dp[j][j+i];
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(dp[i][j]>1){
					t++;
				}
			}
		}
		cout<<t<<"\n";
	}
	return 0;
}
