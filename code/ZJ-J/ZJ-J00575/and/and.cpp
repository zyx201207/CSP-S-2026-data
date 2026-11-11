#include<bits/stdc++.h>
using namespace std;
int a[200010][31],n,x,vis[200010],ans,dp[30]={1},m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=30;i++)
		dp[i]=dp[i-1]*2;
	for(int i=1;i<=n;i++){
		cin>>x;
		for(int j=0;j<=30;j++)
			a[i][j]=x%2,x/=2;
	}
	for(int i=30;i>=0;i--){
		int ge=0;
		for(int j=1;j<=n;j++){
			if(vis[j]==1)
				continue;
			if(a[j][i]==1)
				ge++;
		}
		if(ge>=m){
			ans+=dp[i];
			for(int j=1;j<=n;j++){
				if(a[j][i]==0)
					vis[j]=1;
			}
		}
	}
	cout<<ans;
	return 0;
}