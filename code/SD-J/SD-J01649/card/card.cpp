#include<bits/stdc++.h>
using namespace std;
bool dp[50010][30010];
int last[300010],ans,a[500010],m,n;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}dp[n][a[n]]=1,last[a[n]]=n;
	for(int i=n-1;i>=1;i--){
		if(last[a[i]]==0){
			last[a[i]]=i;
			for(int j=1;j<=m;j++){
				dp[i][j]=dp[i+1][j];
			}dp[i][a[i]]=1;
		}else{
			for(int j=1;j<=m;j++){
				dp[i][j]=dp[last[a[i]]][j];
			}dp[i][a[i]]=1;
		}
	}for(int i=1;i<=m;i++){
		ans=0;
		for(int j=1;j<=n;j++){
			ans+=dp[j][i];
		}cout<<ans<<" ";
	}
	return 0;
}
