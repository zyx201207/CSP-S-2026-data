#include<bits/stdc++.h>
using namespace std;
int a[200020],dp[200020],n,m,maxxn=INT_MIN,vis[200020];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i]=a[i];
		maxxn=max(a[i],maxxn);
	}
	if(m==1){
		cout<<maxxn<<endl;
		return 0;
	}
	if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans=(ans&a[i]);
		}
		cout<<ans<<endl;
		return 0;
	}

	//前j个数，选i个， 
	for(int i=2;i<=m;i++){
		for(int j=n;j>=1;j--){
			if(!vis[j]){
			
				dp[j]=max(dp[j],(dp[j-1]&a[j]));
				vis[j]=1;
				
			}
		}
	}
	
	cout<<dp[n];
	return 0;
} 
