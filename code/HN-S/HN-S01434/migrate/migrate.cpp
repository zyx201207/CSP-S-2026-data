#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int x,y;
};
int c,t,n,d,a[1001],cnt;
node dp[1001][1001];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>c>>t;
	while(t--){
		cnt=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i-1;j>=1;j--){
				if(a[i]-a[j]<=d){
					dp[j][i].x=1;
					dp[j][i].y=1;
				}
				else{
					dp[j][i].x=0x3f;
					dp[j][i].y=0;
				}
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=k-1;i>=1;i--){
				for(int j=k+1;j<=n;j++){
					if(dp[i][k].x+dp[k][j].x<dp[i][j].x){
						dp[i][j].x=dp[i][k].x+dp[k][j].x;
						dp[i][j].y=1;
					}
					else if(dp[i][k].x+dp[k][j].x==dp[i][j].x){
						dp[i][j].y++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(dp[i][j].y==2){
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
    return 0;
}

