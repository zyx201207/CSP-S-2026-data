#include<bits/stdc++.h>
using namespace std;
int n,m;
int arr[200005],dp[200005]; 
int ans;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	int mx=-1;
	for(int i=1;i<=n;i++){
		cin >> arr[i];
		mx=max(mx,arr[i]);
	}
	if(n==m){
		cout << mx;
		return 0;
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,arr[i]);
		}
		cout << ans;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,arr[i]&arr[j]);
			}
		}
		cout << ans;
		return 0;
	}
	dp[0]=2147483647;
	for(int i=1;i<=n;i++){
		for(int z=m;z>=1;z--){
			dp[z]=max(dp[z],dp[z-1]&arr[i]);
		}
	}
	cout << dp[m];
	
	return 0;
} 
