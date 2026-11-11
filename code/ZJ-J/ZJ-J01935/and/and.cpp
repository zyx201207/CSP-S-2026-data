#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005],ans,ans1,ans2,ans3;
bool vis[2005];
void dfs(int x, int y){
	if(y==m){
		if(ans<=x){
			ans=x;	
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(i==x){
			continue;
		}
		if(!vis[i]){
			vis[i]=true;
			dfs(x&a[i],y+1);
			vis[i]=false;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans2=max(ans2,a[i]);
		ans1=ans1&a[i];
	}
	if(m==1){
		cout<<ans2;
	}
	else if(m==n){
		cout<<ans1;
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				if(i==j){
					continue;
				}
				else{
					ans3=max(ans3,a[i]&a[j]);
				}
			}
		}
		cout<<ans3;
	}
	else if(m!=1&&m!=n&&m!=2){
		dfs(2147483647,0);
		cout<<ans;
	}
	/*for(int i=1;i<=n;i++){
		for(int j=i;j>=1;j--){
			if(j==1){
				dp[i][j]=max(dp[i-1][j],a[i]);
			}
			else{
				dp[i][j]=max(dp[i][j],dp[i-1][j]);
				dp[i][j]=max(dp[i][j],dp[i-1][j-1]&a[i]);
			}	
			ans=max(ans,dp[i][m]);
		}
	}
	cout<<ans;*/
	return 0;
}