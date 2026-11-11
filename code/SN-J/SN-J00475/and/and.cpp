#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+10;
ll dp[maxn],a[maxn],n,m,ans,f;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
//	dp[1]=a[1];
//	ans=dp[1];
//	for(int i=2;i<=n;i++){	
//		dp[i]=max(a[i],dp[i-1]&a[i]);
//		ans=max(ans,dp[i]);	
//	}
	if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
	} 
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		} 		
	}else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
	}else if(m==3){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					ans=max(ans,a[i]&a[j]&a[k]);
				}	
			}
		} 		
	}else if(m==4){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						ans=max(ans,a[i]&a[j]&a[k]&a[l]);
					}
				}	
			}
		} 		
	}else if(m==5){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int z=l+1;z<=n;z++){
							ans=max(ans,a[i]&a[j]&a[k]&a[l]&a[z]);
						}
					}
				}	
			}
		} 			
	}else if(m==n-1){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		for(int i=1;i<=n;i++){
			ans=(ans,ans&a[i]);
		}			
	}else if(m==6){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int z=l+1;z<=n;z++){
							for(int y=z+1;y<=n;y++){
								ans=max(ans,a[i]&a[j]&a[k]&a[l]&a[z]&a[y]);
							}
							
						}
					}
				}	
			}
		} 		
	}else{
		dp[1]=a[1];
		ans=dp[1];
		for(int i=2;i<=n;i++){	
			dp[i]=max(a[i],dp[i-1]&a[i]);
			ans=max(ans,dp[i]);	
		}		
	}
	cout<<ans;
	return 0;
}

