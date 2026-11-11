#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,ans=-1e18,maxn=-1e18;
ll dp[5050][5050];
ll a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(a[i],maxn);
	}
	for(int i=1;i<=n;i++){
		dp[i][1]=a[i];
	}
	if(m==1){
		cout<<maxn;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j)ans=max(ans,a[i] & a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans & a[i];
		}
		cout<<ans;
		return 0;
	}
	if(maxn==1){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=2;j<=m;j++){
			for(int k=1;k<=n;k++){
				dp[i][j]=max(dp[k][j-1] & a[i],dp[i][j]);
			}
		}
	}
	cout<<dp[n][m];
	return 0;
} 
/*
4 2
3 15 12 12
*/
