#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],flag=1,dp[5005],ans[5005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+1+n);
	for(int i=1;i<=n;i++){
		if(a[i]!=b[i]){
			flag=0;
		}
	}
	if(flag==1){
	
		for(int i=2;i<=n;i++){
			if(a[i]!=a[i-1]){
				cout<<i-1<<" ";
			}
		}
		cout<<n;
	}
	else{
		for(int i=1;i<=n;i++){
			memset(dp,0,sizeof(dp));
			for(int j=i;j<=n;j++){
				dp[a[j]]=1;
				for(int k=j-1;k>=i;k--){
					if(a[k]==a[j]){
						for(int l=k+1;l<=j-1;l++){
							dp[a[l]]=0;
							dp[a[j]]=1;
						}
					}
				}

			}
			for(int k=1;k<=m;k++){
				if(dp[k]==1){
					ans[k]++;
				}
			}
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
	}
	
	return 0;
}